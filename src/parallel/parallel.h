#ifndef __PARALLEL_H
#define __PARALLEL_H

#include <map>

#include "graph/graph.h"
#include "graph/node.h"
#include "sp/shortest_paths.h"

namespace parallel
{

template <class Pheet>
class Parallel
{
public:
    Parallel(const graph::Graph *g,
             const graph::Node *start);

    sp::ShortestPaths *
    shortest_paths();

private:
    const graph::Graph *m_graph;
    const graph::Node *m_start;
};

}
#endif  /* __PARALLEL_H */
