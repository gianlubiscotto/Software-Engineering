#include <iostream> //for debugging
#include "functions.h"
#include "DAG.h"

N DAG::make(const hypro::Box<R>& B)
{
	/*mybox*/
	vector<carl::Interval<R>> temp=B.boundaries();
	int d = temp.size();
	BR myBox(d);
	for (int j=0;j<d;j++){
		IR interval=IR(temp[j].lower(),temp[j].upper());	
		myBox.x[j]=interval;
	}

    return make(myBox,dim()-1);
}
