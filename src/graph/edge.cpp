#include "edge.h"

#include <assert.h>
#include <sstream>

namespace graph
{

Edge::
Edge(Node *tail,
     Node *head,
     const std::vector<int> &weights)
    : tail(tail), head(head), weights(weights)
{
    assert(tail->graph == head->graph);

    graph = tail->graph;
    e = agedge(graph->g, tail->n, head->n, NULL, TRUE);
    graph->add_edge(AGID(e), this);

    std::stringstream ss;
    for (auto i : weights) {
        ss << i << " ";
    }
    agset(e, ATTR_WEIGHT, const_cast<char *>(ss.str().c_str()));
}

Edge::
Edge(Graph *graph,
     Agedge_t *e)
    : graph(graph), e(e)
{
    tail = graph->get_node(AGID(agtail(e)));
    head = graph->get_node(AGID(aghead(e)));

    std::stringstream ss(std::string(agget(e, ATTR_WEIGHT)));
    int w;
    while (ss >> w) {
        weights.push_back(w);
    }
}

}
