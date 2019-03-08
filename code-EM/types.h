#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <vector>
using namespace std;

//natural numbers
typedef unsigned int N;

//lattice c_no<c_lt,c_gt<c_eq of comparison results in a PO
typedef char CMP;

//any type with a linear order
typedef float R;

//intervals [l,u] in R with l<=u, with inclusion order
struct IR
{
  R l, u;
  IR() {};
  IR(R,R);
};

//unions of intervals (increasing sequence of disjoint intervals)
struct U_IR
{
  vector<IR> S;
  U_IR() {};
};

//points in R^d with d>0, with pointwise order
struct PR
{
    vector<R> x;
  PR(N d){ x=vector<R>(d);};
};

//boxes in R^d with d>0, with inclusion order
struct BR
{
    vector<IR> x;
  BR(N d){ x=vector<IR>(d);};
};

#endif// TYPES_H_INCLUDED
