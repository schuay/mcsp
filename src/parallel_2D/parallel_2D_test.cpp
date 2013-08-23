#include <assert.h>
#include <stdio.h>

#include "generator/generator.h"
#include "graph/graph.h"

#define SEED (42)

int
main(int argc __attribute__((unused)),
     char **argv __attribute__((unused)))
{
    graph::Graph *g = graph::Generator::basic(SEED);

    std::vector<graph::Node *> nodes = g->nodes();
    assert(nodes.size() >= 5);

    delete g;

    return 0;
}
