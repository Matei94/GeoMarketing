#ifndef __ListOfHeaps_H_
#define __ListOfHeaps_H_

#include "../headers/Arbore.h"
#include "../headers/NodeArbore.h"
#include "../headers/ResizableArray.h"
#include "../headers/ServiceAPI.h"


using namespace std;

template <typename T>
class ListOfHeaps {

	/* lista - Lista in care vom retine heap-urile */
	ResizableArray< Heap<T> > lista;

	/* numberOfHeaps - numarul de heap-uri */
	int numberOfHeaps;


  public:

  	/* Functia de extragere a numarului de heap-uri */
  	int getNumberOfHeaps();

  	/* Functia de schimbare a valorii numarului de heap-uri */
  	void setNumberOfHeaps( int value );  	

};


#endif /* __ListOfHeaps_H_ */