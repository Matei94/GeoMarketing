#include <iostream>

#include "../headers/ResizableArray.h"

using namespace std;

template <typename T>
ResizableArray<T>::ResizableArray() {
 	this->array = NULL;
	this->capacity = 0;
 	this->size = 0;
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
void ResizableArray<T>::push_back( T value ) {

	/* Verific daca mai am spatiu alocat pentru insertia curenta */
	if (size == capacity) {
 
		/* Aloc un vector nou de dimensiune dubla */
		T *tmpArray = new T[ 2*capacity ];
 
		/* Copiez elementele din vectorul curent in cel temporar */
		for ( int i = 0; i < size; ++i ) {
			tmpArray[ i ] = array[ i ];
		}
 
		/* Eliberez memoria ocupata de vechiul vector */
		delete[] array;
 
		/* Salvez vectorul nou alocat in vectorul vechi, si fac update la capacity */
		array = tmpArray;
		capacity = 2 * capacity;
	}
 
	/* Adaug elementul la finalul vectorului si incrementez size-ul */
	array[ size++ ] = value;
}


template <typename T>
void ResizableArray<T>::sortAscending() {
	/* Nu cred ca avem nevoie de asta, deocamdata */
}

template <typename T>
void ResizableArray<T>::printOnScreen() {
	
	cout << "Continut: ";

	for ( int i = 0; i < size; ++i ) {
		cout << array[i] << ' ';
	}
	
	cout << '\n';
}


/* Lista de template-uri acceptate */
template class ResizableArray<int>;