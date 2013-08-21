#include <stdio.h>

#include "candidate_set.h"
#include "generator/generator.h"
#include "graph/graph.h"

#define SEED (42)

int
main(int argc,
     char **argv)
{

    graph::Graph *g = graph::Generator::generate_basicTestGraph(SEED);
    parallel_2D::CandidateSet candidates();

    graph::weight_vector_t w1(2, 0);
    graph::weight_vector_t w2(2, 1);
    int i1[] = {0, 1};
    int i2[] = {1, 0};
    graph::weight_vector_t w3(i1, i1 + sizeof(i1) / sizeof(int));
    graph::weight_vector_t w4(i2, i2 + sizeof(i2) / sizeof(int));
    graph::weight_vector_t w5(2, 1);

    std::vector<graph::Node *> nodes = g->nodes();
    assert(nodes.size() >= 5);

    parallel_2D::candidate_t c1(*nodes[1], w1);
    parallel_2D::candidate_t c2(*nodes[1], w2);
    parallel_2D::candidate_t c3(*nodes[2], w3);
    parallel_2D::candidate_t c4(*nodes[2], w4);
    parallel_2D::candidate_t c5(*nodes[0], w1);
    parallel_2D::candidate_t c6(*nodes[0], w2);
    parallel_2D::candidate_t c7(*nodes[0], w3);
    parallel_2D::candidate_t c8(*nodes[0], w4);
    parallel_2D::candidate_t c9(*nodes[0], w5);
    parallel_2D::candidate_t c10(*nodes[0], w2);

    parallel_2D::CandidateSet set;

    set.insert(c1);
    set.insert(c2);
    set.insert(c3);
    set.insert(c4);
    set.insert(c5);
    set.insert(c6);
    set.insert(c7);
    set.insert(c8);
    set.insert(c9);
    set.insert(c10);

    set.print();

    delete g;
    return 0;
}
