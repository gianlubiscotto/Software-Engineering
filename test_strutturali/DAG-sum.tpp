#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

template <typename R> 
N DAG<R>::sum(N i1,N i2)
{
    return 1;
}

template <typename R> 
N DAG<R>::sum(N i1,N i2,N l)
{
    if (i1==0){
		cout<<"sum1"<<endl;
		return i2;
	}
	cout<<"sum2"<<endl;
    if (i2==0){
		cout<<"sum3"<<endl;
		return i1;
	}
	cout<<"sum4"<<endl;
    if (i1==i2){
		cout<<"sum5"<<endl;
		return i1;
	} 
	cout<<"sum6"<<endl;
    if (i1<i2)
    {
		cout<<"sum7"<<endl;
        N i=i1;
        i1=i2;
        i2=i;
    }
	cout<<"sum8"<<endl;
    //i1>i2>0
    i1--;
    i2--;
    if (U[l][i1][i2]!=0){	
		cout<<"sum9"<<endl;
        return U[l][i1][i2];
	}
	cout<<"sum10"<<endl;
    if (l==0){
		cout<<"sum11"<<endl;
        return 1;
	}
    else{
		cout<<"sum12"<<endl;
        return 1;
	}
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
		cout<<"sum1"<<endl;
        if (x1 < x2)
        {
			cout<<"sum2"<<endl;
            x=x1;
            ux=1;
            i1++;
            if (i1 < n1)
            {
				cout<<"sum3"<<endl;
                u1 = X1.u[i1 - 1];
                ux1 = X1.ux[i1];
                x1=X1.x[i1];
            }
            else{
				cout<<"sum4"<<endl;
                u1 = 0;
			}
        }
        else if (x1 > x2)
        {	
			cout<<"sum5"<<endl;
            x=x2;
            ux=1;
            i2++;
            if (i2 < n2)
            {
				cout<<"sum6"<<endl;
                u2 = X2.u[i2 - 1];
                ux2 = X2.ux[i2];
                x2=X2.x[i2];
            }
            else{
				cout<<"sum7"<<endl;
                u2 = 0;
			}
        }
        else
        {
			cout<<"sum8"<<endl;
            x=x1;
            ux=1;
            i1++;
            if (i1 < n1)
            {
				cout<<"sum9"<<endl;
                u1 = X1.u[i1 - 1];
                ux1 = X1.ux[i1];
                x1=X1.x[i1];
            }
            else{
				cout<<"sum10"<<endl;
                u1 = 0;
			}
            i2++;
            if (i2 < n2)
            {	
				cout<<"sum11"<<endl;
                u2 = X2.u[i2 - 1];
                ux2 = X2.ux[i2];
                x2=X2.x[i2];
            }
            else{
				cout<<"sum12"<<endl;
                u2 = 0;
			}
        }
        uu=1;
        if (u!=ux||ux!=uu)
        {
			cout<<"sum13"<<endl;
            X.x.push_back(x);
            X.ux.push_back(ux);
            X.u.push_back(uu);
            u=uu;
        }
		cout<<"sum14"<<endl;
    }
	cout<<"sum15"<<endl;
    if (i1<n1)
    {
		cout<<"sum16"<<endl;
        for(N i=i1; i<n1; i++)
        {
			cout<<"sum17"<<endl;
            X.x.push_back(X1.x[i]);
            X.ux.push_back(X1.ux[i]);
        }
		cout<<"sum18"<<endl;
        for(N i=i1; i<n1-1; i++){
			cout<<"sum19"<<endl;            
			X.u.push_back(X1.u[i]);
		}	
    }
    else if (i2<n2)
    {
		cout<<"sum20"<<endl;
        for(N i=i2; i<n2; i++)
        {
			cout<<"sum21"<<endl;
            X.x.push_back(X2.x[i]);
            X.ux.push_back(X2.ux[i]);
        }
        for(N i=i2; i<n2-1; i++){
			cout<<"sum22"<<endl;
            X.u.push_back(X2.u[i]);
		}
    }
    else{
        cout<<"sum23"<<endl;
		X.u.pop_back();
	}
    return X;
}

