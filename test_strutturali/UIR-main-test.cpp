#include <fstream>
#include <iostream>
#include "types.h"
#include "functions.h"

using namespace std;

typedef int R;

int main(){
	U_IR<R> uir1;
	U_IR<R> uir2;
	//size()
	uir1.S.size();
	//operator U_IR <= U_IR
	IR<R> I1=IR<R>(1,4);
	IR<R> I2=IR<R>(5,6);
	uir1.S.push_back(I1);
	uir2.S.push_back(I2);
	uir1<=uir2;
	uir2<=uir1;
	uir2.S.clear();
	IR<R> I=IR<R>(0,5);
	uir2.S.push_back(I);
	uir2<=uir1;
	uir1<=uir2;
	//operator == 
	uir1==uir2;
	//cmp_a(U_IR,U_IR,CMP)
	CMP c='n';
	cmp_a(uir1,uir2,c);
	c='e';
	uir1.S.push_back(I2);
	cmp_a(uir1,uir2,c);
	IR<R> i=IR<R>(6,7);
	uir2.S.push_back(i);
	IR<R> j=IR<R>(8,9);
	uir2.S.push_back(j);
	cmp_a(uir1,uir2,c);
	uir1.S.push_back(i);
	uir1.S.push_back(j);
	cmp_a(uir1,uir2,c);
	
	uir1.S.clear();
	uir2.S.clear();
	uir1.S.push_back(I1);
	uir1.S.push_back(I2);
	uir2.S.push_back(I1);
	uir2.S.push_back(I2);
	cmp_a(uir1,uir2,c);

	uir1.S.clear();
	uir2.S.clear();
	
	uir1.S.push_back(I1);
	uir1.S.push_back(I2);
	uir2.S.push_back(I1);
	cmp_a(uir1,uir2,c);

	uir1.S.clear();
	uir2.S.clear();
	uir2.S.push_back(I1);
	uir2.S.push_back(I2);
	uir1.S.push_back(I1);
	cmp_a(uir1,uir2,c);

	uir2.S.clear();
	uir2.S.push_back(I2);
	cmp_a(uir1,uir2,c);
	cmp_a(uir2,uir1,c);
	c='l';
	cmp_a(uir1,uir2,c);
	cout<<endl;
	//operator<<
	uir1.S.clear();
	cout<<uir1<<endl;
	uir2.S.push_back(j);
	cout<<uir2<<endl;
	cout<<endl;
	//add(UIR,IR)
	add(uir1,I1);
	cout<<uir1<<endl;	
	add(uir1,j);
	cout<<uir1<<endl;
	add(uir1,I2);	
	cout<<uir1<<endl;
	IR<R> k=IR<R>(6,9);
	add(uir1,k);	
	cout<<uir1<<endl;
	//operator <= IR
	uir1.S.clear();
	uir1.S.push_back(I1);
	uir1.S.push_back(i);
	j<=uir1;
	I2<=uir1;
	//operator+
	uir1.S.clear();
	uir2.S.clear();
	uir1+uir2;
	uir1.S.push_back(I1);
	uir1+uir2;
	uir1.S.push_back(j);
	IR<R> t=IR<R>(7,10);
	uir2.S.push_back(t);
	IR<R> f=IR<R>(10,11);
	uir1.S.push_back(f);
	IR<R> g=IR<R>(11,12);
	uir2.S.push_back(g);
	uir1+uir2;
	uir2+uir1;
	uir2.S.push_back(I);
	uir2+uir1;
	uir1+uir2;

	return 0;
}
