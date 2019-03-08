#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

void DAG::print2 (const N ub) const
//only subsets of [1,9]x[1,9] with integer bounds are printed
{
    if (dim()!=2) cout<<"Abort: only subsets of the plane are printed";
    N s=9;
    N S=2*s;
    char P[S][s+1];//planar display
    for (N x=0; x<S; x++)
        for (N y=0; y<=s; y++)
            P[x][y]=' ';
    for (N i=1; i<=s; i++)
        P[0][i]=P[2*i-1][0]='0'+i;
    //TODO
    P[1][1]='.';
    P[2][1]='_';
    P[3][1]='|';
    P[4][1]='*';
    cout<<endl;
    for (N y=0; y<=s; y++)
    {
        for (N x=0; x<S; x++)
            cout<<P[x][s-y];
        cout<<endl;
    }
}
