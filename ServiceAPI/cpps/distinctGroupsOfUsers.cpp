#include "../../Structuri de date/headers/Arbore.h"
#include "../../Structuri de date/headers/NodeArbore.h"
#include "../../Structuri de date/headers/ResizableArray.h"
#include "../headers/ServiceAPI.h"

using namespace std;

Array<int> Service::distinctGroupsOfUsers() {

	/* Apelam functia de generare a listei de arbori */
	listOfTrees.Arbore::findAllRoots( listaDeAdiacenta, reverseIdUsers, mapUsers );

	/* numberOfTrees - numar de arbori din lista tocmai formata */
	int numberOfTrees = listOfTrees.getNumberOfTrees();

	/* result - vectorul de rezultate, pe care il va returna functia */
	Array< int > result( numberOfTrees );
 
	/* Parcurgem lista de arbori */
	for ( int i = 1; i <= numberOfTrees; ++i ) {

		/* Extragem informatiile din arborele curent */
		NodeArbore currentArbore = listOfTrees[ i ];

		/* Mutam numarul de elemente din fiecare arbore in vectorul ce trebuie trimis ca rezultat - result */
		result.Array< int >::insert( i, currentArbore.getNumberOfElements() );

	}

	/* Returnam rezultatul */
	return result;

}