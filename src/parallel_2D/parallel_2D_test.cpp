#include <stdio.h>

#include <assert.h>
#include "generator/generator.h"
#include "graph/graph.h"

#define SEED (42)

int
main(int argc,
     char **argv)
{

    graph::Graph *g = graph::Generator::generate_basicTestGraph(SEED);

    graph::weight_vector_t w1(2, 0);
    graph::weight_vector_t w2(2, 1);
    int i1[] = {0, 1};
    int i2[] = {1, 0};
    graph::weight_vector_t w3(i1, i1 + sizeof(i1) / sizeof(int));
    graph::weight_vector_t w4(i2, i2 + sizeof(i2) / sizeof(int));
    graph::weight_vector_t w5(2, 1);

    std::vector<graph::Node *> nodes = g->nodes();
    assert(nodes.size() >= 5);



    delete g;
    return 0;
}
