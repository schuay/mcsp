#include "graph.h"

#include <stdexcept>

#include "edge.h"
#include "node.h"

namespace graph {

Graph::
Graph(const std::string &name)
{
    g = agopen(const_cast<char *>(name.c_str()), Agdirected, NULL);
}

Graph::
Graph(Agraph_t *g)
    : g(g)
{
    for (Agnode_t *n = agfstnode(g); n != nullptr; n = agnxtnode(g, n)) {
        new Node(this, n);
    }

    for (auto &p : nodes) {
        Agnode_t *n = p.second->n;
        for (Agedge_t *e = agfstout(g, n); e != nullptr; e = agnxtout(g, e)) {
            new Edge(this, e);
        }
    }
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

Graph *
Graph::
read(FILE *f)
{
    Agraph_t *g = agread(f, NULL);
    return new Graph(g);
}

bool
Graph::
write(FILE *f)
{
    return (agwrite(g, f) > 0);
}

bool
Graph::
contains_edge(const Node *tail,
              const Node *head) const
{
    Agedge_t *e = agedge(g, tail->n, head->n, NULL, FALSE);
    return (e != nullptr);
}

Node *
Graph::
get_node(const ulong id) const
{
    try {
        return nodes.at(id);
    } catch (const std::out_of_range &) {
        return nullptr;
    }
}

Edge *
Graph::
get_edge(const ulong id) const
{
    try {
        return edges.at(id);
    } catch (const std::out_of_range &) {
        return nullptr;
    }
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
