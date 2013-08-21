#include "local_label_map.h"

using namespace graph;

namespace parallel_2D
{

LocalLabelMap::LocalLabelMap(const std::vector<Node *> nodes, const Node *start, const size_t dim)
{
    for (auto & n : nodes) {
        LabelSet *set = new LabelSet(dim);
        m_labelmap[n] = set;
    }
    weight_vector_t *w = new weight_vector_t(2, 0);
    m_labelmap[start]->insert(w);
}

LocalLabelMap::~LocalLabelMap()
{
    for (auto it : m_labelmap) {
        delete it.second;
    }
}
}
