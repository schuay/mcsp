#ifndef __CANDIDATE_H
#define __CANDIDATE_H

#include <utility>
#include "graph/graph.h"
#include "graph/node.h"
namespace parallel_2D
{

/*TODO: Maybe this should be a class? */
typedef std::pair<graph::Node &, graph::weight_vector_t &> candidate_t;

bool operator< (const candidate_t &lhs,
                const candidate_t &rhs);

bool operator==(const candidate_t &lhs,
                const candidate_t &rhs);

}

#endif /* __CANDIDATE_H */
