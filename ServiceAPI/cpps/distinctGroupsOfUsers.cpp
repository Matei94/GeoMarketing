#include "../../Structuri de date/headers/Arbore.h"
#include "../../Structuri de date/headers/NodeArbore.h"
#include "../../Structuri de date/headers/ResizableArray.h"
#include "../headers/ServiceAPI.h"

using namespace std;

inline Array<int> Service::distinctGroupsOfUsers() {

	cout << "Pizdarel, intri in functie?\n";

	/* numberOfTrees - numarul de arbori din lista */
	int numberOfTrees = listOfTrees.Arbore::getNumberOfTrees();

	/* Vectorul in care vom stoca numarul de elemente din fiecare arbore */
	Array<int> result( numberOfTrees + 1 );

	cout << "Number of trees equals: " << numberOfTrees << '\n';

	/* Parcurgem lista de arbori si extragem numarul de elemente din componenta fiecaruia */
	for( int i = 1; i <= numberOfTrees; ++i ) {

		/* Extragem numarul de elemente din fiecare arbore al listei; -1 pentru ca mereu primul vecin o sa fie 0; vezi insertul de la ResizableMatrix */
		int numberOfElements = listOfTrees.Arbore::getListaDeArbori().ResizableArray< NodeArbore >::getValue( i ).NodeArbore::getNumberOfElements() - 1;

		/* Inseram valoarea obtinuta la pozitia curenta */
		result.insert( i, numberOfElements );

		cout << i << ' ' << numberOfElements << '\n';

	}

	cout << '\n';

}