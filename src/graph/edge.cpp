#include "edge.h"

#include <assert.h>
#include <sstream>

namespace graph
{

Edge::
Edge(Node *t,
     Node *h,
     const std::vector<int> &ws)
    : t(t), h(h), ws(ws)
{
    assert(t->graph == h->graph);

    graph = t->graph;
    e = agedge(graph->g, t->n, h->n, NULL, TRUE);
    graph->add_edge(AGID(e), this);

    std::stringstream ss;
    for (auto i : ws) {
        ss << i << " ";
    }
    agset(e, ATTR_WEIGHT, const_cast<char *>(ss.str().c_str()));
}

Edge::
Edge(Graph *graph,
     Agedge_t *e)
    : graph(graph), e(e)
{
    t = graph->get_node(AGID(agtail(e)));
    h = graph->get_node(AGID(aghead(e)));

    std::stringstream ss(std::string(agget(e, ATTR_WEIGHT)));
    int w;
    while (ss >> w) {
        ws.push_back(w);
    }
}

Node *
Edge::
tail() const
{
    return t;
}

Node *
Edge::
head() const
{
    return h;
}

std::vector<int>
Edge::
weights() const
{
    return ws;
}

}
