#include <fstream>
#include <iostream>

#include "../headers/ResizableMatrix.h"


using namespace std;


int main() {

	ResizableMatrix<int> listaDeAdiacenta( 5 );

	for( unsigned long long i = 0; i < listaDeAdiacenta.getCapacityLines(); ++i ) {

		for ( unsigned long long j = 1; j < 4; ++j ) {
			listaDeAdiacenta.insert( i, (int) i*j );
		}
	}

	listaDeAdiacenta.printOnScreen();


	return 0;
}