#ifndef DAG_H_INCLUDED
#define DAG_H_INCLUDED

#include <fstream>
#include "types.h"

using namespace std;

typedef U_IR Leaf;//non-empty leaf in DAG

typedef vector<N> ListN;

struct Node//non-empty node in DAG
{
    vector < R > x; //incresing sequence in R of size #x>0
    ListN ux;//sequences of #x links to level below in DAG
    ListN u; //sequences of #x-1 links to level below in DAG
    friend bool operator==(const Node&X1, const Node&X2)
    {
        return X1.x==X2.x &&X1.ux==X2.ux &&X1.u==X2.u;
    };
};

typedef vector < Leaf > Leaves;//set of nodes at level 0 in DAG
typedef vector < Node > Nodes;//set of nodes at a given level in DAG

class DAG
{
private:
    Leaves leaf;  //set of non-empty nodes at level 0, G empty if #leaf=0
    vector < Nodes > nodes;//nodes[l] set of non-empty nodes at level l+
    //memoization
    vector<vector <vector <CMP> > > C;
    //C[l][j][i] comparison of i and j at level l, with i<j ('?' if not computed yet)
    vector<vector <vector <N> > > U;
    //U[l][j][i] result of union of i and j  at level l, with i<j (0 if not computed yet)

    N add_leaf(const Leaf&);//prevent duplication
    N add_node(const Node&, N l);//prevent duplication
    bool cover(const BR&,ListN&,N l) const;
    bool cover(R,R,const Node&,ListN&) const;
    CMP cmp(N,N,N l);//comparison of nodes at level l
    void cmp(const Node &, const Node &, CMP &, N l);
    N make(const BR&,N l);//make at level l
    N sum(N,N,N l);//union of nodes at level l
    Node sum(const Node & X1, const Node & X2, N l);
public:
    DAG(N d);//dimension d>0
    void print() const;//print DAG (for debug purposes)
    void print_test(ostream &cout) const;//print for testing
    void print2(N) const;//print subsets of the plane with integer bounds
    N dim() const;
    N empty() const;
    bool cover(const BR&,N) const;
    CMP cmp(N,N);
    N make(const BR&);
    N sum(N,N);
};

#endif	// DAG_H_INCLUDED
