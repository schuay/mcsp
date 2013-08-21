#ifndef __GRAPH_H
#define __GRAPH_H

#include <graphviz/cgraph.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace graph
{

class Node;
class Edge;

typedef int weight_t;
typedef std::vector<weight_t> weight_vector_t;

#define ATTR_WEIGHT const_cast<char *>("label")
#define ATTR_DEGREE const_cast<char *>("degree")
#define ATTR_NODEID const_cast<char *>("label")

class Graph
{
    friend class Node;
    friend class Edge;

public:
    Graph(const std::string &name,
          const size_t degree);
    virtual ~Graph();

    static Graph *read(FILE *f);
    bool write(FILE *f);

    size_t degree() const;

    bool contains_edge(const Node *tail,
                       const Node *head) const;

    Node *add_node();
    Edge *add_edge(Node *tail,
                   Node *head,
                   const weight_vector_t &weights);

    size_t node_count() const;

    Node *get_node(const ulong id) const;
    std::vector<Node *> get_nodes() const;

private:
    Graph(Agraph_t *g);

    Edge *get_edge(const ulong id) const;

    void add_node(const ulong id,
                  Node *n);
    void add_edge(const ulong id,
                  Edge *e);

private:
    Agraph_t *g;

    size_t m_degree;

    std::unordered_map<ulong, Node *> nodes;
    std::unordered_map<ulong, Edge *> edges;
};

}

#endif /* __GRAPH_H */
