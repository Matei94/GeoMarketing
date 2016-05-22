#include <iostream>

#include "../headers/Heap.h"

using namespace std;


template <typename T>
Heap<T>::Heap( int length ) {
	/* Se retine ce dimensiune va avea vectorul in care vom retine heap-ul */
    capacity = length;

    /* size - pozitia curenta din heap */
    size = 0;

    /* Se aloca vectorul numit anterior */
    hip = new T[ capacity + 1 ];
}


template <typename T>
Heap<T>::~Heap( ) {
	/* Se dezaloca zona de memorie ce retinea heap-ul */
    delete[] hip;
}


template <typename T>
Heap<T>::Heap( const Heap<T>& other ) {
	
	this->capacity = other.capacity;
	this->size = other.size;
	this->hip = other.hip;

	if( hip ) {

		for( int i = 0; i <= size; ++i ) 
			hip[i] = other.hip[i];

	}

}


template <typename T>
void Heap<T>::operator=( const Heap<T>& other ) {
	
	this->capacity = other.capacity;
	this->size = other.size;
	this->hip = other.hip;

	if( hip ) {

		for( int i = 0; i <= size; ++i ) 
			hip[i] = other.hip[i];

	}

}



template <typename T>
void Heap<T>::insert( T value ) {
	/* Se adauga in coada vectorului hip elementul ce se vrea inserat */
	hip[ ++size ] = value;

	/* Ne asiguram ca ajunge pe pozitia care trebuie in hip */
	moveUp( size );
}


template <typename T>
void Heap<T>::moveUp( int currentIndex ) {
	/* Indexul parintelui nodului curent din heap */
	int parentIndex = currentIndex / 2;

	/* Daca se ajunge in varful heap-ului sau valoarea curenta e bine pozitionata in heap, gata */
	if ( currentIndex == 1 || hip[ parentIndex ] >= hip[ currentIndex ] )
		return;

	/* Se schimba locul celor doua valori, pentru a se pastra ordinea corecta */
	swapValues( parentIndex, currentIndex );

	/* Se reapeleaza functia curenta, pentru verificarea corectitudinii oridinii in heap */
	moveUp( parentIndex );
}


template <typename T>
void Heap<T>::moveDown( int currentIndex ) {
	/* Indicii fiilor nodului curent din arbore, index - auxiliar */
	int leftChildIndex = 2*currentIndex;
	int rightChildIndex = 2*currentIndex + 1;
	int index = currentIndex;

	/* Daca elementul de pe pozitia curenta are o prioritate mai mica decat fiul stang */
	if ( leftChildIndex <= size && hip[index] < hip[leftChildIndex] )
		index = leftChildIndex;

	/* Daca elementul de pe pozitia curenta are o prioritate mai mica decat fiul drept */
	if ( rightChildIndex <= size && hip[index] < hip[rightChildIndex] )
		index = rightChildIndex;

	/* Daca elementul curent inca nu este la locul lui in heap */
	if ( index != currentIndex ) {
		/* Se face swapul intre cele doua elemente gasite ca fiind puse invers */
		swapValues( index, currentIndex );
		/* Se continua verificarea */
		moveDown( index );
	}

}


template <typename T>
void Heap<T>::swapValues( int index1, int index2 ) {
	T aux = hip[ index1 ];
	hip[ index1 ] = hip[ index2 ];
	hip[ index2 ] = aux;
}


template <typename T>
bool Heap<T>::getMaxim( T& hipMaxim ) {
	hipMaxim = hip[1];

	if ( size == 0 ) {
		cout << "Heap-ul este gol. Nu se poate extrage niciun maxim. Scz pls...\n";
		return false;
	}

	/* Se muta maximul pe ultima pozitie in heap */
	hip[1] = hip[size];

	/* Se elimina "fortat" elementul si se scade dimensiunea curenta a heap-ului */
	--size;

	/* Se restabileste ordinea in heap */
	moveDown( 1 );

	return true;
}


template class Heap<int>;
