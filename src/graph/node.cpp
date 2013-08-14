#include "node.h"

namespace graph
{

ulong
Node::
id() const
{
    return AGID(n);
}

std::vector<Edge *>
Node::
out_edges() const
{
    std::vector<Edge *> edges;

    for (Agedge_t *e = agfstout(graph->g, n); e != nullptr; e = agnxtout(graph->g, e)) {
        edges.push_back(graph->get_edge(AGID(e)));
    }

    return edges;
}

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
