#include "candidate_set.h"
#include <assert.h>

namespace parallel_2D
{


CandidateSet::CandidateSet()
{

}

bool
CandidateSet::
insert(const candidate_t &candidate)
{
    assert(dim == candidate.second.size());
    candidates.insert(candidate);

    return true;
}

bool
CandidateSet::
insert(graph::Node &node, graph::weight_vector_t &weight)
{
    candidate_t candidate(node, weight);
    insert(candidate);

    return true;
}

}
