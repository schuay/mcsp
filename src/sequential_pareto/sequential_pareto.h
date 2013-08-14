#ifndef __SEQUENTIAL_PARETO
#define __SEQUENTIAL_PARETO

#include <set>

#include "generator/generator.h"
#include "graph/graph.h"

class SequentialPareto
{
public:
    SequentialPareto(graph::Graph &g, graph::Node &start);

private:
    std::set<graph::Edge> pq;

};

#endif /* __SEQUENTIAL_PARETO */
