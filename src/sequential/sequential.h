#ifndef __SEQUENTIAL
#define __SEQUENTIAL

#include <set>

#include "generator/generator.h"
#include "graph/graph.h"

class Sequential
{
public:
    Sequential(const graph::Graph &graph,
               const graph::Node &start);

private:
    std::set<graph::Edge> pq;

};

#endif /* __SEQUENTIAL */
