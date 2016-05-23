#ifndef __ListOfHeaps_H_
#define __ListOfHeaps_H_

#include "../../Structuri de date/headers/Arbore.h"
#include "../../Structuri de date/headers/NodeArbore.h"
#include "../../Structuri de date/headers/ResizableArray.h"
#include "../../Structuri de date/headers/ServiceAPI.h"


using namespace std;

template <typename T>
class ListOfHeaps {

	/* lista - Lista in care vom retine heap-urile */
	ResizableArray< Heap<T> > lista;

	/* numberOfHeaps - numarul de heap-uri */
	unsigned long long numberOfHeaps;


  public:

  	/* Functia de extragere a numarului de heap-uri */
  	unsigned long long getNumberOfHeaps();

  	/* Functia de schimbare a valorii numarului de heap-uri */
  	void setNumberOfHeaps( unsigned long long value );  	

};


#endif /* __ListOfHeaps_H_ */