#include <iostream>

using namespace std;
#include "../headers/Hashtable.h"
#include "../headers/NodeArbore.h"
#include "../headers/ResizableMatrix.h"
#include "../headers/Hashtable.h"


using namespace std;

template <typename T>
ResizableMatrix<T>::ResizableMatrix() {
	
	/* Set capacity for both lines and collumns */
	this->capacityLines = 1;
	this->capacityCollumns = new int[ capacityLines ];

	/* Set initial size for both lines and collumns */
 	this->sizeLines = 0;

 	/* Allocate memory for all lines */
	this->array = new T*[ capacityLines ];

	/* Allocate memory for all collumns */
	for( int i = 0; i < capacityLines; ++i ) {

		/* Aloc un vector de cate un element pentru fiecare linie */
		array[i] = new T[1];

		capacityCollumns[i] = 1;

		/* Ma asigur ca e pe zero numarul de pozitii ocupate in fiecare linie */
		array[i][0] = 0;
	}

}


template <typename T>	
ResizableMatrix<T>::ResizableMatrix( int capacityLines ) {

	/* Set capacity for both lines and collumns */
	this->capacityLines = capacityLines + 1;
	this->capacityCollumns = new int[ capacityLines ];

	/* Set initial size for both lines and collumns */
 	this->sizeLines = 0;

 	/* Allocate memory for all lines */
	this->array = new T*[ capacityLines ];

	/* Allocate memory for all collumns */
	for( int i = 0; i < capacityLines; ++i ) {

		/* Aloc un vector de cate un element pentru fiecare linie */
		array[i] = new T[1];

		capacityCollumns[i] = 1;

		/* Ma asigur ca e pe zero numarul de pozitii ocupate in fiecare linie */
		array[i][0] = 0;
	}

}


template <typename T>
ResizableMatrix<T>::~ResizableMatrix(){

	/* De-Allocate memory for collumns */
	for ( int i = 0; i < capacityLines; ++i )
		delete[] array[i];

	/* De-Allocate memory for the matrix itself */
	delete[] array;
	delete[] capacityCollumns;
}


template <typename T>
ResizableMatrix<T>::ResizableMatrix( const ResizableMatrix& other ) {

	this->capacityLines = other.capacityLines;

	this->capacityCollumns = other.capacityCollumns;
	for ( int i = 0; i < capacityLines; ++i )
		capacityCollumns[i] = other.capacityCollumns[i];

	this->sizeLines = other.sizeLines;

	this->array = other.array;

	if( array ) {
		for( int i = 0; i < capacityLines; ++i ) {
			for( int j = 0; j <= array[i][0]; ++j )
				array[i][j] = other.array[i][j];
		}
	}

}


template <typename T>
void ResizableMatrix<T>::operator=( const ResizableMatrix& other ) {

	this->capacityLines = other.capacityLines;

	this->capacityCollumns = other.capacityCollumns;
	for ( int i = 0; i < capacityLines; ++i )
		capacityCollumns[i] = other.capacityCollumns[i];

	this->sizeLines = other.sizeLines;

	this->array = other.array;

	if( array ) {
		for( int i = 0; i < capacityLines; ++i ) {
			for( int j = 0; j <= array[i][0]; ++j )
				array[i][j] = other.array[i][j];
		}
	}

}


template <typename T>
T* ResizableMatrix<T>::operator[]( int line ) {

	if(line >= capacityLines) {
		cout << "Boss, nu esti in zona de memorie buna.\n";
		return T();
	}

	return array[ line ];
}


template <typename T>
T ResizableMatrix<T>::getValue( int line, int collumn ) {
	return array[ line ][ collumn ];
}

template <typename T>
int ResizableMatrix<T>::getCapacityLines() {
	return capacityLines;
}


template <typename T>
int ResizableMatrix<T>::getCapacityCollumns( int line ) {
	return capacityCollumns[ line ];
}


template <typename T>
int ResizableMatrix<T>::getSizeLines() {
	return sizeLines;
}


template <typename T>
int ResizableMatrix<T>::getSizeCollumns( int line ) {
	return array[line][0];
}


template <typename T>
void ResizableMatrix<T>::push_back( int line, T value ) {
	
	/* Verific daca mai am spatiu alocat pentru insertia curenta */
	if (array[line][0] + 1 == capacityCollumns[line]) {
		//cout<<"pula\n, cred ca intra in resize collums\n";
 		this->resizeCollumns( line );
	}

	/* Adaug elementul la finalul vectorului si incrementez size-ul de coloane pentru linia curenta */
	array[ line ][ ++array[line][0] ] = value;

}


template <typename T>
void ResizableMatrix<T>::insert( int line, T value ) {
	
	/* Daca linia la care vreau sa inserez nu exista deja, maresc numarul de linii al matricei */
	if (line >= capacityLines) 
		this->resizeLines();

	/* Insertia efectiva */
	this->push_back( line, value );

}


template <typename T>
void ResizableMatrix<T>::resizeLines( ) {

	/* Aloc o matrice noua cu numar dublu de linii */
	T **tmpArray = new T*[ 2*capacityLines ];

	int *tmpCapacityCollumns = new int[ 2*capacityLines ];

	/* Copiez capacityCollumns din vechea matrice in cea noua */
	for ( int i = 0; i < capacityLines; ++i )
		tmpCapacityCollumns[i] = capacityCollumns[i];

	/* Initializam numarul de coloane pentru fiecare dintre noile linii alocate */
	for( int i = capacityLines; i < 2 * capacityLines; ++i )
		tmpCapacityCollumns[i] = 1;

	/* Alocam numarul de coloane pentru fiecare linie in parte */
	for( int i = 0; i < 2*capacityLines; ++i ) {
		tmpArray[ i ] = new T[ tmpCapacityCollumns[i] ];
	}

	/* Copiez elementele din matricea veche in cea temporara */
	for ( int i = 0; i < capacityLines; ++i ) {
		for ( int j = 0; j <= array[i][0]; ++j )
			tmpArray[ i ][ j ] = array[ i ][ j ];
	}

	/* Initializez indexul pozitiei curente de la linia i */
	for( int i = capacityLines; i < 2* capacityLines; ++i )
		tmpArray[ i ][ 0 ] = 0;

	/* Eliberez memoria ocupata de vechea matrice */
	for ( int i = 0; i < capacityLines; ++i )
		delete[] array[i];

	delete[] array;
	delete[] capacityCollumns;

	/* Salvez matricea nou alocata in matricea veche, si fac update la capacity */
	array = tmpArray;
	capacityCollumns = tmpCapacityCollumns;
	capacityLines = 2 * capacityLines;

}


template <typename T>
void ResizableMatrix<T>::resizeCollumns( int line ) {

	/* Aloc o linie cu numar dublu de coloane */
	T *tmpArray = new T[ 2*capacityCollumns[ line ] ];

	/* Copiez valorile din vechea linie in noua linie */
	for ( int i = 0; i < capacityCollumns[line]; ++i )
		tmpArray[i] = array[line][i];
	
	delete[] array[ line ];

	/* Salvez linia nou alocata in vechea linie si fac update la capacity */
	array[line] = tmpArray;
	capacityCollumns[line] *= 2;

}


template <typename T>
void ResizableMatrix<T>::printOnScreen() {
	
	cout << "Continut:\n";

	for ( int i = 0; i < capacityLines; ++i ) {
		
		for ( int j = 1; j <= array[i][0]; ++j ) {
			cout << array[i][j] << ' ';
		}

		cout << '\n';
	}
	
	cout << '\n';
}

template <typename T>
void ResizableMatrix<T>::DFS( int currentNode, ResizableArray<bool>& visited, NodeArbore& currentArbore, ResizableArray< int >& reverseIdUser, Hashtable< int, infoUser>& mapUsers ) {

	/* Crestem contorul pentru elemente deja vizitate din arborele curent */
	currentArbore.NodeArbore::setNumberOfElements( currentArbore.NodeArbore::getNumberOfElements() + 1 );

	/* Facem update la numarul maxim de invitatii trimise */
	currentArbore.NodeArbore::setMaxInvites( max( currentArbore.NodeArbore::getMaxInvites(), array[ currentNode ][ 0 ] ) );

	/* Structura auxiliara in care vom retine informatiile din hash pentru userul cu id-ul currentNode */
	infoUser auxiliar;

	/* Aflam idUser */
	int userID = reverseIdUser[ currentNode ];

	/* Extragem in structura auxiliar informatii despre userul curent */
	mapUsers.get( userID, auxiliar );

	/* Adunam numarul de vizite ale userului curent la total */
	currentArbore.NodeArbore::setSumVisits( currentArbore.NodeArbore::getSumVisits() + auxiliar.numarDeVizite );

	/* Marcam nodul curent din arbore ca fiind vizitat */
	visited.ResizableArray<bool>::insert( currentNode, true );


	/* Parcurgem lista de copii ai nodului curent */
	for ( int i = 2; i <= array[ currentNode ][ 0 ]; ++i ) {

		/* son - fiu al nodului curent */
		int son = array[ currentNode ][ i ];

		/* Daca intalnim unul ce nu a fost deja vizitat, apelam DFS-ul pentru el */
		if( !visited[ son ] )
			DFS( son, visited, currentArbore, reverseIdUser, mapUsers );

	}

}


/* Lista de template-uri acceptate */
template class ResizableMatrix< int >;