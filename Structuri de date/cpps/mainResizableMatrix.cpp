#include <fstream>
#include <iostream>

#include "../headers/ResizableArray.h"


using namespace std;


int main() {
	
	ResizableArray< ResizableArray<int> > listaDeAdiacenta(13);

	cout << listaDeAdiacenta.getCapacity() << '\n';


	for ( unsigned long long i = 0; i < 13; ++i ) {

		//ResizableArray<int> listaDeAdiacenta[i](13);
		cout << i << '\t' << listaDeAdiacenta[i].getCapacity() << ' ' << listaDeAdiacenta[i].getSize() << '\n';

		//listaDeAdiacenta[i].setArray( &newArray );
	}


	for ( unsigned long long  i = 1; i < 5; ++i )
		for ( unsigned long long j = 1; j < 2; ++j )
			listaDeAdiacenta[i].insert(j, j);


	for ( unsigned long long i = 1; i < 5; ++i ) {
		for ( unsigned long long j = 1; j < 2; ++j )
			cout << listaDeAdiacenta[i][j] << ' ';
		cout << '\n';
	}


	return 0;
}