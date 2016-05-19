#include <iostream>
#include "../headers/Hashtable.h"
using namespace std;

int Hash( int key ) {
	/* Smecheria este ca functia noastra de hash este functia identitate, astfel, hashtable-ul nostru se comporta intocmai ca un vector de frecventa */
	return key;
}

int TEST( int& k ) {
	if( k == 0 ) {
		Hashtable<int,infoMagazin> map = Hashtable<int,infoMagazin>( 10, Hash );
		Hashtable<int,infoUser> mapu = Hashtable<int, infoUser>( 10, HashMag );
		k = 1;
	}

	int k = 0;
	test( k, map );

	infoUser user;
	infoMagazin mag;

	for (int i = 0; i < 10; ++i)
	{

		user.numarDeCumparaturi = i;
		user.numarDeVizite = i;
		user.discountAcordat = i;
		user.userX = i;
		user.userY = i;
		mapu.Insert(i,user);

		mag.indexRA = i;
		mag.storeX = i;
		mag.storeY = i;
		map.Insert(i,mag);
	}

	mapu.Insert(0, user);
	mapu.Insert(8, user);

	map.Insert(0, mag);
	map.Insert(8, mag);

	mapu.printTable( );
	map.printTable( );

	map.get( 5,mag );
	cout << mag.indexRA << endl;

}

int test(  ) {

}

int HashMag( int key ) {
	return key;
}

int main () {



	test( k );

	return 0;
}