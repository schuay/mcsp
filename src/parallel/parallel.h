#ifndef __PARALLEL_H
#define __PARALLEL_H

#include <map>

#include "graph/graph.h"
#include "graph/node.h"
#include "local_label_map.h"

namespace parallel
{

class Parallel
{
public:
    Parallel(const graph::Graph *g,
             const graph::Node *start);
    ~Parallel();

private:
    const graph::Graph *m_graph;
    LocalLabelMap *m_labels;
};

}
#endif  /* __PARALLEL_H */
