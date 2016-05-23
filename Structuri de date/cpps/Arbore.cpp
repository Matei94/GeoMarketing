#include "../headers/Arbore.h"
#include "../headers/NodeArbore.h"
#include "../headers/RA.h"
#include "../headers/ResizableMatrix.h"


using namespace std;

unsigned long long Arbore::getNumberOfTrees() {
	return this->numberOfTrees;
}

void Arbore::setNumberOfTrees( unsigned long long value ) {
	this->numberOfTrees = value;
}

void Arbore::findAllRoots( ResizableMatrix< unsigned long long >& listaDeAdiacenta, ResizableArray< int >& reverseIdUser ) {

	/* Nodes - numarul de useri din graf */
	unsigned long long numberOfUsers = listaDeAdiacenta.ResizableMatrix< unsigned long long >::getSizeLines();

	/* numberOfTrees - numarul de arbori pe care i-am gasit */
	unsigned long long numberOfTrees = 0;

	/* visited - vectorul de vizite; 0 - nodul nu a fost vizitat, 1 - nodul a fost vizitat deja */
	ResizableArray< bool > visited( numberOfUsers );
	
	/* Initializez cate un dfs din fiecare nod care nu a fost vizitat inca */
	for( unsigned long long nod = 1; nod <= numberOfUsers; ++nod ) {

		NodeArbore currentArbore;

		/* Nodul curent nu a fost vizitat inca => DFS */
		if( !visited[ nod ] ) {

			/* Incrementam numarul de arbori determinati */
			++numberOfTrees;

			/* Apelam DFS-ul pentru nodul curent */
			ResizableMatrix<T>::DFS( nod, visited, currentArbore, reverseIdUser );
		
			/* Adaugam arborele in lista */
			listaDeArbori.ResizableArray< unsigned long long >::push_back( currentArbore );

		}

	}

	/* Pe pozitia 0 va fi retinut numarul de elemente din lista, deci numarul de arbori din lista */
	listaDeArbori.setNumberOfTrees( numberOfTrees );

}