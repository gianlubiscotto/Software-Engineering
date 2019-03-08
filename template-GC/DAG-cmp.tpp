#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

template <typename R> 
CMP DAG<R>::cmp(N i1,N i2)
{
    return cmp(i1,i2,dim()-1);
}

template <typename R> 
CMP DAG<R>::cmp(N i1,N i2,N l)
{
    if (i1<i2)
    {
        if (i1==0) return c_lt;
        else return c_not(cmp(i2,i1,l));
    }
    else if (i1==i2) return c_eq;
    else  if (i2==0) return c_gt;
    //i1>i2>0
    i1--;
    i2--;
    if (C[l][i1][i2]!='?')
        return C[l][i1][i2];
    C[l][i1][i2]=c_eq;
    if (l==0)
        cmp_a(leaf[i1],leaf[i2],C[l][i1][i2]);
    else
        cmp(nodes[l-1][i1],nodes[l-1][i2],C[l][i1][i2],l-1);
    return C[l][i1][i2];
}

template <typename R> 
void DAG<R>::cmp(const Node<R> & X1, const Node<R> & X2, CMP & c, N l)
{
    N n1 = X1.x.size(), n2 = X2.x.size();
    N i1 = 0, i2 = 0, u1 = 0, u2 = 0, ux1 = X1.ux[0], ux2 = X2.ux[0];
    R x1=X1.x[i1], x2=X2.x[i2];
    while (c != c_no && i1 < n1 && i2 < n2)
    {
        if (x1 < x2)
        {
            c=c_and(c,cmp(ux1,u2,l));
            i1++;
            if (i1 < n1)
            {
                u1 = X1.u[i1 - 1];
                ux1 = X1.ux[i1];
                x1=X1.x[i1];
            }
            else
                u1 = 0;
        }
        else if (x1 > x2)
        {
            c=c_and(c,cmp(u1,ux2,l));
            i2++;
            if (i2 < n2)
            {
                u2 = X2.u[i2 - 1];
                ux2 = X2.ux[i2];
                x2=X2.x[i2];
            }
            else
                u2 = 0;
        }
        else
        {
            c=c_and(c,cmp(ux1,ux2,l));
            i1++;
            if (i1 < n1)
            {
                u1 = X1.u[i1 - 1];
                ux1 = X1.ux[i1];
                x1=X1.x[i1];
            }
            else
                u1 = 0;
            i2++;
            if (i2 < n2)
            {
                u2 = X2.u[i2 - 1];
                ux2 = X2.ux[i2];
                x2=X2.x[i2];
            }
            else
                u2 = 0;
        }
        c=c_and(c,cmp(u1,u2,l));
    }
    if (c == c_no)
        return;
    if (i1 == n1 && i2 == n2)
        return;
    if (i1 < n1)
        c = c_and(c, c_gt);
    else
        c = c_and(c, c_lt);
}

