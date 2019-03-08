#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <fstream>
#include "types.h"

static const char c_eq = 'e', c_lt = 'l', c_gt = 'g', c_no = 'n';
CMP c_and(CMP, CMP);
CMP c_not(CMP);

//min and max for R
R Min(R,R);
R Max(R,R);

//min and max for BR
PR Min(const BR &);
PR Max(const BR &);

//size and dimension functions
N size (const U_IR&);
N dim (const PR&);
N dim (const BR&);

//COMPLEXITY as a function of the dimension of R^d and the size n

//equality
bool operator==(const IR &, const IR &);
bool operator==(const U_IR &, const U_IR &);//O(n)
bool operator==(const PR &, const PR &);//O(d)
bool operator==(const BR &, const BR &);//O(d)

//partial orders
bool operator<=(const IR &, const IR &);//inclusion
bool operator<=(const U_IR &, const U_IR &);//inclusion O(n)
bool operator<=(const PR &, const PR &);//point-wise O(d)
bool operator<=(const BR &, const BR &);//inclusion O(d)

//cover relations
bool operator<=(const IR &, const U_IR &);//O(n), should be O(log n)

//comparison accumulator functions assign to c the c_and of c and cmp(X1,X2)
void cmp_a(const R&, const R&, CMP &c);
void cmp_a(const IR&, const IR&, CMP &c);
void cmp_a(const U_IR&, const U_IR&, CMP &c);//O(n)
void cmp_a(const PR&, const PR&, CMP &c);//O(d)
void cmp_a(const BR&, const BR&, CMP &c);//O(d)

//addition to unions
void add(U_IR&, const IR&);//O(n), but should be O(log n)

//binary union of unions
U_IR operator+(const U_IR &, const U_IR &);//O(n)

//print operators
ostream & operator<<(ostream &, const IR &);
ostream & operator<<(ostream &, const U_IR &);
ostream & operator<<(ostream &, const PR &);
ostream & operator<<(ostream &, const BR &);

//tests that invariants hold
bool ok (const IR&);
bool ok (const U_IR&);//O(n)
bool ok (const PR&);//O(d)
bool ok (const BR&);//O(d)

#endif//FUNCTIONS_H_INCLUDED
