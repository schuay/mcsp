#ifndef __NODE_H
#define __NODE_H

#include <vector>

#include "graph.h"

namespace graph
{

bool operator< (const graph::Node &lhs,
                const graph::Node &rhs);

bool operator==(const graph::Node &lhs,
                const graph::Node &rhs);

class Node
{
    friend class Edge;
    friend class Graph;



public:
    ulong id() const;

    Graph *graph() const;

    std::vector<Edge *> out_edges() const;

private:
    Node(Graph *graph);
    Node(Graph *graph, Agnode_t *n);

private:
    Graph *m_graph;
    Agnode_t *n;
};

}

#endif /* __NODE_H */
