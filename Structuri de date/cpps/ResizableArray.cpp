#include <iostream>

#include "../headers/NodeArbore.h"
#include "../headers/ResizableArray.h"
#include "../headers/Heap.h"

using namespace std;

template <typename T>
ResizableArray<T>::ResizableArray() {
 	this->size = 0;
}


template <typename T>	
ResizableArray<T>::ResizableArray( int capacity ) {
	this->capacity = capacity;
	this->size = 0;
	this->array = new T[ capacity ];
	for( int i = 0; i < capacity; i++ )
		array[i] = T();
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
		for( int i = 0; i <= size; ++i ) {
			array[i] = other.array[i];
		}
		for( int i = size + 1; i < capacity; i++ )
			array[i] = T();
	}

}


template <typename T>
void ResizableArray<T>::operator=( const ResizableArray& other ) {

	size = other.size;
	capacity = other.capacity;
	array = other.array;

	if( array ) {
		for( int i = 0; i <= size; ++i ) {
			array[i] = other.array[i];
		}
		for( int i = size + 1; i < capacity; i++ )
			array[i] = T();
	}

}


template <typename T>
T ResizableArray<T>::operator[]( int position ) {

	if(position >= capacity) {
		cout << "Boss, nu esti in zona de memorie buna\n";
		return T();
	}

	return array[ position ];
}

template <typename T>
T ResizableArray<T>::getValue( int position ) {
	return array[ position ];
}


template <typename T>
int ResizableArray<T>::getCapacity() {
	return capacity;
}


template <typename T>
int ResizableArray<T>::getSize() {
	return size;
}


template <typename T>
void ResizableArray<T>::setArray( T* newArray ) {
	this->array = newArray;
}

template< typename T>
void ResizableArray<T>::setCapacity( int capacity ){
	this->capacity = capacity;
}

template <typename T>
void ResizableArray<T>::resize() {

	/* Aloc un vector nou de dimensiune dubla */
	T *tmpArray = new T[ 2*capacity ];

	/* Copiez elementele din vectorul curent in cel temporar */
	for ( int i = 0; i <= size; ++i ) {
		tmpArray[ i ] = array[ i ];
	}

	/* Eliberez memoria ocupata de vechiul vector */
	delete[] array;

	/* Salvez vectorul nou alocat in vectorul vechi, si fac update la capacity */
	array = tmpArray;
	capacity = 2 * capacity;
	for( int i = size + 1; i < capacity; i++ )
		array[i] = T();	

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
void ResizableArray<T>::insert( int position, T value ) {

	if (position >= capacity)
		{this->resize();
		size = position;
		}	
	array[ position ] = value;
}


template< typename T >
void ResizableArray<T>::insertInPlus( int position, T value ){
	if( position >= capacity ) {
		this->resize();
		size = position;
	}
	if( size < position )
		size = position;
	array[ position ] += value;
}


template <typename T>
void ResizableArray<T>::sortAscending() {
	/* Nu cred ca avem nevoie de asta, deocamdata */
}

template <typename T> 
void ResizableArray<T>::initialize() {
	this->capacity = 1;
 	this->size = 0;
	this->array = new T[ capacity ];
	for( int i = 0; i < capacity; i++ )
		array[i] = T();
}


/*
template <typename T>
void ResizableArray<T>::printOnScreen() {
	
	cout << "Continut: ";

	for ( int i = 0; i <= size; ++i ) {
		cout << array[i] << ' ';
	}
	
	cout << '\n';
}
*/


/* Lista de template-uri acceptate */
template class ResizableArray< bool >;
template class ResizableArray< int >;
template class ResizableArray< NodeArbore >;
//template class ResizableArray< Heap<int> >;