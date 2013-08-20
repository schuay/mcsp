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
    ShortestPaths *sp = new ShortestPaths();

    Path *init = new Path(start);
    m_queue.insert(init);

    while (!m_queue.empty()) {
        /* Retrieve our next optimal candidate path. */

        Path *p = m_queue.first(1)[0];
        const Node *head = p->head();

        /* We've expanded up to head. The path is therefore optimal and must
         * be added to our global shortest paths. */

        sp->paths[head].push_back(p);

        /* For all outgoing edges <- head: */

        for (auto & e : head->out_edges()) {
            /* The following steps are abstracted into queue.insert():
             *
             * Follow the edge, resulting in path p and weight w.
             * Compare it to existing path weights for target node in set:
             * For all dominated paths p':
             *     Remove p' from queue.
             * If p is not dominated by any existing path to head:
             *     Add p to queue.
             *
             * TODO: Convert paths to shared pointers.
             */
            m_queue.insert(p->step(e));
        }
    }

    return sp;
}
