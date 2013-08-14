#ifndef __GRAPH_H
#define __GRAPH_H

#include <graphviz/cgraph.h>
#include <unordered_map>
#include <string>

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

    bool contains_edge(const Node *tail,
                       const Node *head);

private:
    void add_node(const ulong id,
                  Node *n);
    void add_edge(const ulong id,
                  Edge *e);

private:
    Agraph_t *g;

    std::unordered_map<ulong, Node *> nodes;
    std::unordered_map<ulong, Edge *> edges;
};

}

#endif /* __GRAPH_H */
