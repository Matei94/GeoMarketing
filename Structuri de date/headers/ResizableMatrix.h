#ifndef __ResizableMatrix_H_
#define __ResizableMatrix_H_

#include <iostream>

#include "../headers/ResizableArray.h"
#include "../headers/Hashtable.h"

using namespace std;

template <typename T>
class ResizableMatrix {
	
	/* array - matricea alocata dinamic */
	T **array;

	/* capacityLines - numarul de linii declarate pentru matrice */
	int capacityLines;

	/* capacityCollumns - un vector alocat dinamic in care retin pentru fiecare pozitie i, numarul de coloane declarate pentru linia respectiva */
	int *capacityCollumns;

	/* sizeLines - numarul de linii utilizate pana acum din matrice */
	int sizeLines;

	/* array[ line ][ 0 ] - sizeCollumns - numarul de coloane utilizate incepand cu indexul 1 pentru fiecare linie */
	
  public:

	/* Constructor default */
	ResizableMatrix();
	
	/* Constructor */
	ResizableMatrix( int capacityLines );

	/* Destructor */
	~ResizableMatrix();

	/* Copy-constructor */
	ResizableMatrix( const ResizableMatrix& other );

	/* Supraincarcarea operatorului de asignare */
	void operator=( const ResizableMatrix& other );

	/* Supraincarcarea operatorului de accesare */
	T* operator[]( int line );

	/* Metoda care returneaza valoare de pe pozitie */ 
	T getValue( int line, int collumn );

	/* Functia de extractie a capacity pentru linii*/
	int getCapacityLines();

	/* Functia de extractie a capacity pentru linia line (cate coloane au fost alocate pentru linia line) */
	int getCapacityCollumns( int line );

	/* Functia de extractie a size pentru linii */
	int getSizeLines();

	/* Functia de extractie a size pentru coloana collumn (cate coloane au fost utilizate pentru vecini pe linia line) */
	int getSizeCollumns( int line );

	/* Functia de adaugare pe ultima pozitie */
	void push_back( int line, T value );

	/* Functia de insertie la o anumita pozitie in vector */
	void insert( int line, T value );

	/* Functia de redimensionare linii */
	void resizeLines();

	/* Functia de redimensionare a liniei line */
	void resizeCollumns( int line );

	/* peek-ul ma-tii */
	//T peek( T* aux, int collumn );


	/* Functia de afisare a matricei */
	void printOnScreen();

	/* DFS - Parcurgerea in adancime implementata recursiv */
	void DFS( int currentNode, ResizableArray< bool >& visited, NodeArbore& currentArbore, ResizableArray< int >& reverseIdUser, Hashtable< int, infoUser >& mapUsers );
   	
};




#endif /* __ResizableMatrix_H_ */