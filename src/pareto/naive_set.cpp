#include "less.h"
#include "naive_set.h"

using namespace sp;

namespace pareto
{

void
NaiveSet::
insert(sp::Paths paths)
{
    for (auto it : paths) {
        insert(it);
    }
}

void
NaiveSet::
insert(sp::PathPtr path)
{
    less dominates;
    bool add_elem = true;
    PathPtr lhs = path;
    for (auto i = m_set.begin(); i != m_set.end(); i++) {
        PathPtr rhs = *i;
        if (dominates(lhs.get(), rhs.get())) {
            m_set.erase(rhs);
        } else if (dominates(rhs.get(), lhs.get())) {
            add_elem = false;
            break;
        }
    }
    if (add_elem) {
        m_set.insert(path);
    }
}
}
