#include "../headers/Arbore.h"


using namespace std;


void Arbore::findAllRoots( ResizableMatrix< unsigned long long >& listaDeAdiacenta ) {

	/* Nodes - numarul de useri din graf */
	Nodes = listaDeAdiacenta->sizeLines;

	/* numberOfTrees - numarul de arbori pe care i-am gasit */
	numberOfTrees = 0;

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
			this->ResizableArray::insert( numberOfTrees, currentArbore );

		}


	}

}