#include "../headers/Arbore.h"
#include "../headers/ResizableArray.h"


using namespace std;


void Arbore::findAllRoots( ResizableMatrix< unsigned long long >& listaDeAdiacenta ) {

	/* Nodes - numarul de useri din graf */
	unsigned long long Nodes = listaDeAdiacenta->sizeLines;

	/* numberOfTrees - numarul de arbori pe care i-am gasit */
	unsigned long long numberOfTrees = 0;

	/* visited - vectorul de vizite; 0 - nodul nu a fost vizitat, 1 - nodul a fost vizitat deja */
	ResizableArray< bool > visited( Nodes );
	
	/* Initializez cate un dfs din fiecare nod care nu a fost vizitat inca */
	for( unsigned long long nod = 1; nod <= Nodes; ++nod ) {

		NodeArbore currentArbore;

		/* Nodul curent nu a fost vizitat inca => DFS */
		if( !visited[ nod ] ) {

			/* Incrementam numarul de arbori determinati */
			++numberOfTrees;

			/* Apelam DFS-ul pentru nodul curent */
			DFS( nod, visited, currentArbore );
		
			/* Adaugam arborele in lista */
			this->ResizableArray< unsigned long long >::insert( numberOfTrees, currentArbore );

		}


	}

	/* Pe pozitia 0 va fi retinut numarul de elemente din lista, deci numarul de arbori din lista */
	this->ResizableArray::insert( 0, numberOfTrees );

}