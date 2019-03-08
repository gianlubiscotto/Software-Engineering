#include "types.h"
#include "functions.h"

//POINTS IN R^d

N dim (const PR& X)
{
    return X.x.size();
}

bool ok(const PR& X)
{
    return X.x.size()!=0;
}

//BOXES IN R^d

N dim (const BR& X)
{
    return X.x.size();
}

bool ok(const BR& X)
{
    N d = X.x.size();
    if (d==0) return false;
    for (N i = 0; i < d; i++)
        if (!ok(X.x[i]))
            return false;
    return true;
}

bool operator==(const BR & X1, const BR & X2)
{
    return X1.x == X2.x;
}

bool operator<=(const BR & X1, const BR & X2)
{
    N d = X1.x.size();
    if (X2.x.size()!=d) return false;
    for (N i = 0; i < d; i++)
        if (!(X1.x[i]<=X2.x[i])) return false;
    return true;
}

void cmp_a(const BR & X1, const BR & X2, CMP & c)
{
    N d = X1.x.size();
    if (X2.x.size()!=d) c=c_no;
    if (c == c_no)
        return;
    for (N i = 0; c != c_no && i < d; i++)
        cmp_a(X1.x[i], X2.x[i], c);
    return;
}

PR Min(const BR &X)
{
    N d=X.x.size();
    PR p(d);
    for (N i=0; i<d; i++)
        p.x[i]=X.x[i].l;
    return p;
}

PR Max(const BR &X)
{
    N d=X.x.size();
    PR p(d);
    for (N i=0; i<d; i++)
        p.x[i]=X.x[i].u;
    return p;
}

ostream & operator<<(ostream & stream, const BR & X)
{
    N d=X.x.size();
    //assume d>0
    stream << X.x[0];
    for (N i = 1; i < d; i++)
        stream << "x" << X.x[i];
    return stream;
}
