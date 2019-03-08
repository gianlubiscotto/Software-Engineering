#include "types.h"
#include "functions.h"
template <typename R> 
IR<R>::IR(R x1,R x2)
{
    l=Min(x1,x2);
    u=Max(x1,x2);
}

template <typename R> 
bool operator==(const IR<R> & X1, const IR<R> & X2)
{
    return (X1.l == X2.l && X1.u == X2.u);
}
template <typename R> 
bool operator<=(const IR<R> & X1, const IR<R> & X2)
{
    return (X2.l <= X1.l) && (X1.u <= X2.u);
}
template <typename R> 
void cmp_a(const IR<R> & X1, const IR<R> & X2, CMP & c)
{
    if (c == c_no)
        return;
    if (X1 == X2)
        c = c_and(c, c_eq);
    else if (X1 <= X2)
        c = c_and(c, c_lt);
    else if (X2 <= X1)
        c = c_and(c, c_gt);
    else
        c = c_no;
}
template <typename R> 
ostream & operator<<(ostream & stream, const IR<R> & X)
{
    if (X.l < X.u)
        stream << "[" << X.l << "," << X.u << "]";
    else
        stream << "[" << X.l << "]";
    return stream;
}

