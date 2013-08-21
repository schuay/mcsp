#include <getopt.h>
#include <stdio.h>

#include "generator.h"

using namespace graph;

static void
usage(void)
{
    fprintf(stderr, "gengraph [-n <# nodes>] [-m <# edges>] [-s <seed>]\n");
    exit(EXIT_FAILURE);
}

int
main(int argc,
     char **argv)
{
    int n = 10;
    int m = 15;
    int s = 42;

    int opt;
    while ((opt = getopt(argc, argv, "n:m:s:")) != -1) {
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
        default:
            usage();
        }
    }

    Graph *g = Generator::directed("test graph", n, m, true,
                                   Generator::default_weights(), s);

    g->write(stdout);

    delete g;

    return 0;
}
