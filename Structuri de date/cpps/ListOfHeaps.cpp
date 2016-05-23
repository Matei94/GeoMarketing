#include "../headers/ListOfHeaps.h"
#include "../headers/RA.h"
#include "../headers/Heap.h"

using namespace std;


template <typename T>
void ListOfHeaps<T>::getNumberOfHeaps() {
	return this->numberOfHeaps;
}


template <typename T>
int ListOfHeaps<T>::setNumberOfHeaps( int value ) {
	this->numberOfHeaps = value;
}


