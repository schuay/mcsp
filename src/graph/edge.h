#ifndef __EDGE_H
#define __EDGE_H

#include <vector>

#include "node.h"

namespace graph {

class Edge
{
public:
    Edge(Node *tail, 
         Node *head,
         const std::vector<int> &weights);

private:
    Graph *graph;
    Node *tail, *head;
    Agedge_t *e;

    std::vector<int> weights;
};

}

#endif /* __EDGE_H */
