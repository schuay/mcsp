#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "edge.h"

int
main(int argc,
     char **argv)
{
    graph::Graph g("g");

    graph::Node *tail = g.add_node();
    graph::Node *head = g.add_node();
    graph::Edge *e = g.add_edge(tail, head, { 1, 3, 5 });

    g.write(stdout);

    return 0;
}
