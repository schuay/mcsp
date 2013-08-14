#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "edge.h"

int
main(int argc,
     char **argv)
{
    graph::Graph g("g");

    graph::Node *tail = new graph::Node(&g);
    graph::Node *head = new graph::Node(&g);
    graph::Edge *e = new graph::Edge(tail, head, { 1, 3, 5 });

    g.write(stdout);

    return 0;
}
