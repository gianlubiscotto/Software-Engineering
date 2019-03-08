#include "types.h"
#include "functions.h"

//POINTS IN R^d
template <typename R> 
N dim (const PR<R>& X)
{
    return X.x.size();
}
/*
template <typename R> 
bool ok(const PR<R>& X)
{
    return X.x.size()!=0;
}*/

//BOXES IN R^d
template <typename R> 
N dim (const BR<R>& X)
{
    return X.x.size();
}
/*
template <typename R> 
bool ok(const BR<R>& X)
{
    N d = X.x.size();
    if (d==0) return false;
    for (N i = 0; i < d; i++)
        if (!ok(X.x[i]))
            return false;
    return true;
}*/

template <typename R> 
bool operator==(const BR<R> & X1, const BR<R> & X2)
{
    return X1.x == X2.x;
}
template <typename R> 
bool operator<=(const BR<R> & X1, const BR<R> & X2)
{
    N d = X1.x.size();
    if (X2.x.size()!=d) return false;
    for (N i = 0; i < d; i++)
        if (!(X1.x[i]<=X2.x[i])) return false;
    return true;
}
template <typename R> 
void cmp_a(const BR<R> & X1, const BR<R> & X2, CMP & c)
{
    N d = X1.x.size();
    if (X2.x.size()!=d) c=c_no;
    if (c == c_no)
        return;
    for (N i = 0; c != c_no && i < d; i++)
        cmp_a(X1.x[i], X2.x[i], c);
    return;
}
template <typename R> 
PR<R> Min(const BR<R> &X)
{
    N d=X.x.size();
    PR<R> p(d);
    for (N i=0; i<d; i++)
        p.x[i]=X.x[i].l;
    return p;
}
template <typename R> 
PR<R> Max(const BR<R> &X)
{
    N d=X.x.size();
    PR<R> p(d);
    for (N i=0; i<d; i++)
        p.x[i]=X.x[i].u;
    return p;
}
template <typename R> 
ostream & operator<<(ostream & stream, const BR<R> & X)
{
    N d=X.x.size();
    //assume d>0
    stream << X.x[0];
    for (N i = 1; i < d; i++)
        stream << "x" << X.x[i];
    return stream;
}

