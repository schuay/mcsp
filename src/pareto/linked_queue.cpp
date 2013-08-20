#include "linked_queue.h"

using namespace graph;
using namespace sp;

namespace pareto
{

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

std::vector<Path *>
LinkedQueue::
first(const size_t n)
{
    return { };
}

void
LinkedQueue::
insert(Path *path)
{
}

LinkedQueue::elem_t *
LinkedQueue::
list_insert(Path *path)
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
