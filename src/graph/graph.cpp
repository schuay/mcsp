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
    for (auto n : nodes) {
        delete n;
    }

    for (auto e : edges) {
        delete e;
    }

    agclose(g);
}

}
