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
	/*Coruperi de memorei, habar n-am sa le rezolv*/
	//delete[] list;
}

template <typename T>
void ListOfHeaps<T>::newHeap( ) {
	Heap<T>* tmpList = new Heap<T>[ 2 * capacity ];

	for( int i = 0; i < numberOfHeaps; i++ ) {
		tmpList[ i ] = list[ i ];
	}

	/*Coruperi de memorei, habar n-am sa le rezolv*/
	//delete[] list;

	list = tmpList;
	capacity = 2 * capacity;

}

template <typename T>
void ListOfHeaps<T>::initHeap( int poz ) {

	if( poz >= capacity ) {
		this->newHeap();
	}

	numberOfHeaps++;

	list[ poz ].insert( -1 );

}

template <typename T>
void ListOfHeaps<T>::topK( int poz, int k, int array[] ) {

	Heap<T> copy;

	if( poz >= capacity ) {
		std::cout << " Nu exista acest heap \n";
		return ;
	}

	int aux;
	copy = list[ poz ];
	for (int i = 0; i < k; ++i)	{
		copy.getMaxim( aux );
		cout<<aux<<' ';
		if( aux < 0 ) {
			array[ i ] = -1;
		}
		else {
			array[ i ] = aux;
		}
	}
	cout<<"\n";

}

template <typename T>
void ListOfHeaps<T>::insert( int poz, T value ) {
	
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

template <typename T>
int ListOfHeaps<T>::getSizeHeap( int poz ){
	return this->list[ poz ].getSize();
}

template class ListOfHeaps<int>;