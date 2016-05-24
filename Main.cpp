#include <iostream>

#include "ServiceAPI/headers/ServiceAPI.h"


using namespace std;

int main () {

	Service mata;

	//cout<<"creats\n";
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
	
	//cout<<"vizite\n";
	mata.visit( 1, 1, 1, 1);
	mata.visit( 2, 4, 358, -1 );
	mata.visit( 1, 3, 1, 43);

	//cout<<"invite\n";
	mata.invite( 1, 2 );
	mata.invite( 2, 3 );
	mata.invite( 1, 4 );
	mata.invite( 2, 5 );


	mata.distinctGroupsOfUsers();


	return 0;

}