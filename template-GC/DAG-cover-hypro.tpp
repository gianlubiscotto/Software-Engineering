#include <iostream> //for debugging
#include <algorithm> //for sorting
#include "functions.h"
#include "DAG-hypro.h"

template <typename R>
bool DAG_hypro<R>::cover(const hypro::Box<R> &B, N i) const
{
    if (i==0) return false;
    ListN C;//accumulator of non-empty nodes at level l that must cover B
    C.push_back(i);
    /*mybox*/
    vector<carl::Interval<R>> temp=B.boundaries();
    int d = temp.size();
    BR<R> myBox(d);
    for (int j=0; j<d; j++)
    {
        IR<R> interval=IR<R>(temp[j].lower(),temp[j].upper());
        myBox.x[j]=interval;
    }
    return DAG<R>::cover(myBox,i);
}

