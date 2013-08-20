#include "candidate.h"
using namespace graph;

namespace parallel_2D
{

bool
operator< (const candidate_t &lhs,
           const candidate_t &rhs)
{
    if (lhs.first == rhs.first) {
        if (lhs.second[0] == rhs.second[0]) {
            return lhs.second[1] < rhs.second[1];
        }
        return lhs.second[0] < rhs.second[0];
    }
    return lhs.first < rhs.first;
}

bool
operator==(const candidate_t &lhs,
           const candidate_t &rhs)
{
    if (lhs.first == rhs.first &&
            lhs.second[0] == rhs.second[0] &&
            lhs.second[1] == rhs.second[1]) {
        return true;
    }
    return false;
}

}
