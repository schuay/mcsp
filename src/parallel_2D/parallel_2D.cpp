#include "parallel_2D.h"

using namespace graph;

namespace parallel_2D
{

Parallel_2D::
Parallel_2D(const Graph *g,
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

Parallel_2D::
~Parallel_2D()
{
    delete m_labels;
}

}
