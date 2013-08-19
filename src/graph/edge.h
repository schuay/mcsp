#ifndef __EDGE_H
#define __EDGE_H

#include <vector>

#include "node.h"

namespace graph
{

typedef int weight_t;

class Edge
{
    friend class Graph;

private:
    Edge(Node *t,
         Node *h,
         const std::vector<weight_t> &ws);
    Edge(Graph *graph,
         Agedge_t *e);

    Node *tail() const;
    Node *head() const;

    std::vector<weight_t> weights() const;

private:
    Graph *graph;
    Node *t, *h;
    Agedge_t *e;

    std::vector<weight_t> ws;
};

}

#endif /* __EDGE_H */
