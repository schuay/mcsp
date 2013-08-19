#include "sequential.h"

using namespace graph;
using namespace sp;

Sequential::
Sequential(const Graph *graph,
           const Node *start)
    : graph(graph), start(start)
{
}

ShortestPaths *
Sequential::
shortest_paths()
{
    /* 1. n = first node in queue.
     * 2. expand all edges from node, update any in queue
     * 3. repeat.
     */

    ShortestPaths *sp = new ShortestPaths();

    Path *init = new Path(start);
    m_queue.insert(init);

    while (!m_queue.empty()) {
        auto it = m_queue.begin();
        Path *path = *it;
        m_queue.erase(it);

        /* h = path.head
         * for all outgoing edges <- h:
         *      follow the edge
         *      construct the resulting weight
         *      compare it to existing weights for target node in set
         *      if it's smaller:
         *          remove path for target node from set
         *          re-add new path for target node to set
         *
         * We have a problem here. The STL set compares for equality using two
         * applications of the Compare functor (not a < b && not a > b), which
         * does not guarantee identity in the case of our pareto comparator.
         */
    }

    return sp;
}
