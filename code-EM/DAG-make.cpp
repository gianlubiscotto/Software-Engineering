#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

N DAG::make(const BR& B)
{
    return make(B,dim()-1);
}

N DAG::make(const BR& B,N l)
{
    if (l==0)
    {
        Leaf X;
        add(X,B.x[0]);
        return add_leaf(X);
    }
    Node X;
    N u=make(B,l-1);
    R min=B.x[l].l, max=B.x[l].u;
    X.x.push_back(min);
    X.ux.push_back(u);
    if (min<max)
    {
        X.x.push_back(max);
        X.ux.push_back(u);
        X.u.push_back(u);
    }
    return add_node(X,l);
}

