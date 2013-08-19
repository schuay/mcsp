#ifndef __LESS_H_
#define __LESS_H_

#include "sp/path.h"

namespace pareto
{

class less
{
public:
    bool operator()(const sp::Path *lhs,
                    const sp::Path *rhs) const;
};

}

#endif /* __LESS_H_ */
