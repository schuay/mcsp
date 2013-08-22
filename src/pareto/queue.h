#ifndef __QUEUE_H
#define __QUEUE_H

#include <vector>

#include "sp/path.h"

namespace pareto
{

/**
 * A high level interface for the required pareto queue operations
 * first() and insert().
 */
class Queue
{
public:
    /**
     * Returns the first element and removes it from the queue.
     */
    virtual sp::PathPtr first() = 0;

    /**
     * Inserts path into the queue.
     *
     * Let ps be the set of all paths p' with p'.head() == path.head()
     * (including path itself).
     *
     * insert() additionally removes all nodes <- ps which are dominated by
     * any other node <- ps.
     */
    virtual void insert(sp::PathPtr path) = 0;

    virtual bool empty() const = 0;
};

}

#endif /* __QUEUE_H */
