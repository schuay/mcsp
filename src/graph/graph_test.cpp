#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "edge.h"

int
main(int argc __attribute__((unused)),
     char **argv __attribute__((unused)))
{
    graph::Graph g("g", 3);

    graph::Node *tail = g.add_node();
    graph::Node *head = g.add_node();
    g.add_edge(tail, head, { 1, 3, 5 });

    g.write(stdout);

    return 0;
}
