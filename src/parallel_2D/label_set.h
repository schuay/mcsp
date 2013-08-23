#ifndef __LABEL_SET_H
#define __LABEL_SET_H

#include <set>

#include "graph/graph.h"

namespace parallel_2D
{

class LabelSet
{
public:
    LabelSet(const size_t dim);

    void insert(graph::weight_vector_t *weights);

private:
    std::set<graph::weight_vector_t *> m_labels;
    const size_t DIM;
};

}

#endif /* __LABEL_SET_H */
