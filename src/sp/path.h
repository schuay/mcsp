#ifndef __PATH_H
#define __PATH_H

#include <vector>

#include "graph/edge.h"

namespace sp
{

class Path;
typedef std::vector<Path *> Paths;

class Path
{
public:
    std::vector<graph::Edge *> edges() const;
    std::vector<graph::weight_t> weight() const;

private:
    std::vector<graph::Edge *> m_edges;
    std::vector<graph::weight_t> m_weight;
};

}

#endif /* __PATH_H */
