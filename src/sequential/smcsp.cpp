#include <assert.h>
#include <getopt.h>
#include <stdio.h>

#include "generator/generator.h"
#include "sequential.h"
#include "sp/shortest_paths.h"

using namespace graph;

static void
usage(void)
{
    fprintf(stderr, "gengraph [-n <# nodes>] [-m <# edges>] [-s <seed>] [-t <start node>]\n");
    exit(EXIT_FAILURE);
}

int
main(int argc __attribute__((unused)),
     char **argv __attribute__((unused)))
{
    int n = 10;
    int m = 15;
    int s = 42;
    int t = 1;

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

    Graph *g = Generator::generate_rDiGraph("test graph", n, m, true,
                                            Generator::default_weights(), s);

    Node *node = g->get_node(t);
    assert(node);

    Sequential seq(g, node);

    sp::ShortestPaths *sp = seq.shortest_paths();

    g->write(stdout);
    printf("\nShortest paths:\n");
    sp->print();

    delete sp;
    delete g;

    return 0;
}
