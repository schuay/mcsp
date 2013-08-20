#ifndef __CANDIDATE_SET_H
#define __CANDIDATE_SET_H

#include <assert.h>
#include "candidate.h"
#include "graph/graph.h"
#include <set>
#include <vector>
#include <stddef.h>

namespace parallel_2D
{

/**
 A set of candidates, ordered lexicographically by node and weight vector
*/
class CandidateSet
{

public:
    CandidateSet();

    bool insert(const candidate_t &candidate);
    bool insert(graph::Node &node, graph::weight_vector_t &weight);

    void print() const;

private:
    std::set<candidate_t> m_candidates;
    const size_t dim = 2;

private:

};

}

#endif /* __CANDIDATE_SET_H */
