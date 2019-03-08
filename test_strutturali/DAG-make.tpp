#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

template <typename R> 
N DAG<R>::make(const BR<R>& B)
{
	cout<<"make0"<<endl;
    return 1;
}

template <typename R> 
N DAG<R>::make(const BR<R>& B,N l)
{
    if (l==0)
    {
		cout<<"make1"<<endl;
        Leaf<R> X;
        return 1;
    }
	cout<<"make2"<<endl;
    Node<R> X;
    N u=1;
    R min=B.x[l].l, max=B.x[l].u;
    X.x.push_back(min);
    X.ux.push_back(u);
    if (min<max)
    {
		cout<<"make3"<<endl;
        X.x.push_back(max);
        X.ux.push_back(u);
        X.u.push_back(u);
    }
	cout<<"make4"<<endl;
    return 1;
}

