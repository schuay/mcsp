#include "path.h"

namespace sp
{

std::vector<graph::Edge *>
Path::
edges() const
{
    return m_edges;
}

std::vector<graph::weight_t>
Path::
weight() const
{
    return m_weight;
}

}
