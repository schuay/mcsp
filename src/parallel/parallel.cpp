#include "parallel.h"

#include "pheet/pheet.h"

using namespace graph;

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

    return nullptr;
}

template class Parallel < pheet::PheetEnv < pheet::BStrategyScheduler,
         pheet::SystemModel,
         pheet::Primitives,
         pheet::DataStructures,
         pheet::ConcurrentDataStructures >>;

}
