#include <iostream>
#include "../headers/LinkedList.h"
#include "../headers/Heap.h"

using namespace std;

int main () {

	Heap<int> jeg,ham;

	jeg.insert( 2 );
	ham.insert( 3 );
	ham.insert( 5 );

	LinkedList< Heap<int> > lista;

	lista.addFirst( jeg );

	int maria;

	lista.front()->getValue().getMaxim( maria);

	cout<<maria<<endl;
	return 0;
}