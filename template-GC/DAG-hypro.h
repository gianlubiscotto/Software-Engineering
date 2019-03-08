/**
 * @brief Implementation of DAG_hypro.
 *
 * @file DAG-hypro.h
 * @author E.Moggi
 * @author G.Ceccoli
 *
 *
 */
#ifndef DAG_Hypro_INCLUDED
#define DAG_Hypro_INCLUDED

#include <fstream>
#include "types.h"
#include "DAG.h"
#include "representations/GeometricObject.h"
#include "datastructures/Point.h"
#include "datastructures/Halfspace.h"

using namespace std;

/**
 * @brief   The class which represents a DAG compatibile with hypro's types.
 * @details It it an inherited class from DAG but it is able to convert hypro::Box to BR. See class DAG for infos about what a DAG represents.
 * @tparam 	R   The used number type.
 *
 */
template <typename R>
class DAG_hypro : public DAG<R>
{
public:

	/**
	 * @brief	Constructor given a dimension.
	 * @details	See DAG::DAG()
	 * @param	d   The dimension of the space.
	 */
    DAG_hypro(N d) : DAG<R>(d) {};

	/**
	 * @brief	Method that determines if a hypro::Box is covered by a union of boxes inside the DAG-hypro.
	 * @details	First it performs the conversion from hypro::Box passed as parameter to BR and then it calls public method DAG::cover(const BR< R >& box, N i) const.
	 * @param	box	the hypro::Box to check.
	 * @param 	i   the link to the i-th union of boxes inside DAG-hypro.
	 * @return  True, if the IR of each dimension of the BR (converted from a hypro::Box) passed as parameter is included in each U_IR of each dimension of the i-th union of boxes passed as parameter. False otherwise.
	 */
    bool cover(const hypro::Box<R>& box,N i) const;

	/**
	 * @brief	Method that adds to the DAG-hypro a hypro::Box in form of a union of boxes (UBR).
	 * @details	First it performs the conversion from hypro::Box passed as parameter to BR and then it calls public method DAG::make(const BR< R >& box).
	 * @param	box	the hypro::Box to add in form of nodes and leaves.
	 * @return  #N, the link representing the index of the UBR's respective starting Node at the highest level of the DAG-hypro.
	 */
    N make(const hypro::Box<R>& box);
};

#include "DAG-cover-hypro.tpp"
#include "DAG-make-hypro.tpp"


#endif

