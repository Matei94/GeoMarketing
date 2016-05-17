#ifndef __ResizableMatrix_H_
#define __ResizableMatrix_H_

#include <iostream>

using namespace std;

template <typename T>
class ResizableMatrix {
	
	/* array - matricea alocata dinamic */
	T **array;

	/* capacityLines - numarul de linii declarate pentru matrice */
	unsigned long long capacityLines;

	/* capacityCollumns - un vector alocat dinamic in care retin pentru fiecare pozitie i, numarul de coloane declarate pentru linia respectiva */
	unsigned long long *capacityCollumns;

	/* sizeLines - numarul de linii utilizate pana acum din matrice */
	unsigned long long sizeLines;

	/* array[ line ][ 0 ] - sizeCollumns - numarul de coloane utilizate incepand cu indexul 1 pentru fiecare linie */
	
  public:

	/* Constructor default */
	ResizableMatrix();
	
	/* Constructor */
	ResizableMatrix( unsigned long long capacityLines );

	/* Destructor */
	~ResizableMatrix();

	/* Copy-constructor */
	ResizableMatrix( const ResizableMatrix& other );

	/* Supraincarcarea operatorului de asignare */
	void operator=( const ResizableMatrix& other );

	/* Supraincarcarea operatorului de accesare */
	T* operator[]( unsigned long long line );

	/* Metoda care returneaza valoare de pe pozitie */ 
	T getValue( unsigned long long line, unsigned long long collumn );

	/* Functia de extractie a capacity pentru linii*/
	unsigned long long getCapacityLines();

	/* Functia de extractie a capacity pentru linia line (cate coloane au fost alocate pentru linia line) */
	unsigned long long getCapacityCollumns( unsigned long long line );

	/* Functia de extractie a size pentru linii */
	unsigned long long getSizeLines();

	/* Functia de extractie a size pentru coloana collumn (cate coloane au fost utilizate pentru vecini pe linia line) */
	unsigned long long getSizeCollumns( unsigned long long line );

	/* Functia de adaugare pe ultima pozitie */
	void push_back( unsigned long long line, T value );

	/* Functia de insertie la o anumita pozitie in vector */
	void insert( unsigned long long line, T value );

	/* Functia de redimensionare linii */
	void resizeLines();

	/* Functia de redimensionare a liniei line */
	void resizeCollumns( unsigned long long line );

	/* peek-ul ma-tii */
	//T peek( T* aux, unsigned long long collumn );


	/* Functia de afisare a matricei */
	void printOnScreen();
   	
};




#endif /* __ResizableMatrix_H_ */