#ifndef __EDGE_H
#define __EDGE_H

#include <vector>

#include "node.h"

namespace graph
{

class Edge
{
    friend class Graph;

private:
    Edge(Node *t,
         Node *h,
         const std::vector<int> &ws);
    Edge(Graph *graph,
         Agedge_t *e);

    Node *tail() const;
    Node *head() const;

    std::vector<int> weights() const;

private:
    Graph *graph;
    Node *t, *h;
    Agedge_t *e;

    std::vector<int> ws;
};

}

#endif /* __EDGE_H */
