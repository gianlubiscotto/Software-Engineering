#include <algorithm>
#include "types.h"
#include "functions.h"

// NAIVE IMPLEMENTATION: use linear instead of binary search
template <typename R> 
N size (const U_IR<R>& X)
{
    return X.S.size();
}

template <typename R> 
bool operator==(const U_IR<R> & X1, const U_IR<R> & X2)
{
    return X1.S == X2.S;
}
template <typename R> 
bool operator<=(const U_IR<R> & X1, const U_IR<R> & X2)
{
    N n1 =X1.S.size(), n2=X2.S.size();
    N i1=0, i2=0;
    while (i1<n1 && i2<n2)
    {
		cout<<"uir1"<<endl;
        IR<R> I1=X1.S[i1], I2=X2.S[i2];
        if (I1.u<I2.l){
			cout<<"uir2"<<endl;
			return false;
		}        
		else if(I1.l>I2.u){
			cout<<"uir3"<<endl;
			i2++;
		}
        else if (!(I1<=I2)){
			cout<<"uir4"<<endl;
			return false;
		}
        else{
			cout<<"uir5"<<endl;
			i1++;
		}
    }
	cout<<"uir6"<<endl;
    return i1==n1;
}
template <typename R> 
void cmp_a(const U_IR<R> & X1, const U_IR<R> & X2, CMP & c)
{
    if (c==c_no){
		cout<<"cmp_a1"<<endl;
		return;	
	} 
	cout<<"cmp_a2"<<endl;
    N n1 =X1.S.size(), n2=X2.S.size();
    N i, n;
    if (n1<n2){
		cout<<"cmp_a3"<<endl;	
		n=n1;
	} 
    else{
		cout<<"cmp_a4"<<endl; 
		n=n2;
	}
    for (i = 0; i < n && X1.S[i]==X2.S[i]; i++);
    if (i==n)
    {
		cout<<"cmp_a5"<<endl;
        if (n1<n2){
			cout<<"cmp_a6"<<endl;		
		} 
        else if(n1>n2) {
			cout<<"cmp_a7"<<endl;
		} 
        return;
    }
	cout<<"cmp_a8"<<endl;
    //i<n
    N i1=i, i2=i;
    while (c!=c_no && i1<n1 && i2<n2)
    {
		cout<<"cmp_a9"<<endl;
        IR<R> I1=X1.S[i1], I2=X2.S[i2];
        if (I1.u<I2.l)
        {
			cout<<"cmp_a10"<<endl;
            i1++;
        }
        else if (I1.l>I2.u)
        {
			cout<<"cmp_a11"<<endl;
            i2++;
        }
        else
        {
			cout<<"cmp_a12"<<endl;
            //cmp_a(I1,I2,c);
            if (I1.u<I2.u){ 
				cout<<"cmp_a13"<<endl;				
				i1++;
			}
            else if (I1.u>I2.u) {
				cout<<"cmp_a14"<<endl;
				i2++;
			}
            else
            {
				cout<<"cmp_a15"<<endl;
                i1++;
                i2++;
            }
        }
    }
	c=c_and(c,c_gt);
	cout<<"cmp_a16"<<endl;
    if (c==c_no){ 
		cout<<"cmp_a17"<<endl;
		return;
	}
    if (n1 < n2){
		cout<<"cmp_a18"<<endl;	
		//c = c_and(c, c_lt);
	}
        
    else if (n1 > n2){
		cout<<"cmp_a19"<<endl;
        c = c_and(c, c_gt);
	}
	cout<<"cmp_a20"<<endl;    
	return;
}
template <typename R> 
ostream & operator<<(ostream & stream, const U_IR<R> & X)
{
    N n = X.S.size();
    if (n == 0)
        stream << "0";
    else
    {
        stream << X.S[0];
        for (N i = 1; i < n; i++)
            stream << "+" << X.S[i];
    }
    return stream;
}
template <typename R> 
void add(U_IR<R> &U, const IR<R> & I)
{
    N n = U.S.size();
    if (n==0)
    {
        U.S.push_back(I);
        return;
    }
    R l=I.l, u=I.u;
    if (U.S[n-1].u<l)
    {
        U.S.push_back(I);
        return;
    }
    typename vector < IR <R> >::iterator it = U.S.begin();

    N i, j;
    for (i=0; U.S[i].u<l; i++);
    //smallest i st l<=U.S[i].u
    if (u<U.S[i].l)
    {
        U.S.insert(it+i,I);
        return;
    }
    U.S[i].l=Min(l,U.S[i].l);
    //U.S[i].l<=u
    for (j=i+1; j<n &&U.S[j].l<=u; j++);
    U.S[i].u=Max(u,U.S[j-1].u);
    U.S.erase(it+i+1,it+j);
}
template <typename R> 
bool operator<=(const IR<R> & I, const U_IR<R> & U)
{
    R l=I.l;
    N n = U.S.size(), i;
    for (i=0; i<n&&U.S[i].u<l; i++);
    if (i == n){
		return false;
	} 
    //smallest i st l<=U.S[i].u
    else{
		return I<=U.S[i];
	} 
}
template <typename R> 
U_IR<R> operator+(const U_IR<R> &U1, const U_IR<R> &U2)
{
    U_IR<R> U;
    N n1=size(U1), n2=size(U2);
    if (n1==0){ 
		cout<<"+1"<<endl;	
		U=U1;
	}
    else if (n2==0){
		cout<<"+2"<<endl;
		U=U2;
	}
    else
    {
		cout<<"+3"<<endl;
        N i1=0, i2=0;
        IR<R> I1=U1.S[i1], I2=U2.S[i2];
        while (i1<n1 && i2<n2)
            if (I1.u<I2.l)
            {
				cout<<"+4"<<endl;
                U.S.push_back(I1);
                i1++;
                if (i1<n1){
					cout<<"+5"<<endl;
					I1=U1.S[i1];
				}
            }
            else if (I2.u<I1.l)
            {
				cout<<"+6"<<endl;
                U.S.push_back(I2);
                i2++;
                if (i2<n2){
					cout<<"+7"<<endl;
					I2=U2.S[i2];
				}
            }
            else if (I1.u<I2.u)
            {	
				cout<<"+8"<<endl;
                I2.l=Min(I1.l,I2.l);
                i1++;
                if (i1<n1){
					cout<<"+9"<<endl;
					I1=U1.S[i1];
				}
            }
            else
            {
				cout<<"+10"<<endl;
                I1.l=Min(I1.l,I2.l);
                i2++;
                if (i2<n2){
					cout<<"+11"<<endl;
					I2=U2.S[i2];
				}
            };
        if (i1<n1)
        {
			cout<<"+12"<<endl;
            U.S.push_back(I1);
            for (i1++; i1<n1; i1++){
				cout<<"+13"<<endl;
                U.S.push_back(U1.S[i1]);
			}
        }
        else
        {
			cout<<"+14"<<endl;
            U.S.push_back(I2);
            for (i2++; i2<n2; i2++){
				cout<<"+15"<<endl;
                U.S.push_back(U2.S[i2]);
        	}
		}
    }
    return U;
}

