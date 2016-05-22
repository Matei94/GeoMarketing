#include <iostream>

#include "../headers/NodeArbore.h"
#include "../headers/ResizableArray.h"

using namespace std;

template <typename T>
ResizableArray<T>::ResizableArray() {
	this->capacity = 1;
 	this->size = 1;
	this->array = new T[ capacity ];
	array[0] = 0;
}


template <typename T>	
ResizableArray<T>::ResizableArray( unsigned long long capacity ) {
	this->capacity = capacity;
	this->size = 0;
	this->array = new T[ capacity ];
}


template <typename T>
ResizableArray<T>::~ResizableArray(){
	delete[] this->array;
}


template <typename T>
ResizableArray<T>::ResizableArray( const ResizableArray& other ) {

	size = other.size;
	capacity = other.capacity;
	array = other.array;

	if( array ) {
		for( unsigned long long i = 0; i < size; ++i ) {
			array[i] = other.array[i];
		}
	}

}


template <typename T>
void ResizableArray<T>::operator=( const ResizableArray& other ) {

	size = other.size;
	capacity = other.capacity;
	array = other.array;

	if( array ) {
		for( unsigned long long i = 0; i < size; ++i ) {
			array[i] = other.array[i];
		}
	}

}


template <typename T>
T ResizableArray<T>::operator[]( unsigned long long position ) {

	if(position >= capacity) {
		cout << "Boss, nu esti in zona de memorie buna\n";
		return T();
	}

	return array[ position ];
}

template <typename T>
T ResizableArray<T>::getValue( unsigned long long position ) {
	return array[ position ];
}


template <typename T>
unsigned long long ResizableArray<T>::getCapacity() {
	return capacity;
}


template <typename T>
unsigned long long ResizableArray<T>::getSize() {
	return size;
}


template <typename T>
void ResizableArray<T>::setArray( T* newArray ) {
	this->array = newArray;
}


template <typename T>
void ResizableArray<T>::resize() {

	/* Aloc un vector nou de dimensiune dubla */
	T *tmpArray = new T[ 2*capacity ];

	/* Copiez elementele din vectorul curent in cel temporar */
	for ( unsigned long long i = 0; i < size; ++i ) {
		tmpArray[ i ] = array[ i ];
	}

	/* Eliberez memoria ocupata de vechiul vector */
	delete[] array;

	/* Salvez vectorul nou alocat in vectorul vechi, si fac update la capacity */
	array = tmpArray;
	capacity = 2 * capacity;	

}


template <typename T>
void ResizableArray<T>::push_back( T value ) {

	/* Verific daca mai am spatiu alocat pentru insertia curenta */
	if (size == capacity) {
 		this->resize();
	}
 
	/* Adaug elementul la finalul vectorului si incrementez size-ul */
	array[ size++ ] = value;
}


template <typename T>
void ResizableArray<T>::insert( unsigned long long position, T value ) {

	if (position >= capacity)
		this->resize();
	array[ position ] = value;
}


template <typename T>
void ResizableArray<T>::sortAscending() {
	/* Nu cred ca avem nevoie de asta, deocamdata */
}

/*
template <typename T>
void ResizableArray<T>::printOnScreen() {
	
	cout << "Continut: ";

	for ( int i = 0; i < size; ++i ) {
		cout << array[i] << ' ';
	}
	
	cout << '\n';
}
*/


/* Lista de template-uri acceptate */
template class ResizableArray< int >;
template class ResizableArray< NodeArbore >;