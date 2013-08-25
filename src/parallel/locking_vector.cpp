#include "locking_vector.h"

#include "sp/path.h"

namespace parallel
{

template <typename T>
void
LockingVector<T>::
locked_push_back(const T &val)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::vector<T>::push_back(val);
}

template class LockingVector<sp::PathPtr>;

}
