#include "edge.h"

#include <assert.h>

namespace graph {

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
}

Edge::
Edge(Graph *graph,
     Agedge_t *e)
    : graph(graph), e(e)
{
    tail = graph->get_node(AGID(agtail(e)));
    head = graph->get_node(AGID(aghead(e)));

    /* TODO: Restore weights. */
}

}
