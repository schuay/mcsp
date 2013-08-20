#ifndef __LINKED_QUEUE_H
#define __LINKED_QUEUE_H

#include "queue.h"

#include <unordered_map>
#include <unordered_set>

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

    std::vector<sp::Path *> first(const size_t n);
    void insert(sp::Path *path);

private:
    typedef struct elem_t {
        struct elem_t *prev, *next;
        sp::Path *path;
    } elem_t;

    typedef std::unordered_map<graph::Node *, std::unordered_set<elem_t *>>
            node_ptrs_t;

private:
    node_ptrs_t m_elems_by_head;
    elem_t *m_list;
};

}

#endif /* __LINKED_QUEUE_H */
