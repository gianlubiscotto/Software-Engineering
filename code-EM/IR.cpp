#include "types.h"
#include "functions.h"

IR::IR(R x1,R x2)
{
    l=Min(x1,x2);
    u=Max(x1,x2);
}

bool operator==(const IR & X1, const IR & X2)
{
    return (X1.l == X2.l && X1.u == X2.u);
}

bool operator<=(const IR & X1, const IR & X2)
{
    return (X2.l <= X1.l) && (X1.u <= X2.u);
}

void cmp_a(const IR & X1, const IR & X2, CMP & c)
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

ostream & operator<<(ostream & stream, const IR & X)
{
    if (X.l < X.u)
        stream << "[" << X.l << "," << X.u << "]";
    else
        stream << "[" << X.l << "]";
    return stream;
}

bool ok (const IR& X)
{
    return X.l<=X.u;
}
