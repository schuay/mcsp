#include "linked_queue.h"

#include <assert.h>
#include <queue>
#include <vector>

using namespace graph;
using namespace sp;

namespace pareto
{

bool
LinkedQueue::elem_lexic_greater::
operator()(const elem_t *lhs, const elem_t *rhs) const
{
    assert(lhs && rhs);

    const std::vector<graph::weight_t> l = lhs->path->weight();
    const std::vector<graph::weight_t> r = rhs->path->weight();

    assert(l.size() == r.size());
    const int dims = l.size();

    for (int i = 0; i < dims; i++) {
        if (l[i] == r[i]) {
            continue;
        }
        return (l[i] > r[i]);
    }

    return false;
}

LinkedQueue::
LinkedQueue()
    : m_list(nullptr)
{
}

LinkedQueue::
~LinkedQueue()
{
    elem_t *curr = nullptr;
    elem_t *next = m_list;

    while (next != nullptr) {
        curr = next;
        next = next->next;
        delete curr;
    }
}

PathPtr
LinkedQueue::
first()
{
    std::priority_queue<elem_t *, std::vector<elem_t *>, elem_lexic_greater> q;

    for (elem_t *n = m_list; n != nullptr; n = n->next) {
        q.push(n);
    }

    elem_t *n = q.top();
    PathPtr p = n->path;

    m_elems_by_head[p->head()].erase(n);
    list_erase(n);

    return p;
}

void
LinkedQueue::
insert(PathPtr path)
{
    const Node *head = path->head();
    std::unordered_set<elem_t *> &elems = m_elems_by_head[head];

    /* First, insert the new element. */

    elem_t *elem = list_insert(path);
    elems.insert(elem);

    /* Then, prune all dominated elements within this node's path set. */

    for (auto it = elems.begin(); it != elems.end();) {
        elem_t *other = *it;

        if (other == elem) {
            it++;
            continue;
        }

        if (dominates(elem->path.get(), other->path.get())) {
            /* Remove other. */
            elems.erase(it++);
            list_erase(other);
        } else if (dominates(other->path.get(), elem->path.get())) {
            /* Remove elem. Break from loop, since we only insert a single new
             * element, domination is transitive, and within the original
             * queue no paths dominate each other within a node set. */
            elems.erase(elem);
            list_erase(elem);
            return;
        } else { /* No domination in either direction. */
            it++;
        }
    }
}

bool
LinkedQueue::
empty() const
{
    return (m_list == nullptr);
}

LinkedQueue::elem_t *
LinkedQueue::
list_insert(PathPtr path)
{
    elem_t *elem = new elem_t;
    elem->path = path;
    elem->prev = nullptr;
    elem->next = m_list;

    if (m_list != nullptr) {
        m_list->prev = elem;
    }
    m_list = elem;

    return elem;
}

void
LinkedQueue::
list_erase(elem_t *elem)
{
    if (elem == m_list) {
        m_list = elem->next;
    }

    if (elem->prev != nullptr) {
        elem->prev->next = elem->next;
    }

    if (elem->next != nullptr) {
        elem->next->prev = elem->prev;
    }

    delete elem;
}

}
