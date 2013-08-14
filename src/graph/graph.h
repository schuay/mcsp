#ifndef __GRAPH_H
#define __GRAPH_H

#include <graphviz/cgraph.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace graph {

class Node;
class Edge;

#define ATTR_WEIGHT const_cast<char *>("weight")

class Graph
{
    friend class Node;
    friend class Edge;

public:
    Graph(const std::string &name);
    virtual ~Graph();

    static Graph *read(FILE *f);
    bool write(FILE *f);

    bool contains_edge(const Node *tail,
                       const Node *head) const;

    Node *add_node();
    Edge *add_edge(Node *tail,
                   Node *head,
                   const std::vector<int> &weights);

private:
    Graph(Agraph_t *g);

    Node *get_node(const ulong id) const;
    Edge *get_edge(const ulong id) const;

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
