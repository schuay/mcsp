#include <stdio.h>

#include "generator/generator.h"
#include "sequential_pareto.h"

int
main(int argc __attribute__((unused)),
     char **argv __attribute__((unused)))
{
    graph::Generator::Wl wl;
    wl.push_back(std::pair<int, int>(0, 1));
    wl.push_back(std::pair<int, int>(3, 10));
    wl.push_back(std::pair<int, int>(-2, 2));
    Graph *g = graph::Generator::generate_rDiGraph("test graph", 10, 15, true, wl,
               (unsigned short) time(NULL));


    return 0;
}
