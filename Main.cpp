#include <iostream>
#include "ServiceAPI/headers/ServiceAPI.h"

using namespace std;

int main () {

	Service mata;

	mata.createUser( 1, 1, 1 );
	mata.createStore( 1, 1, 1);
	mata.visit(1,1,1,1);
	mata.createStore( 1, 1, 1);

	cout << "std\n";
	return 0;

}