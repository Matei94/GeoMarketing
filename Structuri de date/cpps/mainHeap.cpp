#include <iostream>

#include "../headers/Heap.h"

using namespace std;

int main( ) {

	Heap<int> H(10);
	int aux;

	for ( int i = 0; i < 7; ++i ) {
		cin >> aux;
		H.insert(aux);
	}

	for ( int i = 0; i < 3; ++i ) {
		int maxim = 0;
		H.getMaxim( maxim );
		cout << maxim << " ";
	}

	return 0;
}
