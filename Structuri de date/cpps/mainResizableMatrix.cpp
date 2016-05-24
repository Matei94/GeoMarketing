#include <fstream>
#include <iostream>

#include "../headers/ResizableMatrix.h"


using namespace std;


int main() {

	ResizableMatrix<int> listaDeAdiacenta( 5 );
	cout<<"capacitylines: "<<listaDeAdiacenta.getCapacityLines( )<<"\n";
	cout<<"capacitycolums pentru linia 1: "<<listaDeAdiacenta.getCapacityCollumns(1)<<"\n";
	for( int i = 0; i < listaDeAdiacenta.getCapacityLines(); ++i ) {

		for ( int j = 1; j < 4; ++j ) {
			listaDeAdiacenta.insert( i, (int) i*j );
			cout<<"capacitylines: "<<listaDeAdiacenta.getCapacityLines()<<"\n";
			cout<<"capacitycolums pentru j: "<<listaDeAdiacenta.getCapacityCollumns( j )<<"\n";
		}
	}

	listaDeAdiacenta.printOnScreen();


	return 0;
}