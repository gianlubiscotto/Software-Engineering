/**
 * @brief Definition of functions and operators common to multiple files.
 * @file functions.h
 * @author E.Moggi
 * @author G.Ceccoli
 *
 */

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <fstream>
#include "types.h"

static const char c_eq = 'e', c_lt = 'l', c_gt = 'g', c_no = 'n';

/**
 * @brief	Function that makes logic AND between two CMP.
 * @details	If c1 or c2 has value "equal" it returns the other. If one of them has value "not comparable" it returns "not comparable". If c1==c2 it returns c1. If c1 ad c2 have different values ("less then" and "greater then") it returns "not comparable".
 * @param	c1 	The first CMP value.
 * @param 	c2 	The second CMP value.
 * @return 	CMP	The result of AND operation.
 */
CMP c_and(CMP c1, CMP c2);

/**
 * @brief	Function that makes logic NOT of a CMP value.
 * @details	NOT("less than")="greater than". NOT("greater than")="less than". NOT("equal")="equal". NOT("not comparable")="not comparable".
 * @param	c 	The CMP value on which perform NOT operation.
 * @return 	CMP	The result of NOT operation.
 */
CMP c_not(CMP c);

/**
 * @brief	Function that compares two numbers.
 * @details	It returns the smallest value between the two passed as parameters 
 * @param	i 	The first value.
 * @param 	j 	The second value.
 * @tparam	R	The used number type.
 * @return 	R	The smallest between the two.
 */
//min and max for R
template <typename R> 
R Min(R i,R j);

/**
 * @brief	Function that compares two numbers.
 * @details	It returns the largest value between the two passed as parameters 
 * @param	i 	The first value.
 * @param 	j 	The second value.
 * @tparam	R	The used number type.
 * @return 	R	The largest between the two.
 */
template <typename R> 
R Max(R i,R j);

/**
 * @brief	Function that returns the smallest point (vertex) of a BR passed as input.
 * @details	The smallest vertex is computed by collecting all the lower values of each IR in each dimension of the BR.
 * @param	Box	The BR passed as input.
 * @return 	PR	The smallest vertex of the BR.
 */
template <typename R> 
PR<R> Min(const BR<R> & box);

/**
 * @brief	Function that returns the largest point (vertex) of a BR passed as input.
 * @details	The largest vertex is computed by collecting all the upper values of each IR in each dimension of the BR.
 * @param	Box	The BR passed as input.
 * @return 	PR	The largest vertex of the BR.
 */
template <typename R> 
PR<R> Max(const BR<R> & box);

//size and dimension functions
/**
 * @brief	Function that computes the size of the U_IR passed as input.
 * @details	The size is computed by counting how many disjoint IR form the union. 
 * @param	u_ir	The U_IR passed as input.
 * @return 	#N	The size of U_IR::S.
 */
template <typename R> 
N size (const U_IR<R>& u_ir);

/**
 * @brief	Function that computes the dimension of the PR passed as input.
 * @details	The dimension is computed by counting how many coordinates form the point. 
 * @param	point	The PR passed as input.
 * @return 	#N	The size of PR::x.
 */
template <typename R> 
N dim (const PR<R>& point);

/**
 * @brief	Function that computes the dimension of the BR passed as input.
 * @details	The dimension is computed by counting how many IR form the BR. 
 * @param	box	The BR passed as input.
 * @return 	#N	The size of BR::x.
 */
template <typename R> 
N dim (const BR<R>& box);

//COMPLEXITY as a function of the dimension of R^d and the size n

//equality
/**
 * @brief	Equality operator for two IR.
 * @details	Two IR are equal if their IR::l and IR::u are equal between each other.  
 * @param	I1	the first IR.
 * @param	I2	the second IR.
 * @return 	true	if two IR are equal, false otherwise
 */
template <typename R> 
bool operator==(const IR<R> & I1, const IR<R> & I2);

/**
 * @brief	Equality operator for two U_IR.
 * @details	Two U_IR are equal if their U_IR::S are equal between each other.  
 * @param	u_ir1	the first U_IR.
 * @param	u_ir2	the second U_IR.
 * @return 	true	if two U_IR are equal, false otherwise
 */
template <typename R> 
bool operator==(const U_IR<R> & u_ir1, const U_IR<R> & u_ir2);//O(n)

/**
 * @brief	Equality operator for two PR.
 * @details	Two PR are equal if their PR::x are equal between each other.  
 * @param	point1	the first PR.
 * @param	pint2	the second PR.
 * @return 	true	if two PR are equal, false otherwise
 */
template <typename R> 
bool operator==(const PR<R> & point1, const PR<R> & point2);//O(d)

/**
 * @brief	Equality operator for two BR.
 * @details	Two BR are equal if their BR::x are equal between each other.  
 * @param	box1	the first BR.
 * @param	box2	the second BR.
 * @return 	true	if two BR are equal, false otherwise
 */
template <typename R> 
bool operator==(const BR<R> & box1, const BR<R> & box2);//O(d)

//partial orders
/**
 * @brief	Operator for inclusion between two IR.
 * @details	An IR X1 is included in another if the second contains the lower and upper limits of the first. 
 * @param	X1	the first IR.
 * @param	X2	the second IR.
 * @return 	true	if X2.l<=X1.l<=X1.u<=X2.u, false otherwise
 */
template <typename R> 
bool operator<=(const IR<R> &, const IR<R> &);//inclusion

/**
 * @brief	Operator for inclusion between two U_IR.
 * @details	A U_IR X1 is included in another if the second includes all the IR of first. 
 * @param	X1	the first U_IR.
 * @param	X2	the second U_IR.
 * @return 	true	if every IR of X1 is included in any IR of X2. 
 */
template <typename R> 
bool operator<=(const U_IR<R> &, const U_IR<R> &);//inclusion O(n)

/*
template <typename R> 
bool operator<=(const PR<R> &, const PR<R> &);//point-wise O(d)*/

/**
 * @brief	Operator for inclusion between two BR.
 * @details	A BR X1 is included in another if each IR of the second includes each IR of the first. 
 * @param	X1	the first BR.
 * @param	X2	the second BR.
 * @return 	true	if, for every dimension, the IR of X1 related to that dimension is included in the IR related to the same dimension of X2, false otherwise.
 */
template <typename R> 
bool operator<=(const BR<R> & X1, const BR<R> & X2);//inclusion O(d)

/**
 * @brief	Operator for coverage of an IR by a U_IR.
 * @details	An IR I is included in a U_IR U if I is contained in any IR of U. 
 * @param	I	the IR to check.
 * @param	U	the U_IR in which to search for I
 * @return 	true	if I<=U.S[i] for some i, false otherwise
 */
//cover relations
template <typename R> 
bool operator<=(const IR<R> & I, const U_IR<R> &U);//O(n), should be O(log n)

//comparison accumulator functions assign to c the c_and of c and cmp(X1,X2)

/*template <typename R> 
void cmp_a(const R&, const R&, CMP &c);*/

/**
 * @brief	Performs the c_and() between the result of comparison between two IR and CMP passed as parameter.
 * @param	I1 	The first IR.
 * @param 	I2 	The second IR.
 * @param 	c 	The CMP with which perform c_and().
 */
template <typename R> 
void cmp_a(const IR<R>&, const IR<R>&, CMP &c);

/**
 * @brief	Performs the c_and() between the result of comparison between two U_IR and CMP passed as parameter.
 * @param	U1 	The first U_IR.
 * @param 	U2 	The second U_IR.
 * @param 	c 	The CMP with which perform c_and().
 */
template <typename R> 
void cmp_a(const U_IR<R>&, const U_IR<R>&, CMP &c);//O(n)
/*template <typename R> 
void cmp_a(const PR<R>&, const PR<R>&, CMP &c);//O(d)*/

/**
 * @brief	Performs the c_and() between the result of comparison between two BR and CMP passed as parameter.
 * @param	B1 	The first BR.
 * @param 	B2 	The second BR.
 * @param 	c 	The CMP with which perform c_and().
 */
template <typename R> 
void cmp_a(const BR<R>&, const BR<R>&, CMP &c);//O(d)

/**
 * @brief	Function that adds an IR to a U_IR.
 * @details	It selects the right index of U_IR::S where IR should be placed and if not present it adds it. If the new IR connects two previous disjoint IR the three IR merges into one. If the new IR extends a previous IR they merge into one IR as well.   
 * @param	U	the U_IR to which to add the IR.
 * @param	I	the IR to add.
 */
//addition to unions
template <typename R> 
void add(U_IR<R>& U, const IR<R>& I);//O(n), but should be O(log n)

/**
 * @brief	Operator for binary union of U_IR.
 * @details	It scans both U_IR merging they're IR.
 * @param	U1	the first U_IR.
 * @param	U2	the second U_IR.
 * @return 	U_IR	A new U_IR containing the union of the two U_IR
 */
//binary union of unions
template <typename R> 
U_IR<R> operator+(const U_IR<R> &, const U_IR<R> &);//O(n)

//print operators
/**
 * @brief	Print operator for IR.
 * @details	It makes possible to print out an IR in the form: [IR::l,IR::u]
 * @param	I	the IR to print.
 */
template <typename R> 
ostream & operator<<(ostream &, const IR<R> & I);

/**
 * @brief	Print operator for U_IR.
 * @details	It makes possible to print out the sequence of disjoint IR in the form: [IR::l,IR::u]+[IR::l,IR::u]
 * @param	U	the U_IR to print.
 */
template <typename R> 
ostream & operator<<(ostream &, const U_IR<R> & U);

/*
template <typename R> 
ostream & operator<<(ostream &, const PR<R> &);*/

/**
 * @brief	Print operator for BR.
 * @details	It makes possible to print out a BR in form of a cartesian product: [IR::l,IR::u]x[IR::l,IR::u]x...x[IR::l,IR::u]
 * @param	box	the BR to print.
 */
template <typename R> 
ostream & operator<<(ostream &, const BR<R> & box);
/*
//tests that invariants hold

 * @brief	Tests that invariants hold for IR 
 * @details	Checks that IR::l<=IR::u.
 * @param	I	the IR to test
 * @return	true, if invariants hold. False otherwise

template <typename R> 
bool ok (const IR<R>& I);


 * @brief	Tests that invariants for U_IR hold
 * @details	Checks that invariants hold for all the IR inside U_IR::S.
 * @param	U	the U_IR to test
 * @return	true, if invariants hold. False otherwise


template <typename R> 
bool ok (const U_IR<R>& U);//O(n)

 * @brief	Tests that invariants for PR hold
 * @details	Checks that PR::x.size()!=0
 * @param	point	the PR to test
 * @return	true, if invariants hold. False otherwise

template <typename R> 
bool ok (const PR<R>& point);//O(d)

 * @brief	Tests that invariants for BR hold
 * @details	Checks that invariants hold for all the IR inside BR::x
 * @param	box	the BR to test
 * @return	true, if invariants hold. False otherwise

template <typename R> 
bool ok (const BR<R>& box);//O(d)
*/
#endif//FUNCTIONS_H_INCLUDED

