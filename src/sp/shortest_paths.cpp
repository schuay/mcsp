#include "shortest_paths.h"

namespace sp
{

ShortestPaths::
~ShortestPaths()
{
    for (auto & p : m_paths) {
        for (auto & path : p.second) {
            delete path;
        }
    }
}

}
