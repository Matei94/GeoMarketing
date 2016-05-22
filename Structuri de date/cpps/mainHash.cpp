#include <iostream>
#include "../headers/Hashtable.h"
#include <string>
using namespace std;

int Hash( int key ) {
	/* Smecheria este ca functia noastra de hash este functia identitate, astfel, hashtable-ul nostru se comporta intocmai ca un vector de frecventa */
	return key;
}

int sdbm( int key ) {
	unsigned long hash = 0;

	while( key ) {
		hash = ( ( key % 10 ) + '0' ) + ( hash << 6 ) + ( hash << 16 ) - hash;
		key = key / 10;
	}

	return hash % 65599;

}

int main () {

	cout << sdbm( 42687 ) << '\n';

	return 0;
}