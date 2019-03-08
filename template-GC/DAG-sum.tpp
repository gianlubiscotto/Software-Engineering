#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

template <typename R> 
N DAG<R>::sum(N i1,N i2)
{
    return sum(i1,i2,dim()-1);
}

template <typename R> 
N DAG<R>::sum(N i1,N i2,N l)
{
    if (i1==0) return i2;
    if (i2==0) return i1;
    if (i1==i2) return i1;
    if (i1<i2)
    {
        N i=i1;
        i1=i2;
        i2=i;
    }
    //i1>i2>0
    i1--;
    i2--;
    if (U[l][i1][i2]!=0)
        return U[l][i1][i2];
    if (l==0)
        return add_leaf(leaf[i1]+leaf[i2]);
    else
        return add_node(sum(nodes[l-1][i1],nodes[l-1][i2],l-1),l);
}

template <typename R> 
Node<R> DAG<R>::sum(const Node<R> & X1, const Node<R> & X2, N l)
{
    Node<R> X;
    N n1 = X1.x.size(), n2 = X2.x.size();
    N i1 = 0, u1 = 0, ux1 = X1.ux[i1];
    R x1=X1.x[i1];
    N i2 = 0, u2 = 0, ux2 = X2.ux[i2];
    R x2=X2.x[i2];
    N u=0, ux, uu;
    R x;
    while (i1 < n1 && i2 < n2)
    {
        if (x1 < x2)
        {
            x=x1;
            ux=sum(ux1,u2,l);
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
            x=x2;
            ux=sum(ux2,u1,l);
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
            x=x1;
            ux=sum(ux1,ux2,l);
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
        uu=sum(u1,u2,l);
        if (u!=ux||ux!=uu)
        {
            X.x.push_back(x);
            X.ux.push_back(ux);
            X.u.push_back(uu);
            u=uu;
        }
    }
    if (i1<n1)
    {
        for(N i=i1; i<n1; i++)
        {
            X.x.push_back(X1.x[i]);
            X.ux.push_back(X1.ux[i]);
        }
        for(N i=i1; i<n1-1; i++)
            X.u.push_back(X1.u[i]);
    }
    else if (i2<n2)
    {
        for(N i=i2; i<n2; i++)
        {
            X.x.push_back(X2.x[i]);
            X.ux.push_back(X2.ux[i]);
        }
        for(N i=i2; i<n2-1; i++)
            X.u.push_back(X2.u[i]);
    }
    else
        X.u.pop_back();
    return X;
}

