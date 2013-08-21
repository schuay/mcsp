#ifndef __PARALLEL_2D_H
#define __PARALLEL_2D_H

#include "local_label_map.h"
#include "graph/graph.h"
#include "graph/node.h"
#include <map>

namespace parallel_2D
{

class Parallel_2D
{

public:
    Parallel_2D(const graph::Graph *g, const graph::Node *start);
    ~Parallel_2D();

private:
    const graph::Graph *m_graph;
    LocalLabelMap *m_labels;
};

}
#endif  /* __PARALLEL_2D_H */
