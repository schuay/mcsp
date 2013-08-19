#ifndef __SEQUENTIAL_H
#define __SEQUENTIAL_H

#include "graph/edge.h"
#include "graph/graph.h"
#include "sp/shortest_paths.h"

class Sequential
{
public:
    Sequential(const graph::Graph *graph,
               const graph::Node *start);

    sp::ShortestPaths *
    shortest_paths();

private:
    const graph::Graph *graph;
    const graph::Node *start;
};

#endif /* __SEQUENTIAL_H */
