#ifndef __LOCAL_LABEL_MAP_H
#define __LOCAL_LABEL_MAP_H

#include "graph/graph.h"
#include "label_set.h"
#include <map>

namespace parallel_2D
{

class LocalLabelMap
{

public:
    LocalLabelMap(const std::vector<graph::Node *> nodes, const graph::Node *start, const size_t dim);
    ~LocalLabelMap();


public:
    std::map<const graph::Node *, LabelSet *> m_labelmap;

};

}


#endif /* __LOCAL_LABEL_MAP_H */
