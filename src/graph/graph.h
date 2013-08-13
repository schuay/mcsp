#ifndef __GRAPH_H
#define __GRAPH_H

#include <graphviz/cgraph.h>
#include <string>
#include <vector>

namespace graph {

class Node;
class Edge;

class Graph
{
    friend class Node;
    friend class Edge;

public:
    Graph(const std::string &name);
    virtual ~Graph();

private:
    void add_node(Node *n);
    void add_edge(Edge *e);

private:
    Agraph_t *g;

    std::vector<Node *> nodes;
    std::vector<Edge *> edges;
};

}

#endif /* __GRAPH_H */
