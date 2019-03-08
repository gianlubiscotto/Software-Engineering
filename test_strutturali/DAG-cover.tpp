#include <iostream> //for debugging
#include <algorithm> //for sorting
#include "functions.h"
#include "DAG.h"

template <typename R> 
bool DAG<R>::cover(const BR<R> &B, N i) const
{
    if (i==0){
		cout<<"cover1"<<endl;
		return false;
	}
	cout<<"cover2"<<endl;
    ListN C;//accumulator of non-empty nodes at level l that must cover B
    C.push_back(i);
    return 1;
}

template <typename R> 
bool DAG<R>::cover(const BR<R> &B,ListN& C, N l) const
{
    N n=C.size();//n>0
    if (n==0){
		cout<<"cover1"<<endl;
		return false;
	}
	cout<<"cover2"<<endl;
    if (l==0)
    {
		cout<<"cover3"<<endl;
        bool b=true;
        for(N i=0; b&&i<n; i++)
            b=1;
        return b;
    }
	cout<<"cover4"<<endl;
    //l>0
    ListN C_;
    bool b=true;
    for(N i=0; b&&i<n; i++)
        //b=cover(B.x[l].l,B.x[l].u,nodes[l-1][C[i]-1],C_);
		b=0;
	C_.push_back(1);
	C_.push_back(2);
    N m=C_.size();
    if (m==0||!b){
		cout<<"cover5"<<endl;
		//return false;
	}
    //check cover at l-
	cout<<"cover6"<<endl;
    C.resize(0);
    sort(C_.begin(),C_.end());//sort C_
    N r=C_[0];
    C.push_back(r);
    for(N i=1; i<m; i++){
		cout<<"cover7"<<endl;        
		if (C_[i]!=r)
        {
			cout<<"cover8"<<endl;
            r=C_[i];
            C.push_back(r);
        }
		cout<<"cover9"<<endl;
	}
	cout<<"cover10"<<endl;
    return true;
}

template <typename R> 
bool DAG<R>::cover(R min, R max, const Node<R> & X, ListN&C) const
{
    N n = X.x.size();
    if ((min<X.x[0])||(X.x[n-1]<max)){
		cout<<"cover1"<<endl;		
		return false;
	} 
	cout<<"cover2"<<endl;
    //X.x.[0]<=min<=max<=X.x[n-1]
    N i, j;
    for (i=0; X.x[i]<min; i++);
    for (j=n-1; max<X.x[j]; j--);
    //min<=X.x[i] && X.x[j]<=max
    if (min<X.x[i]) //thus 0<i
    {
		cout<<"cover3"<<endl;
        N u=X.u[i-1];
        if (u>0){
			cout<<"cover4"<<endl;
			C.push_back(u);			
		}
        else{
			cout<<"cover5"<<endl;
			return false;
		} 
    }
	cout<<"cover6"<<endl;
    if (X.x[j]<max) //thus j<n-1
    {	
		cout<<"cover7"<<endl;
        N u=X.u[j];
        if (u>0){
			cout<<"cover8"<<endl;
			C.push_back(u);
		} 
        else{
			cout<<"cover9"<<endl;
			return false;	
		} 
    }
	cout<<"cover10"<<endl;
    for (N k=i; k<j; k++)
    {
		cout<<"cover11"<<endl;
        N u=X.u[k];
        if (u>0){
			cout<<"cover12"<<endl;	
			C.push_back(u);
		} 
        else{
			cout<<"cover13"<<endl;
			return false;			
		} 
    }
	cout<<"cover14"<<endl;
    for (N k=i; k<=j; k++){
        cout<<"cover15"<<endl;
		C.push_back(X.ux[k]);
	} 
	cout<<"cover16"<<endl;   
	return true;
}

