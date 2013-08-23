#include <assert.h>
#include <getopt.h>
#include <pheet/pheet.h>
#include <stdio.h>

#include "generator/generator.h"
#include "graph/graph.h"
#include "parallel.h"

using namespace graph;
using namespace parallel;

typedef pheet::Pheet Pheet;

static void
usage(void)
{
    fprintf(stderr, "pmcsp [-n <# nodes>] [-m <# edges>] [-s <seed>] [-t <start node>]\n");
    exit(EXIT_FAILURE);
}

int
main(int argc,
     char **argv)
{
    int n = 10;
    int m = 15;
    int s = 42;
    int t __attribute__((unused)) = 1;

    int opt;
    while ((opt = getopt(argc, argv, "m:n:s:t:")) != -1) {
        switch (opt) {
        case 'm':
            m = strtol(optarg, NULL, 10);
            break;
        case 'n':
            n = strtol(optarg, NULL, 10);
            break;
        case 's':
            s = strtol(optarg, NULL, 10);
            break;
        case 't':
            t = strtol(optarg, NULL, 10);
            break;
        default:
            usage();
        }
    }

    Graph *g = Generator::directed("test graph", n, m, true,
                                   Generator::default_weights(), s);

    Node *start = g->get_node(t);
    assert(start);

    Parallel<Pheet> p(g, start);

    {
        Pheet::Environment e;
        /* TODO: Do stuff. */
    }

    delete g;

    return 0;
}
