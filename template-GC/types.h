/**
 * @brief Definition of struct IR, U_IR, PR and BR
 *
 * @file types.h
 * @author E.Moggi
 * @author G.Ceccoli
 *
 */

#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <vector>
using namespace std;

/**
* @brief    Typedef for unsigned int.
* @detalis  It represents a link to a node/leaf inside DAG. 
*/
typedef unsigned int N;

/**
* @brief    Typedef for char.
* @details  It can have 4 different meanings: "equal", "not comparable", "less then" and "greater than".
*/
typedef char CMP;

/**
 * @brief   The struct which represents an interval.
 * @details An interval is represented by two values in R [l,u] with l<=u, with inclusion order.
 * @tparam  R   The used number type.
 */
template <typename R>
struct IR
{
	/***************************************************************************
	 * Members
	 **************************************************************************/

    R l; /*!< Lower limit value for the interval.*/
	R u; /*!< Upper limit value for the interval.*/

	/***************************************************************************
	 * Constructors
	 **************************************************************************/

	/**
	 * @brief     Default constructor. Creates an empty interval.
	 */
    IR() {};

	/**
	 * @brief   Creates an interval given the lower and upper values.
	 * @details	It's not important wich one is the lower value and which is the upper because the constructor assign them automatically.
	 * @param	l	lower value
	 * @param	u	upper value		
	 */
    IR(R l,R u);
};

/**
 * @brief   The struct which represents a union of intervals.
 * @details A union of interval is represented by a sequence of disjoint intervals
 * @tparam  R   The used number type.
 */
template <typename R>
struct U_IR
{
	/***************************************************************************
	 * Members
	 **************************************************************************/

    vector<IR <R> > S; /*!< Vector of IR.*/

	/***************************************************************************
	 * Constructors
	 **************************************************************************/

    /**
	 * @brief   Default constructor. Creates an empty union.
	 */
	U_IR() {};
};

/**
 * @brief   The struct which represents a point.
 * @details A point in R^d with d>0, with pointwise order. It consists of a vector
 * of coordinates which forms a point in a n-dimensional space.
 * @tparam  R   The used number type.
 */
template <typename R>
struct PR
{
	/***************************************************************************
	 * Members
	 **************************************************************************/
	
    vector<R> x; /*!< A vector of coordinates.*/
    
	/***************************************************************************
	 * Constructors
	 **************************************************************************/

 	/**
	 * @brief	Constructor given a dimension. 
	 * @details	Create a vector of size d.
	 * @param	d	The dimension of the space.
	 */
	PR(N d)
		{
		    x=vector<R>(d);
		};
};

/**
 * @brief   The struct which represents a box in R^d with d>0, with inclusion order.
 * @details A box is represented by a sequence of IR.
 * @tparam  R     The used number type.
 */
template <typename R>
struct BR
{
	/***************************************************************************
	 * Members
	 **************************************************************************/

    vector<IR <R> > x; /*!< The sequence of IR. One for each dimension.*/
    
	/***************************************************************************
	 * Constructors
	 **************************************************************************/

	/**
	 * @brief	Constructor given a dimension. 
	 * @details	Create a vector of IR of size d.
	 * @param	d	The dimension of the space.
	 */
	BR(N d)
    {
        x=vector<IR <R> >(d);
    };
};


#include "IR.tpp"
#include "UIR.tpp"
#include "basic.tpp"
#include "BR.tpp"


#endif// TYPES_H_INCLUDED


