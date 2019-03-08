Main for testing purposes:
	test-main.cpp


FORMAT of test files for functions/methods related to DAG:
The program will ask you a testfile as input and an output file where it will write the results.

Each file contains a sequence of lines to act on a vector VUB of N (unions of boxes) and a DAG D. We give the syntax of allowed lines (and their semantics after //), where d denotes an element of type N (the dimension of boxes), and xy denotes a sequence of 2*d elements of type R representing a box of dimension d, e.g. "x0 y0 x1 y1" represents the box [x0,y0]x[x1,y1]:
D d	//creates the DAG D(d), error if this is not the first line in the file
e	//append to VUB the empty union of boxes D.empty()
a xy	//add using make) to VUB[last] the box represented by xy, error if VUB.size<1
c xy	//check if the box represented by xy is covered by VUB[last], error if VUB.size<1
P	//print the entire DAG D
+	//append to VUB the union of VUB[last-1] and VUB[last], error if VUB.size<2
<	//check (using cmp) if VUB[last-1] is included in VUB[last], error if VUB.size<2
