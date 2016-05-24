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

	/* Vector in care vom retine indicii radacinilor */
	ResizableArray< int > listOfRoots; 

	/* visited - vectorul de vizite; 0 - nodul nu a fost vizitat, 1 - nodul a fost vizitat deja */
	ResizableArray< bool > visited( nrUsers );

	/* Parcurgem lista de useri si vedem care sunt root-urile */
	for ( int currentUser = 1; currentUser <= nrUsers; ++currentUser ) {
		
		/* Daca userul curent pare sa fie radacina, il adaugam in lista de radacini */
		if ( !areParinte[ currentUser ] && adjacencyList[ currentUser ][ 0 ] )
			listOfRoots.ResizableArray< int >::push_back( currentUser );
		
	}

	/* Setam numarul de arbori din lista = numarul de radacini pe care le-am detectat */
	this->setNumberOfTrees( listOfRoots.getSize() );

	/* Parcurgem lista de radacini si construim listOfTrees */
	for ( int i = 1; i <= numberOfTrees; ++i ) {

		/* currentRoot - radacina arborelui curent pe care il vom inspecta */
		int curentRoot = listOfRoots[ i ];
	
		/* Declaram un NodeArbore pentru arborele curent, pe care ulterior il vom adauga la lista de arbori */
		NodeArbore currentNodeArbore;

		/* Apelam DFS-ul pentru nodul curent */
		adjacencyList.ResizableMatrix< int >::DFS( curentRoot, visited, currentNodeArbore, reverseIdUser, mapUsers );
	
		/* Adaugam informatiile cu privire la arborele tocmai exploatat in lista de arbori */
		listaDeArbori.ResizableArray< NodeArbore >::push_back( currentNodeArbore );

	}

}