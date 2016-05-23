#include <iostream>
#include "ServiceAPI/headers/ServiceAPI.h"

using namespace std;

int main () {

	Service mata;

	mata.createStore( 1, 1, 1);
	mata.createStore( 4, 1, 1);
	mata.createStore( 4786157, 1, 1);
	mata.createStore( 358, 1, 1);
	mata.createUser( 1, 2, 3 );
	mata.createUser( 2, 3, 4 );
	mata.createUser( 3, 1, 2 );
	mata.createUser( 4, 5, 10 );
	mata.createUser( 5, 10, 11 );
	mata.createUser( 6, 9, 1 );
	mata.visit(1,1,1,1);

	return 0;

}