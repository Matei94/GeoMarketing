#include "../headers/ListOfHeaps.h"
#include "../headers/RA.h"
#include "../headers/Heap.h"

using namespace std;


template <typename T>
void ListOfHeaps<T>::getNumberOfHeaps() {
	return this->numberOfHeaps;
}


template <typename T>
unsigned long long ListOfHeaps<T>::setNumberOfHeaps( unsigned long long value ) {
	this->numberOfHeaps = value;
}


