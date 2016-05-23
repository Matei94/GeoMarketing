#include "../headers/ListOfHeaps.h"
#include "../headers/ResizableArray.h"
#include "../headers/Heap.h"

using namespace std;


template<typename T>
ListOfHeaps<T>::ListOfHeaps<T>() {
	
}


template <typename T>
void ListOfHeaps<T>::getNumberOfHeaps() {
	return this->numberOfHeaps;
}


template <typename T>
unsigned long long ListOfHeaps<T>::setNumberOfHeaps( unsigned long long value ) {
	this->numberOfHeaps = value;
}


