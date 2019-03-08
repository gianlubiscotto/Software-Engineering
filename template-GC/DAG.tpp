#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

template <typename R> 
ostream & operator<<(ostream & cout, const Node<R> & X)
{
    N n=X.x.size();
    cout<<'['<<X.x[0]<<','<<X.ux[0]<<']';
    for (N i=1; i<n; i++)
        cout<<X.u[i-1]<<'['<<X.x[i]<<','<<X.ux[i]<<']';
    return cout;
}

template <typename R> 
DAG<R>::DAG (N d)
{
    if (d==0)
    {
        cout << "bad DAG initialization"<<endl;
        return;
    }
    nodes.resize(d-1);
    C.resize(d);
    U.resize(d);
}

template <typename R> 
N DAG<R>::dim () const
{
    return nodes.size()+1;
}

template <typename R> 
void DAG<R>::print_test(ostream &cout) const
{
    N d=dim();
    cout<<d<<" levels"<<endl;
    cout<<"level "<<0<<endl;
    N n=leaf.size();
    for (N i=0; i<n; i++)
        cout<<'\t'<<i+1<<':'<<leaf[i]<<endl;
    for(N l=0; l<d-1; l++)
    {
        cout<<"level "<<l+1<<endl;
        N n=nodes[l].size();
        for (N i=0; i<n; i++)
            cout<<'\t'<<i+1<<':'<<nodes[l][i]<<endl;
    }
}

template <typename R> 
N DAG<R>::empty () const
{
    return 0;
}

template <typename R> 
N DAG<R>::add_leaf(const Leaf<R>& X)
{
    if (X.S.size()==0) return 0;
    N n=leaf.size();
    for (N i=0; i<n; i++)
        if (leaf[i]==X) return i+1;
    leaf.push_back(X);
    C[0].resize(n+1);
    C[0][n]=vector<CMP>(n,'?');
    U[0].resize(n+1);
    U[0][n]=vector<N>(n,0);
    return n+1;
}

template <typename R> 
N DAG<R>::add_node(const Node<R>& X, N l)
{
    if (l==0 || l>=dim())
    {
        cout << "wrong level in add_node"<<endl;
        return 0;
    }
    if (X.x.size()==0) return 0;
    N n=nodes[l-1].size();
    for (N i=0; i<n; i++)
        if (nodes[l-1][i]==X) return i+1;
    nodes[l-1].push_back(X);
    C[l].resize(n+1);
    C[l][n]=vector<CMP>(n,'?');
    U[l].resize(n+1);
    U[l][n]=vector<N>(n,0);
    return n+1;
}

