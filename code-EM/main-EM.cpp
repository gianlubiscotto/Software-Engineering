#include <iostream>
#include <cstdlib>//for rand
#include "types.h"
#include "functions.h"
#include "DAG.h"

N seed=1;

N gen(N mod)
{
    N g=0;
    for (N i=0; i<seed; i++)
        g+=rand();
    return g%mod;
}

int main()
{
    cout << "TEST on union of intervals (UI)"<<endl;
    N d, nUI, nI, max;
    cout << "Give a seed in [1-9] ";
    cin>> seed;
    cout << "How many UI do you want? ";
    cin>>nUI;
    cout << "What is the max number (>0) of intervals they can have? ";
    cin>>nI;
    nI++;
    cout << "What is the max number (>0) in an interval? ";
    cin>>max;
    cout << "Give a dimension >0 for boxes ";
    cin>> d;
    if (seed==0||nI==0||max==0||d==0)
    {
        cout<<"wrong input!"<<endl;
        return 1;
    }
    max++;
    DAG G(d);
    vector<U_IR> vUI(nUI);
    vector<N> vUB(nUI);//links to U_BR in G
    for (N n=0; n<nUI; n++)
    {
        cout<<"adding to "<<vUI[n]<<" the following intervals"<<endl;
        N m=gen(nI);
        vUB[n]=G.empty();//empty UBR
        for (N i=0; i<m; i++)
        {
            R l=gen(max), u=gen(max);
            IR I=IR(l,u);
            add(vUI[n],I);
            cout<<'\t'<< I<<" the result is "<<vUI[n]<<endl;
            //mimic add at the level of R^n
            BR B(d);
            for (N i=0; i<d; i++)
                B.x[i]=I;
            if (G.cover(B,vUB[n])) cout<<"box is covered"<<endl;
            else
            {
	      N b=G.make(B);
                cout<<"\tadding "<<b<<" to "<<vUB[n];
                vUB[n]=G.sum(b,vUB[n]);
                cout<<" produce "<<vUB[n]<<endl;
            }
	    cout<<"snapshot "<<endl; G.print();
        }
    }
    cout<<"Comparisons o UI"<<endl;
    for(N i=0; i<nUI; i++)
        for(N j=0; j<nUI; j++)
        {
            CMP c=c_eq;
            cmp_a(vUI[i],vUI[j],c);
            cout<<"cmp of "<<vUI[i]<<" with "<<vUI[j]<<" is ";
            cout<<c<<" and "<<G.cmp(vUB[i],vUB[j])<<endl;
        }
    cout<<"info on DAG "<<endl;
    G.print();
    return 0;
}
