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
         * add the weight of the current path to the optima list
         * for all outgoing edges e = (tail, head) <- h:
         *      follow the edge, resulting in path p and weight w
         *      compare it to existing path weights for target node in set:
         *      for all dominated paths p':
         *          remove p' from queue
         *      if p is not dominated by any existing path to head:
         *          add p to queue
         *
         * We have a problem here. The STL set compares for equality using two
         * applications of the Compare functor (not a < b && not a > b), which
         * does not guarantee identity in the case of our pareto comparator.
         *
         * Required operations:
         *
         * * queue.min(): return first (dominating) element {head, path}.
         * * queue.erase(iterator or element): remove a specific element from the queue.
         * * queue.insert(element)
         * * retrieve all existing paths to a specific node
         */
    }

    return sp;
}
