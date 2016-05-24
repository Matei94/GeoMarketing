#ifndef __ListOfHeaps_H_
#define __ListOfHeaps_H_

#include "Heap.h"

using namespace std;

template <typename T>
class ListOfHeaps {

public:
	/* lista - Lista in care vom retine heap-urile */
	Heap<T> *list;
	unsigned int capacity;

	/* numberOfHeaps - numarul de heap-uri */
	unsigned long long numberOfHeaps;


  public:

  	ListOfHeaps( );

  	~ListOfHeaps( );

    void newHeap(  );

    void initHeap( int poz );

    void insert( int poz, T value );

    T getMaxim( int poz );

  	/* Functia de extragere a numarului de heap-uri */
  	int getNumberOfHeaps( ); 	

    int getCapacity( );

    int getSizeHeap( int poz );

};


#endif /* __ListOfHeaps_H_ */