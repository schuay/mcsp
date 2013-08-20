#include <assert.h>
#include <stdio.h>

#include "generator/generator.h"
#include "sequential.h"
#include "sp/shortest_paths.h"

using namespace graph;

#define SEED (42)
#define START (1)

int
main(int argc __attribute__((unused)),
     char **argv __attribute__((unused)))
{
    Graph *g = Generator::generate_basicTestGraph(SEED);

    Node *n = g->get_node(START);
    assert(n);

    Sequential seq(g, n);

    sp::ShortestPaths *sp = seq.shortest_paths();

    g->write(stdout);
    printf("\nShortest paths:\n");
    sp->print();

    delete sp;
    delete g;

    return 0;
}
