#include "node.h"

namespace graph
{

bool
operator< (const graph::Node &lhs,
           const graph::Node &rhs)
{
    return lhs.id() < rhs.id();
}

bool
operator== (const graph::Node &lhs,
            const graph::Node &rhs)
{
    return lhs.id() == rhs.id();
}

ulong
Node::
id() const
{
    return AGID(n);
}

Graph *
Node::
graph() const
{
    return m_graph;
}

std::vector<Edge *>
Node::
out_edges() const
{
    std::vector<Edge *> edges;

    for (Agedge_t *e = agfstout(m_graph->g, n); e != nullptr; e = agnxtout(m_graph->g, e)) {
        edges.push_back(m_graph->get_edge(AGID(e)));
    }

    return edges;
}

Node::
Node(Graph *graph)
    : m_graph(graph)
{
    /* TODO: Add a node "label" attribute. */
    n = agnode(m_graph->g, NULL, TRUE);
    m_graph->add_node(AGID(n), this);
}

Node::
Node(Graph *graph,
     Agnode_t *n)
    : m_graph(graph), n(n)
{
    m_graph->add_node(AGID(n), this);
}

}
