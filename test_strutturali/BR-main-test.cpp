#include <fstream>
#include <iostream>
#include "types.h"
#include "functions.h"

using namespace std;

typedef int R;

int main(){
	//PR::dim()
	PR<R> p(2);
	p.x.push_back(1);
	p.x.push_back(2);
	dim(p);
	//BR::dim()
	BR<R> b(2);
	IR<R> i=IR<R>(1,4);
	IR<R> j=IR<R>(0,6);
	b.x[0]=i;
	b.x[1]=i;
	dim(b);
	//operator==
	if(b==b);
	//operator<=
	BR<R> c(3);
	c.x[0]=i;
	c.x[1]=i;
	c.x[2]=i;
	b<=c;
	b<=b;
	BR<R> b_(2);
	b_.x[0]=j;
	b_.x[1]=j;
	b<=b_;
	b_<=b;
	//cmp_a(BR,BR,CMP)
	CMP f='e';
	cmp_a(b,c,f);
	f='e';
	cmp_a(b,b_,f);
	//Min(BR)
	Min(b);
	//Max(BR)
	Max(b);
	cout<<b<<endl;




	return 0;
}
