#include "types.h"
#include "functions.h"

//CMP
CMP c_and(CMP c1, CMP c2)
{
    if (c1 == c_no)
        return c_no;
    if (c2 == c_no)
        return c_no;
    if (c1 == c_eq)
        return c2;
    if (c2 == c_eq)
        return c1;
    if (c1 == c2)
        return c1;
    return c_no;
}

CMP c_not(CMP c)
{
    if (c==c_lt) return c_gt;
    else if (c==c_gt) return c_lt;
    else return c;
}

//R
template <typename R>
R Min(R x1, R x2)
{
    if (x1 < x2)
        return x1;
    else
        return x2;
}
template <typename R>
R Max(R x1, R x2)
{
    if (x1 < x2)
        return x2;
    else
        return x1;
}

