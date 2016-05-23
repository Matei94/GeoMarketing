#include "../headers/ListOfHeaps.h"

using namespace std;

template <typename T>
ListOfHeaps<T>::ListOfHeaps( ) {
	this->capacity = 1;
	this->numberOfHeaps = 0;
	this->list = new Heap<T>[ capacity ];
}

template <typename T>
ListOfHeaps<T>::~ListOfHeaps( ) {
	delete[] list;
}

template <typename T>
void ListOfHeaps<T>::newHeap( ) {
	Heap<T>* tmpList = new Heap<T>[ 2 * capacity ];

	for( int i = 0; i < numberOfHeaps; i++ ) {
		tmpList[ i ] = list[ i ];
	}

	delete[] list;

	list = tmpList;
	capacity = 2 * capacity;

}

template <typename T>
void ListOfHeaps<T>::insert( int poz, T value ) {
	
	if( poz >= capacity ) {
		this->newHeap();
		numberOfHeaps = poz;
	}

	list[ poz ].insert( value );

}

template <typename T>
T ListOfHeaps<T>::getMaxim( int poz ) {
	T aux;
	list[ poz ].getMaxim( aux );
	return aux;
}

template <typename T>
int ListOfHeaps<T>::getNumberOfHeaps() {
	return this->numberOfHeaps;
}

template <typename T>
int ListOfHeaps<T>::getCapacity() {
	return this->capacity;
}

template class ListOfHeaps<int>;