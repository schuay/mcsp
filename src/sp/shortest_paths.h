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

    void print() const;

public:
    std::unordered_map<const graph::Node *, Paths> paths;
};

}

#endif /* __SHORTEST_PATHS_H */
