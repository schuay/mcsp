#include "shortest_paths.h"

#include <stdio.h>

namespace sp
{

ShortestPaths::
~ShortestPaths()
{
    for (auto & p : paths) {
        for (auto & path : p.second) {
            delete path;
        }
    }
}

void
ShortestPaths::
print() const
{
    for (const auto & p : paths) {
        for (const auto & path : p.second) {
            path->print();
        }
        printf("\n");
    }
}

}
