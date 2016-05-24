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

NodeArbore Arbore::getValue( int position ) {
	return this->listaDeArbori[ position ];
}

void Arbore::findAllRoots( ResizableMatrix< int >& adjacencyList, ResizableArray< int >& reverseIdUser, Hashtable< int, infoUser >& mapUsers, int nrUsers, ResizableArray< bool >& areParinte ) {

	//cout << "Se presupune ca avem " << nrUsers << " utilizatori frumosi aicisa.\n\n";

	/* Vector in care vom retine indicii radacinilor */
	ResizableArray< int > listOfRoots; 

	/* Initializez numarul de arbori */
	int countTrees = 0;

	/* visited - vectorul de vizite; 0 - nodul nu a fost vizitat, 1 - nodul a fost vizitat deja */
	ResizableArray< bool > visited( nrUsers );

	//cout << "Cica s-au creat cu succes listOfRoots, respectiv visited.\n\n";

	/* Parcurgem lista de useri si vedem care sunt root-urile */
	for ( int currentUser = 1; currentUser <= nrUsers; ++currentUser ) {
		
		//cout << "Se spune ca userul cu indexul " << currentUser << " este acum procesat.\n";

		//cout << "Userul " << currentUser << " are parinte. Raspuns: " << areParinte[ currentUser ] << ". \n";

		//cout << "Lista de adiacenta are acum " << adjacencyList.getCapacityLines() << " linii declarate.\n";

		/* Daca userul curent pare sa fie radacina, il adaugam in lista de radacini */
		if ( !areParinte[ currentUser ] && currentUser < adjacencyList.getCapacityLines() &&  adjacencyList[ currentUser ][ 0 ] ) {

			//cout << "Ca sa vezi, userul cu indexul " << currentUser << " este si radacina.\n\n";

			//cout << " Are parinte nodul curent? Raspuns: " << areParinte[ currentUser ] << "\n Are " << adjacencyList[ currentUser ][ 0 ] << " copilasi copaci, prosti si urati.\n";

			listOfRoots.ResizableArray< int >::insert( ++countTrees, currentUser );

			//cout << "Ultima radacina adaugata este " << listOfRoots[ countTrees ] << " .\n";

		}
		
	}

	/* Setam numarul de arbori din lista = numarul de radacini pe care le-am detectat */
	this->setNumberOfTrees( countTrees );

	//cout << "Legenda spune ca avem in momentul asta " << this->getNumberOfTrees() << " copacei frumosi si baftosi.\n\n";

	/* Parcurgem lista de radacini si construim listOfTrees */
	for ( int i = 1; i <= numberOfTrees; ++i ) {

		/* currentRoot - radacina arborelui curent pe care il vom inspecta */
		int curentRoot = listOfRoots[ i ];

		//cout << "Se spune ca radacina cu indexul " << curentRoot << " este acum procesata.\n";
	
		/* Declaram un NodeArbore pentru arborele curent, pe care ulterior il vom adauga la lista de arbori */
		NodeArbore currentNodeArbore;

		/* Apelam DFS-ul pentru nodul curent */
		adjacencyList.ResizableMatrix< int >::DFS( curentRoot, visited, currentNodeArbore, reverseIdUser, mapUsers );
	
		/* Adaugam informatiile cu privire la arborele tocmai exploatat in lista de arbori */
		listaDeArbori.ResizableArray< NodeArbore >::push_back( currentNodeArbore );

	}

}