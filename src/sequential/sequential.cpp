#include "sequential.h"

Sequential::
Sequential(const graph::Graph *graph,
           const graph::Node *start)
    : graph(graph), start(start)
{
}

sp::ShortestPaths *
Sequential::
shortest_paths()
{
    /* Do stuff here. */

    return new sp::ShortestPaths;
}
