#include "parallel.h"

#include "locking_vector.h"
#include "pareto/naive_linked_queue.h"
#include "pheet/pheet.h"
#include "sp/path.h"

using namespace graph;
using namespace pareto;
using namespace sp;

/** The maximum number of optimal elements processed at once during one iteration. */
#define NELEMS (512)

namespace
{
void
generate_candidates(const PathPtr from,
                    parallel::LockingVector<PathPtr> *candidates)
{
    const Node *head = from->head();
    for (auto & e : head->out_edges()) {
        PathPtr to(from->step(e));
        candidates->locked_push_back(to);
    }
}

} /* namespace */

namespace parallel
{

template <class Pheet>
Parallel<Pheet>::
Parallel(const Graph *g,
         const Node *start)
    : m_graph(g), m_start(start)
{
}

template <class Pheet>
sp::ShortestPaths *
Parallel<Pheet>::
shortest_paths()
{
    /* High level pseudo-code:
     *
     * L: The set of globally Pareto optimal elements in Q.
     * Q: Set of locally Pareto optimal (node, label) pairs.
     *
     * L[v] := {} for all v <- V
     * L[start] := { 0^d }
     * ParetoQueue Q = {(s, 0^d)}
     * while Q != {} {
     *      remove any Pareto optimal subset L from Q
     *      scan the labels in L
     *      insert new locally nondominated labels (v, l) into Q
     *          and remove old locally dominated labels
     *
     * Generic phases:
     *
     * 1. Pareto queue
     * 2. Generating candidates
     * 3. Grouping candidates
     * 4. Computing Pareto optima among candidates
     * 5. Merging new and old labels
     * 6. Bulk update of Q
     */

    ShortestPaths *sp = new ShortestPaths;

    /* TODO: The NaiveLinkedQueue is neither parallel nor efficient. */
    NaiveLinkedQueue m_queue;

    PathPtr init(new Path(m_start));
    m_queue.insert(init);

    while (!m_queue.empty()) {
        /* 1. Pareto queue. */
        std::vector<PathPtr> optima = m_queue.first(NELEMS);
        LockingVector<PathPtr> candidates;

        /* TODO: How to avoid the sequential bottleneck of distributing work
         * and spawning the tasks? */

        {
            typename Pheet::Finish f;
            for (auto ptr : optima) {
                /* 2. Generating candidates. */
                Pheet::spawn(::generate_candidates, ptr, &candidates);
            }
        }
    }

    return sp;
}

template class Parallel < pheet::PheetEnv < pheet::BStrategyScheduler,
         pheet::SystemModel,
         pheet::Primitives,
         pheet::DataStructures,
         pheet::ConcurrentDataStructures >>;

}
