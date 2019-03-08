#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

template <typename R> 
N DAG<R>::make(const BR<R>& B)
{
    return make(B,dim()-1);
}

template <typename R> 
N DAG<R>::make(const BR<R>& B,N l)
{
    if (l==0)
    {
        Leaf<R> X;
        add(X,B.x[0]);
        return add_leaf(X);
    }
    Node<R> X;
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

