#ifndef __SHORTEST_PATHS_H
#define __SHORTEST_PATHS_H

#include <unordered_map>

#include "graph/node.h"
#include "path.h"

namespace sp
{

class ShortestPaths
{
public:
    virtual ~ShortestPaths();

    std::unordered_map<graph::Node *, Paths> paths() const;

private:
    std::unordered_map<graph::Node *, Paths> m_paths;
};

}

#endif /* __SHORTEST_PATHS_H */
