#ifndef __EDGE_H
#define __EDGE_H

#include <vector>

#include "node.h"

namespace graph {

class Edge
{
    friend class Graph;

public:
    Edge(Node *tail, 
         Node *head,
         const std::vector<int> &weights);

private:
    Edge(Graph *graph,
         Agedge_t *e);

private:
    Graph *graph;
    Node *tail, *head;
    Agedge_t *e;

    std::vector<int> weights;
};

}

#endif /* __EDGE_H */
