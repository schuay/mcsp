#include "graph.h"

#include "edge.h"
#include "node.h"

namespace graph {

Graph::
Graph(const std::string &name)
{
    g = agopen(const_cast<char *>(name.c_str()), Agdirected, NULL);
}

Graph::
~Graph()
{
    for (auto &n : nodes) {
        delete n.second;
    }

    for (auto &e : edges) {
        delete e.second;
    }

    agclose(g);
}

bool
Graph::
contains_edge(const Node *tail,
              const Node *head)
{
    Agedge_t *e = agedge(g, tail->n, head->n, NULL, FALSE);
    return (e != nullptr);
}

void
Graph::
add_node(const ulong id,
         Node *n)
{
    nodes.emplace(id, n);
}

void
Graph::
add_edge(const ulong id,
         Edge *e)
{
    edges.emplace(id, e);
}

}
