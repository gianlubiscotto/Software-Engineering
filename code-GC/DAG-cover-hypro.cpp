#include <iostream> //for debugging
#include <algorithm> //for sorting
#include "functions.h"
#include "DAG.h"

bool DAG::cover(const hypro::Box<R> &B, N i) const
{
    	if (i==0) return false;
    	ListN C;//accumulator of non-empty nodes at level l that must cover B
    	C.push_back(i);
	/*mybox*/
	vector<carl::Interval<R>> temp=B.boundaries();
	int d = temp.size();
	BR myBox(d);
	for (int j=0;j<d;j++){
		IR interval=IR(temp[j].lower(),temp[j].upper());
		myBox.x[j]=interval;
	}
    	return cover(myBox,C,dim()-1);
}
