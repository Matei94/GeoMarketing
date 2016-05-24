#include "../headers/Arbore.h"
#include "../headers/Hashtable.h"
#include "../headers/NodeArbore.h"
#include "../headers/ResizableArray.h"
#include "../headers/ResizableMatrix.h"


using namespace std;


Arbore::Arbore() {
	this->numberOfTrees = 0;
}


ResizableArray< NodeArbore > Arbore::getListaDeArbori() {
	return this->listaDeArbori;
}


int Arbore::getNumberOfTrees() {
	return this->numberOfTrees;
}

void Arbore::setNumberOfTrees( int value ) {
	this->numberOfTrees = value;
}

void Arbore::findAllRoots( ResizableMatrix< int >& listaDeAdiacenta, ResizableArray< int >& reverseIdUser, Hashtable< int, infoUser >& mapUsers ) {

	/* numbereOfUsers - numarul de useri din graf */
	int numberOfUsers = listaDeAdiacenta.ResizableMatrix< int >::getCapacityLines();

	/* numberOfCopaci - numarul de arbori pe care i-am gasit */
	int numberOfCopaci = 0;

	/* visited - vectorul de vizite; 0 - nodul nu a fost vizitat, 1 - nodul a fost vizitat deja */
	ResizableArray< bool > visited( numberOfUsers );
	
	/* Initializez cate un dfs din fiecare nod care nu a fost vizitat inca */
	for( int nod = 1; nod <= numberOfUsers; ++nod ) {

		NodeArbore currentArbore;

		/* Nodul curent nu a fost vizitat inca => DFS */
		if( !visited[ nod ] &&  ) {

			/* Incrementam numarul de arbori determinati */
			++numberOfTrees;

			/* Apelam DFS-ul pentru nodul curent */
			listaDeAdiacenta.ResizableMatrix< int >::DFS( nod, visited, currentArbore, reverseIdUser, mapUsers );
		
			/* Adaugam arborele in lista */
			listaDeArbori.ResizableArray< NodeArbore >::push_back( currentArbore );

		}

	}

	/* Pe pozitia 0 va fi retinut numarul de elemente din lista, deci numarul de arbori din lista */
	this->setNumberOfTrees( numberOfTrees );

}