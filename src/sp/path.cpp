#include "path.h"

using namespace graph;
using std::vector;

namespace sp
{

Path::
Path(const graph::Node *init)
    : m_tail(init), m_head(init)
{
    m_weight.resize(init->graph()->degree(), 0);
}

Path *
Path::
step(const Edge *edge) const
{
    return nullptr; /* TODO */
}

const Node *
Path::
tail() const
{
    return m_tail;
}

const Node *
Path::
head() const
{
    return m_head;
}

vector<const Edge *>
Path::
edges() const
{
    return m_edges;
}

vector<weight_t>
Path::
weight() const
{
    return m_weight;
}

}
