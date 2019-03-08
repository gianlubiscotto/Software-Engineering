/**
 * @brief Implementation of the DAG.
 *
 * @file DAG.h
 * @author E.Moggi
 * @author G.Ceccoli
 *
 *
 */

#ifndef DAG_H_INCLUDED
#define DAG_H_INCLUDED

#include <fstream>
#include "types.h"
using namespace std;

/**
* @brief    Typedef for U_IR.
* @detalis  It represents a union of intervals at level 0 of the DAG.
* @tparam   R   The used number type. 
*/
template <typename R>
using Leaf=U_IR<R>;
//typedef U_IR<R> Leaf;//non-empty leaf in DAG

/**
* @brief    Typedef for a vector of type #N.
* @detalis  It will be used to store nodes' links.
*/
typedef vector<N> ListN;

/**
 * @brief 	The struct which represents a node inside the DAG.
 * @details	A node is represented by a vector of points of discontinuity and links to other nodes/leaves to a lower level of the DAG.
 * @details	A Node with its attributes represents a union of boxes (UBR). 			
 * @tparam	R   The used number type.
 * 
 */
template <typename R>
struct Node//non-empty node in DAG
{
	/***************************************************************************
	 * Members
	 **************************************************************************/

    vector < R > x; /*!< @brief Increasing sequence in R of points of discontinuity of size #n>0 
						@details Each element of #x represents a point of discontinuity of a union of boxes (UBR) along one dimension.*/
    ListN ux;/*!< @brief Sequences of #n links to level below in DAG 
				@details Every link represent the index of a Node / #Leaf at level below associated with a point of discontinuity.*/
    ListN u; /*!< @brief Sequences of #n-1 links to level below in DAG
				@details Every link represent the index of a Node / #Leaf at level below associated with an interval between two points of discontinuity.*/

	/**
	 * @brief	Comparison operator between two nodes.
	 * @details	Two Node are equal if all their attributes are equal to each other.
	 * @param	X1	The first Node.
	 * @param	X2	The second Node.
	 * @return	True, if all X1's attributes are equal to X2's attributes.
	 */
    friend bool operator==(const Node<R>&X1, const Node<R>&X2)
    {
        return X1.x==X2.x &&X1.ux==X2.ux &&X1.u==X2.u;
    };
};

/**
* @brief    Typedef for vector< Leaf<R> >.
* @detalis  It represents a set of nodes(leaves) at level 0 in DAG.
* @tparam   R   The used number type. 
*/
template <typename R>
using Leaves=vector < Leaf<R> >;
//typedef vector < Leaf<R> > Leaves;//set of nodes(leaves) at level 0 in DAG

/**
* @brief    Typedef for vector< Node<R> >.
* @detalis  It represents a set of nodes at the same level inside the DAG.
* @tparam   R	The used number type. 
*/
template <typename R>
using Nodes=vector<Node <R> >;
//typedef vector < Node<R> > Nodes;//set of nodes at a given level in DAG

/**
 * @brief   The class which represents a DAG.
 * @details A DAG is a container of Node and Leaf so a container for union of boxes (UBR).
 * @details DAG stores unions of boxes in n-dimensional space as n levels in which level 0 is always reserved for leaves. 
 * @tparam 	R   The used number type.
 * 
 */
template <typename R>
class DAG
{
	/***************************************************************************
	* Members
	**************************************************************************/
protected:

    Leaves<R> leaf;  /*!< Set of non-empty nodes at level 0 (leaves). DAG empty if number of leaf=0 */
    vector < Nodes<R> > nodes;/*!< Matrix of Node. #nodes[l] set of non-empty Node at level l */
    //memoization
    vector<vector <vector <CMP> > > C; /*!< #C[l][j][i] comparison of i and j at level l, with i<j ('?' if not computed yet)*/
    vector<vector <vector <N> > > U; /*!< #U[l][j][i] result of union of i and j  at level l, with i<j (0 if not computed yet)*/
    
	N add_leaf(const Leaf<R>&);//prevent duplication
    N add_node(const Node<R>&, N l);//prevent duplication
    bool cover(const BR<R>&,ListN&,N l) const;
    bool cover(R,R,const Node<R>&,ListN&) const;
    CMP cmp(N,N,N l);//comparison of nodes at level l
    void cmp(const Node<R> &, const Node<R> &, CMP &, N l);
    N make(const BR<R>&,N l);//make at level l
    N sum(N,N,N l);//union of nodes at level l
    Node<R> sum(const Node<R> & X1, const Node<R> & X2, N l);
public:
	/**
	 * @brief	Constructor given a dimension. 
	 * @details	Resizes #nodes to a matrix with d-1 lines and #C and #U to vectors of dimension d.
	 * @details	#nodes is resized to d-1 because a union of boxes of dimension n has n levels but just n-1 of them are reserved for Nodes. The lower level has only Leaves.
	 * @details If d=0 the constructor returns a "bad initialization" error. 
	 * @param	d	The dimension of the space.
	 */
    DAG(N d);//dimension d>0

    //void print() const;//print DAG (for debug purposes)
	
	/**
	 * @brief	Function able to print out the structure of the DAG 
	 * @details	Starting from the bottom it prints all the Leaf at level 0 and then all the Node at level>0
	 * @param	cout	The output stream you want to print on.
	 */
    void print_test(ostream &cout) const;//print for testing

    //void print2(N) const;//print subsets of the plane with integer bounds
	
	/**
	 * @brief	Compute the height of the DAG.
	 * @details	The height of the DAG corresponds to the number of levels. It corresponds also to the size of the n-dimensional space of the union of boxes stored inside DAG.
	 * @return	#N, Levels of the DAG.
	 */
    N dim() const;

	/**
	 * @brief	Returns a link to the empty union of boxes.
	 * @return	0, Link to the empty union of boxes.
	 */
    N empty() const;

	/**
	 * @brief	Method that determines if a box is covered by a union of boxes inside the DAG
	 * @details	It checks if the box passed as parameter is included in the union of boxes identified by the parameter link i.
	 * @param	box	the BR to check.
	 * @param 	i	the link to the i-th union of boxes inside DAG.
	 * @return  True, if the IR of each dimension of the BR passed as parameter is included in each U_IR of each dimension of the i-th union of boxes passed as parameter. False otherwise.
	 */
    bool cover(const BR<R>& box,N i) const;

	/**
	 * @brief	Method that compares two union of boxes.
	 * @details	It can return the meaning of "less than" or "greater than" and this is associated to the first parameter. 
	 * @param	i 	the link to the i-th union of boxes inside DAG.
	 * @param 	j 	the link to the j-th union of boxes inside DAG.
	 * @return  #CMP, that states for less than, greater than, equal, not comparable.
	 */
    CMP cmp(N i,N j);
	
	/**
	 * @brief	Method that adds to the DAG a BR in form of a union of boxes (UBR).
	 * @details	It adds recursively from level 0 to top level at most one Node (or a #Leaf if level=0) if it doesn't exist yet.  
	 * @param	box	the BR to add in form of nodes and leaves.
	 * @return  #N, the link representing the index of the UBR's respective starting Node at the highest level of the DAG.
	 */
    N make(const BR<R>& box);

	/**
	 * @brief	Method that merges two union of boxes from inside the DAG.
	 * @details	It joins each Node and #Leaf of the two UBRs.
	 * @param	i 	the link of the first UBR.
	 * @param	j 	the link of the second UBR.
	 * @return	#N	the link of the resulting union.
	 */
    N sum(N i,N j);
};

#include "DAG.tpp"
#include "DAG-sum.tpp"
#include "DAG-cover.tpp"
#include "DAG-make.tpp"
#include "DAG-cmp.tpp"


#endif	// DAG_H_INCLUDED


