#include <fstream>
#include <iostream>
#include "types.h"
#include "functions.h"

using namespace std;

typedef int R;

int main(){
	//min(R,R)
	Min(2,3);
	Min(3,2);
	//max(R,R)
	Max(2,3);
	Max(3,2);
	//c_not(CMP)
	CMP c='e';
	c_not(c);
	c='l';
	c_not(c);
	c='g';
	c_not(c);
	c='n';
	c_not(c);
	//c_and(CMP,CMP)
	CMP c_='n';
	c_and(c,c_);
	c='e';
	c_and(c,c_);
	c_='e';
	c_and(c,c_);
	c='l';
	c_and(c,c_);
	c_='l';
	c_and(c,c_);
	c='g';
	c_and(c,c_);


	return 0;
}
