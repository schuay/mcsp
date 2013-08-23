#include "naive_linked_queue.h"

#include <assert.h>
#include <unordered_set>

using namespace sp;

namespace pareto
{

std::vector<PathPtr>
NaiveLinkedQueue::
first(const size_t n)
{
    std::unordered_set<elem_t *> elems;
    for (elem_t *m = m_list; m != nullptr; m = m->next) {
        elems.insert(m);
    }

    /* Prune all dominated elements. */

    for (auto i = elems.begin(); i != elems.end();) {
        elem_t *lhs = *i;
        bool broke_early = false;

        /* j = i + 1 does not work :( */
        auto j = i;
        j++;
        for (; j != elems.end();) {
            elem_t *rhs = *j;

            if (dominates(lhs->path.get(), rhs->path.get())) {
                /* Remove rhs. */
                elems.erase(j++);
            } else if (dominates(rhs->path.get(), lhs->path.get())) {
                /* Remove lhs and break from loop. */
                elems.erase(i++);
                broke_early = true;
                break;
            } else { /* No domination in either direction. */
                j++;
            }
        }

        if (!broke_early) {
            i++;
        }
    }

    std::vector<PathPtr> ps;
    size_t i = 0;
    for (auto it = elems.begin(); it != elems.end() && i < n; it++, i++) {
        elem_t *elem = *it;
        ps.push_back(elem->path);

        m_elems_by_head[elem->path->head()].erase(elem);
        list_erase(elem);
    }

    return ps;
}

}
