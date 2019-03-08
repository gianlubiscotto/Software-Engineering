#include <fstream>
#include <iostream>
#include "types.h"
#include "functions.h"
#include "DAG-test.h"
using namespace std;

typedef int R;

int main(){
	
//brach di DAG.tpp
	//DAG::DAG()
	DAG_test<R> G(0);
	DAG_test<R> Dag(2);
	cout<<endl;
	//DAG::dim()
	Dag.dim();
	cout<<endl;
	//DAG::empty()
	Dag.empty();
	cout<<endl;
	
	//DAG::add_leaf()
	Leaf<R> L;
	Dag.add_leaf(L);
	IR<R> I=IR<R>(1,4);
	L.S.push_back(I);
	Dag.add_leaf(L);
	IR<R> I_=IR<R>(5,6);
	L.S.push_back(I_);
	Dag.add_leaf(L);
	cout<<endl;
	Dag.print_test(cout);
	
	//DAG::add_node()
	Node<R> Q;
	Dag.add_node(Q,0);
	Dag.add_node(Q,1);
	Q.x.push_back(1);
	Q.x.push_back(4);
	Q.u.push_back(1);
	Q.ux.push_back(1);
	Q.ux.push_back(1);
	Dag.add_node(Q,1);
	Q.x.clear();
	Q.x.push_back(5);
	Q.x.push_back(6);
	Dag.add_node(Q,1);
	Dag.add_node(Q,1);
	cout<<endl;
	//operatore <<Node<R>
	cout<<Q<<endl;
	cout<<endl;
	
	//creo una box per make e cover
	IR<R> I1=IR<R>(1,4);
	IR<R> I2=IR<R>(1,4);	
	BR<R> box(2);
	box.x[0]=I1;
	box.x[1]=I2;
	
//branch di DAG-make.tpp
	//DAG::make(BR)
	Dag.make(box);
	cout<<endl;
	//DAG::make(BR,N)
	Dag.make(box,0);	
	Dag.make(box,1);
	cout<<endl;

//branch di DAG-cover.tpp	
	//DAG::cover(BR,N)
	Dag.cover(box,0);	
	Dag.cover(box,1);
	cout<<endl;
	//DAG::cover(BR,ListN,N)
	ListN C;
	Dag.cover(box,C,0);
	C.push_back(1);
	Dag.cover(box,C,0);
	Dag.cover(box,C,1);
	cout<<endl;
	//DAG::cover(R,R,Node,ListN)
	Node<R> X;
	X.x.push_back(5);
	Dag.cover(1,3,X,C);
	Node<R> Y;
	Y.x.push_back(1);
	Y.x.push_back(5);
	Y.u.push_back(1);
	Dag.cover(2,3,Y,C);
	Y.u.pop_back();
	Y.u.push_back(0);
	Dag.cover(2,3,Y,C);
	Node<R> Z;
	Z.x.push_back(1);
	Z.x.push_back(2);
	Z.x.push_back(5);
	Z.u.push_back(0);
	Dag.cover(2,4,Z,C);
	
	Z.x.pop_back();
	Z.x.push_back(4);
	Z.x.push_back(5);
	Dag.cover(2,4,Z,C);

	Z.u.pop_back();
	Z.u.push_back(1);
	Z.u.push_back(1);
	Z.ux.push_back(1);
	Dag.cover(2,4,Z,C);
	cout<<endl;

//branch di DAG-cmp.tpp
	//DAG::cmp(N,N)	
	Dag.cmp(1,2);
	//DAG::cmp(N,N,N)
	Dag.cmp(0,2,0);
	Dag.cmp(1,2,0);
	Dag.cmp(2,2,0);
	Dag.cmp(2,0,0);
	Dag.C.resize(2);
	Dag.C[0].resize(4);
	Dag.C[0][2].resize(3);
	Dag.C[0][2][1]='e';
	Dag.cmp(3,2,0);
	Dag.C[0][2][1]='?';
	Dag.cmp(3,2,0);
	Dag.C[1].resize(4);
	Dag.C[1][2].resize(3);
	Dag.C[1][2][1]='?';
	Dag.cmp(3,2,1);
	cout<<endl;
	//DAG::cmp(Node,Node,CMP,N)
	Node<R> N1;
	Node<R> N2;
	CMP c='e';
	N1.x.push_back(1);
	N1.ux.push_back(1);
	N1.u.push_back(1);
	N1.x.push_back(2);
	N1.ux.push_back(1);
	
	N2.x.push_back(3);
	N2.ux.push_back(1);
	Dag.cmp(N1,N2,c,1);
	
	N1.x.clear();
	N1.x.push_back(4);	
	N2.u.push_back(1);	
	N2.x.push_back(3);
	N2.ux.push_back(1);
	Dag.cmp(N1,N2,c,1);

	N2.x.clear();
	N2.x.push_back(4);
	N2.x.push_back(3);
	N1.x.push_back(3);	
	Dag.cmp(N1,N2,c,1);
	c='n';
	Dag.cmp(N1,N2,c,1);
	cout<<endl;

//branch di DAG-sum.tpp
	//DAG::sum(N,N)	
	Dag.sum(1,2);
	//DAG::sum(N,N,N)
	Dag.sum(0,0,0);
	Dag.sum(1,0,0);	
	Dag.sum(1,1,0);
	Dag.U.resize(2);
	Dag.U[0].resize(2);
	Dag.U[0][1].resize(2);
	Dag.U[0][1][0]=2;
	Dag.sum(1,2,0);
	Dag.U[0][1][0]=0;
	Dag.sum(2,1,0);
	Dag.U.resize(2);
	Dag.U[1].resize(2);
	Dag.U[1][1].resize(2);
	Dag.U[1][1][0]=2;
	Dag.U[1][1][0]=0;
	Dag.sum(2,1,1);
	cout<<endl;
	//DAG::sum(Node,Node,N)
	Node<R> N1_;
	Node<R> N2_;
	N1_.x.push_back(1);
	N1_.ux.push_back(1);
	N1_.u.push_back(1);
	N1_.x.push_back(2);
	N1_.ux.push_back(1);
	
	N2_.x.push_back(3);
	N2_.ux.push_back(1);
	Dag.sum(N1_,N2_,1);
	
	N1_.x.clear();
	N1_.x.push_back(4);	
	N2_.u.push_back(1);	
	N2_.x.push_back(3);
	N2_.ux.push_back(1);
	Dag.sum(N1_,N2_,1);

	N2_.x.clear();
	N2_.x.push_back(4);
	N2_.x.push_back(3);
	N1_.x.push_back(3);	
	Dag.sum(N1_,N2_,1);

	N2_.x.clear();
	N1_.x.clear();
	N1_.x.push_back(1);
	N2_.x.push_back(2);
	N2_.x.push_back(3);
	Dag.sum(N1_,N2_,1);
	
	N2_.x.clear();
	N1_.x.clear();
	N2_.x.push_back(1);
	N1_.x.push_back(2);
	N1_.x.push_back(3);
	Dag.sum(N1_,N2_,1);
	


	return 0;
}

