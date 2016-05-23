#include <iostream>

#include "../headers/Heap.h"

using namespace std;

int main( ) {

	Heap<int> H(10);
	int aux;

	H.insert( 1323);
	H.insert( 2244);
	H.getMaxim( aux );
	cout<<aux<< '\n';
	H.getMaxim(aux);
	cout<<aux<< '\n';
	H.getMaxim(aux);
	cout<<aux<< '\n';

	return 0;
}
