
#include <assert.h>
#include "label_set.h"
using namespace graph;

namespace parallel_2D
{

LabelSet::
LabelSet(const size_t dim)
    : DIM(dim)
{

}

void
LabelSet::
insert(weight_vector_t *weights)
{
    assert(DIM == weights->size());
    m_labels.insert(weights);
}


}
