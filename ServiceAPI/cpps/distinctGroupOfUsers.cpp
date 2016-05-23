#include "../../Structuri de date/headers/Arbore.h"
#include "../../Structuri de date/headers/NodeArbore.h"
#include "../../Structuri de date/headers/ResizableArray.h"
#include "../../Structuri de date/headers/ServiceAPI.h"

using namespace std;

Array<int> ServiceAPI<T>::distinctGroupsOfUsers() {

	/* numberOfTrees - numarul de arbori din lista */
	unsigned long long numberOfTrees = listOfTrees.listaDeArbori.Arbore::getNumberOfTrees();

	/* Vectorul in care vom stoca numarul de elemente din fiecare arbore */
	Array<int> result( numberOfTrees + 1 );

	/* Parcurgem lista de arbori si extragem numarul de elemente din componenta fiecaruia */
	for( unsigned long long i = 1; i <= numberOfTrees; ++i ) {

		/* Extragem numarul de elemente din fiecare arbore al listei */
		unsigned long long numberOfElements = listOfTrees.listaDeArbori.ResizableArray< NodeArbore >::getValue( i ).NodeArbore::getNumberOfElements();

		/* Inseram valoarea obtinuta la pozitia curenta */
		result.insert( i, numberOfElements );

	}

}