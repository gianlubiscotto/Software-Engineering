#include <iostream> //for debugging
#include <algorithm> //for sorting
#include "functions.h"
#include "DAG.h"

bool DAG::cover(const BR &B, N i) const
{
    if (i==0) return false;
    ListN C;//accumulator of non-empty nodes at level l that must cover B
    C.push_back(i);
    return cover(B,C,dim()-1);
}

bool DAG::cover(const BR &B,ListN& C, N l) const
{
    N n=C.size();//n>0
    if (n==0) return false;
    if (l==0)
    {
        bool b=true;
        for(N i=0; b&&i<n; i++)
            b=B.x[0]<=leaf[C[i]-1];
        return b;
    }
    //l>0
    ListN C_;
    bool b=true;
    for(N i=0; b&&i<n; i++)
        b=cover(B.x[l].l,B.x[l].u,nodes[l-1][C[i]-1],C_);
    N m=C_.size();
    if (m==0||!b) return false;
    //check cover at l-
    C.resize(0);
    sort(C_.begin(),C_.end());//sort C_
    N r=C_[0];
    C.push_back(r);
    for(N i=1; i<m; i++)
        if (C_[i]!=r)
        {
            r=C_[i];
            C.push_back(r);
        }
    return cover(B,C,l-1);
}

bool DAG::cover(R min, R max, const Node & X, ListN&C) const
{
    N n = X.x.size();
    if ((min<X.x[0])||(X.x[n-1]<max)) return false;
    //X.x.[0]<=min<=max<=X.x[n-1]
    N i, j;
    for (i=0; X.x[i]<min; i++);
    for (j=n-1; max<X.x[j]; j--);
    //min<=X.x[i] && X.x[j]<=max
    if (min<X.x[i]) //thus 0<i
    {
        N u=X.u[i-1];
        if (u>0) C.push_back(u);
        else return false;
    }
    if (X.x[j]<max) //thus j<n-1
    {
        N u=X.u[j];
        if (u>0) C.push_back(u);
        else return false;
    }
    for (N k=i; k<j; k++)
    {
        N u=X.u[k];
        if (u>0) C.push_back(u);
        else return false;
    }
    for (N k=i; k<=j; k++)
        C.push_back(X.ux[k]);
    return true;
}
