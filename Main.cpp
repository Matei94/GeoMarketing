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

	//mata.distinctGroupsOfUsers();

	//cout << '\n';

	//cout << mata.userWithMostInvites();

/*
	cout<<"creats\n";
	mata.createStore( 1, 25.96966, 44.44577);
	//mata.visitsInTimeframe( 1278, 2319 );
	mata.createStore( 2, 25.965965, 44.336735);
	mata.createStore( 3, 25.927, 44.176857);
	mata.createStore( 4, 25.804914, 44.474495);
	mata.createStore( 5, 26.047882, 44.290497);
	mata.createUser( 1, 2.9873094627998737, 4.1296186324496205 );
	mata.createUser( 0, 3.208566980164757, 3.1919495083244676 );
	mata.invite(0, 1);
*/

	return 0;

}