Per compilare SENZA HYPRO:

-NON compilare:
	DAG-cover-hypro.tpp
	DAG-make-hypro.tpp

-COMMENTARE in DAG.h i metodi sovraccaricati:
	bool cover(const hypro::Box<R>&,N) const;
	N make(const hypro::Box<R>&);

-COMMENTARE in DAG-h le inclusioni alla fine del file:
	#include "DAG-cover-hypro.tpp"
	#include "DAG-make-hypro.tpp"

-COMMENTARE in types.h le inclusioni:
	#include "representations/GeometricObject.h"
	#include "datastructures/Point.h"
	#include "datastructures/Halfspace.h"
	 

Per compilare CON HYPRO (cmake):

-Buildare in una cartella build il progetto con cmake
-Settare modalità "Debug" con ccmake
-Avviare da /build/bin l'eseguibile myhypro tramite gdb se si vuole avere traccia degli errori.
