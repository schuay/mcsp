#ifndef __LOCKING_VECTOR_H
#define __LOCKING_VECTOR_H

#include <mutex>
#include <vector>

namespace parallel
{

/** A quick and dirty wrapper around vector which provides thread-safe
 *  push_back() functions.
 */
template <typename T>
class LockingVector : public std::vector<T>
{
public:
    void locked_push_back(const T &);

private:
    std::mutex m_mutex;
};

}

#endif /* __LOCKING_VECTOR_H */
