#include <iostream>
#include "ServiceAPI/headers/ServiceAPI.h"

using namespace std;

int main () {

	Service mata;

	mata.createUser( 1, 2, 3 );
	mata.createUser( 2, 3, 4 );
	mata.createUser( 3, 1, 2 );
	mata.createUser( 4, 5, 10 );
	mata.createUser( 5, 10, 11 );
	mata.createUser( 6, 9, 1 );

//	mata.createStore( 1, 1, 1);
//	mata.visit(1,1,1,1);
//	mata.createStore( 1, 1, 1);

	cout << "std\n";
	return 0;

}