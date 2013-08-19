#include "shortest_paths.h"

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

}
