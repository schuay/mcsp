#include "../generator/generator.h"
#include "../graph/graph.h"
#include "set"

class SequentialPareto
{

public:
    SequentialPareto(Graph &g, Node &start);

private:
    std::set<graph::Edge> pq;

};
