#include <iostream> //for debugging
#include "functions.h"
#include "DAG-hypro.h"

template <typename R>
N DAG_hypro<R>::make(const hypro::Box<R>& B)
{
    /*mybox*/
    vector<carl::Interval<R>> temp=B.boundaries();
    int d = temp.size();
    BR<R> myBox(d);
    for (int j=0; j<d; j++)
    {
        IR<R> interval=IR<R>(temp[j].lower(),temp[j].upper());
        myBox.x[j]=interval;
    }
    return DAG<R>::make(myBox);
}

