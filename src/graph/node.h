#ifndef __NODE_H
#define __NODE_H

#include "graph.h"

namespace graph {

class Node
{
    friend class Edge;

public:
    Node(Graph *graph);

private:
    Graph *graph;
    Agnode_t *n;
};

}

#endif /* __NODE_H */
