#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

template <typename R> 
CMP DAG<R>::cmp(N i1,N i2)
{
    return 'e';
}

template <typename R> 
CMP DAG<R>::cmp(N i1,N i2,N l)
{
    if (i1<i2)
    {
		cout<<"cmp1"<<endl;
        if (i1==0){
			cout<<"cmp3"<<endl;
			return c_lt;
		}
        else{
			cout<<"cmp4"<<endl;
			return 'e';
		} 
    }
    else if (i1==i2){
		cout<<"cmp5"<<endl;
		return c_eq;
	} 
    else  if (i2==0){
		cout<<"cmp7"<<endl;
		return c_gt;
	} 
	cout<<"cmp8"<<endl;
    //i1>i2>0
    i1--;
    i2--;
    if (C[l][i1][i2]!='?'){
		cout<<"cmp9"<<endl;
        return C[l][i1][i2];
	}
	cout<<"cmp10"<<endl;
    C[l][i1][i2]=c_eq;
    if (l==0){
		cout<<"cmp11"<<endl;
        //cmp_a(leaf[i1],leaf[i2],C[l][i1][i2]);
	}
    else{
		cout<<"cmp12"<<endl;
       // cmp(nodes[l-1][i1],nodes[l-1][i2],C[l][i1][i2],l-1);
	}
	cout<<"cmp13"<<endl;
    return C[l][i1][i2];
}

template <typename R> 
void DAG<R>::cmp(const Node<R> & X1, const Node<R> & X2, CMP & c, N l)
{
    N n1 = X1.x.size(), n2 = X2.x.size();
    N i1 = 0, i2 = 0, u1 = 0, u2 = 0, ux1 = X1.ux[0], ux2 = X2.ux[0];
    R x1=X1.x[i1], x2=X2.x[i2];
    while (c != c_no && i1 < n1 && i2 < n2)
    {
		cout<<"cmp1"<<endl;
        if (x1 < x2)
        {	
			cout<<"cmp2"<<endl;
            //c=c_and(c,cmp(ux1,u2,l));
            i1++;
            if (i1 < n1)
            {
				cout<<"cmp3"<<endl;
                u1 = X1.u[i1 - 1];
                ux1 = X1.ux[i1];
                x1=X1.x[i1];
            }
            else{
				cout<<"cmp4"<<endl;
                u1 = 0;
			}
        }
        else if (x1 > x2)
        {
			cout<<"cmp5"<<endl;
            //c=c_and(c,cmp(u1,ux2,l));
            i2++;
            if (i2 < n2)
            {
				cout<<"cmp6"<<endl;
                u2 = X2.u[i2 - 1];
                ux2 = X2.ux[i2];
                x2=X2.x[i2];
            }
            else{
				cout<<"cmp7"<<endl;
                u2 = 0;
			}
        }
        else
        {
			cout<<"cmp8"<<endl;
            //c=c_and(c,cmp(ux1,ux2,l));
            i1++;
            if (i1 < n1)
            {
				cout<<"cmp9"<<endl;
                u1 = X1.u[i1 - 1];
                ux1 = X1.ux[i1];
                x1=X1.x[i1];
            }
            else{
				cout<<"cmp10"<<endl;                
				u1 = 0;
			}
            i2++;
            if (i2 < n2)
            {	
				cout<<"cmp11"<<endl;
                u2 = X2.u[i2 - 1];
                ux2 = X2.ux[i2];
                x2=X2.x[i2];
            }
            else{
				cout<<"cmp12"<<endl;                
				u2 = 0;
			}
        }
        //c=c_and(c,cmp(u1,u2,l));
    }
	cout<<"cmp13"<<endl;
    if (c == c_no){
		cout<<"cmp14"<<endl;
        return;
	}
	cout<<"cmp15"<<endl;
    if (i1 == n1 && i2 == n2){
		cout<<"cmp16"<<endl;
        return;
	}
	cout<<"cmp17"<<endl;
    if (i1 < n1){
		cout<<"cmp18"<<endl;
        //c = c_and(c, c_gt);
	}
    else{
		cout<<"cmp19"<<endl;
        //c = c_and(c, c_lt);
	}
}

