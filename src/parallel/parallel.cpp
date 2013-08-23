#include "parallel.h"

using namespace graph;

namespace parallel
{

Parallel::
Parallel(const Graph *g,
         const Node *start)
    : m_graph(g)
{
    //init
    m_labels = new LocalLabelMap(g->nodes(), start, 2);

    //L = find pareto minima in Q

    //Q\L

    //expand edges of nodes in L = Lc

    //sort Lc by v

    //sort Lc(v) lexicographically
}

Parallel::
~Parallel()
{
    delete m_labels;
}

}
