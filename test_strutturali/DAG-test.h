#include <fstream>
#include "types.h"
#include "DAG.h"
using namespace std;

template <typename R>
class DAG_test : public DAG<R>
{
public:
    using DAG<R>::cover;
    using DAG<R>::make;
	using DAG<R>::add_leaf;
	using DAG<R>::add_node;
	using DAG<R>::sum;
	using DAG<R>::print_test;
	using DAG<R>::cmp;
	using DAG<R>::C;
	using DAG<R>::U;
    DAG_test(N d) : DAG<R>(d) {};
	
};
