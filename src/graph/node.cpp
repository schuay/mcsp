#include "node.h"

namespace graph {

Node::
Node(Graph *graph)
    : graph(graph)
{
    n = agnode(graph->g, NULL, TRUE);
    graph->add_node(this);
}

}
