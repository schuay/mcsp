#include <stdio.h>

#include "sequential_pareto.h"
#include "../generator/generator.h"

int
main(int argc,
     char **argv)
{
    graph::Generator::Wl wl;
    wl.push_back(std::pair<int, int>(0, 1));
    wl.push_back(std::pair<int, int>(3, 10));
    wl.push_back(std::pair<int, int>(-2, 2));
    Graph *g = graph::Generator::generate_rDiGraph(std::string("test graph"), 10, 15, true, wl,
               (unsigned short) time(NULL));


    return 0;
}
