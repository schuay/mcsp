#ifndef __LINKED_QUEUE_H
#define __LINKED_QUEUE_H

#include "queue.h"

#include <unordered_map>
#include <unordered_set>

#include "less.h"

namespace pareto
{

/**
 * A naive implementation of the pareto queue using linked lists.
 */
class LinkedQueue : public Queue
{
public:
    LinkedQueue();
    virtual ~LinkedQueue();

    std::vector<sp::PathPtr> first(const size_t n);
    void insert(sp::PathPtr path);
    bool empty() const;

private:
    typedef struct elem_t {
        struct elem_t *prev, *next;
        sp::PathPtr path;
    } elem_t;

    class elem_greater
    {
    public:
        less dominates;

        bool operator()(const elem_t *lhs, const elem_t *rhs) const {
            return dominates(rhs->path.get(), lhs->path.get());
        }
    };

    typedef std::unordered_map<const graph::Node *, std::unordered_set<elem_t *>>
            node_ptrs_t;

private:
    elem_t *list_insert(sp::PathPtr path);
    void    list_erase(elem_t *elem);

private:
    node_ptrs_t m_elems_by_head;
    elem_t *m_list;

    less dominates;
};

}

#endif /* __LINKED_QUEUE_H */
