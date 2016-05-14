#include "../headers/ResizableArray.h"
#include <iostream>

using namespace std;

ResizableArray::ResizableArray(){
 	this->array = NULL;
	this->capacity = 0;
 	this->size = 0;
}
	
ResizableArray::ResizableArray(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->array = new int[ capacity ];
}

ResizableArray::~ResizableArray(){
	// Do nothing
}

int ResizableArray::getValue(int position){
	return array[position-1];
}

void ResizableArray::AddElement(int value) {
	// Verific daca vectorul intern este plin
	if (size == capacity) {
		// Voi face o realocare. La final copiez elementele in noul vectorl
 
		// Aloc un nou vector de dimensiune dubla.
		int *tmpArray = new int[ 2*capacity ];
 
		// Copiez elementele in noul vector
		for ( int i = 0; i < size; ++i ) {
			tmpArray[ i ] = array[ i ];
		}
 
		// Eliberez memoria ocupata de vechiul vector.
		delete[] array;
 
		// Salvez vectorul nou format, care are capacitate dubla.
		array = tmpArray;
		capacity = 2 * capacity;
	}
 
	// Adaug elementul la finalul vectorului
	// Pozitia noului element este size;
	array[ size ] = value;
	size++; // urmatorul element adaugat va fi adaugat la o urmatoarea pozitie
}

void ResizableArray::SortAscending() {
	for ( int i = 0; i < size; ++i ) {
		for ( int j = i + 1; j < size; ++j ) {
			if (array[ i ] > array[ j ]) {
				int tmp = array[i];
				array[ i ] = array[ j ];
				array[ j ] = tmp;
			}
		}
	}
}

void ResizableArray::PrintOnScreen() {
	cout << "Continut: ";
	for ( int i = 0; i < size; ++i ) {
		cout << array[i] << ' ';
	}
	cout << '\n';
}