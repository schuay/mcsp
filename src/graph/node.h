#ifndef __NODE_H
#define __NODE_H

#include <vector>

#include "graph.h"

namespace graph
{

class Node
{
    friend class Edge;
    friend class Graph;

public:
    ulong id() const;

    std::vector<Edge *> out_edges() const;

private:
    Node(Graph *graph);
    Node(Graph *graph, Agnode_t *n);

private:
    Graph *graph;
    Agnode_t *n;
};

}

#endif /* __NODE_H */
