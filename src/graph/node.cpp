#include "node.h"

namespace graph {

Node::
Node(Graph *graph)
    : graph(graph)
{
    n = agnode(graph->g, NULL, TRUE);
    graph->add_node(AGID(n), this);
}

Node::
Node(Graph *graph,
     Agnode_t *n)
    : graph(graph), n(n)
{
    graph->add_node(AGID(n), this);
}

}
