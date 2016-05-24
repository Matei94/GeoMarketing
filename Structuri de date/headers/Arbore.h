#ifndef __Arbore_H_
#define __Arbore_H_

#include "../headers/Arbore.h"
#include "../headers/Hashtable.h"
#include "../headers/NodeArbore.h"
#include "../headers/ResizableArray.h"
#include "../headers/ResizableMatrix.h"


using namespace std;


class Arbore {

	/* listaDeArbori - lista de arbori de useri pe care ii folosim la taskul 3 */
	ResizableArray< NodeArbore > listaDeArbori;

	/* numberOfTrees - numarul de arbori retinuti in lista */
	int numberOfTrees;

  public:

    /* Constructor default */
    Arbore();

    /* Functia care returneaza continutul listaDeArbori */
    ResizableArray< NodeArbore > getListaDeArbori();

  	/* Functia care extrage numarul de arbori din lista */
  	int getNumberOfTrees();

    /* Functia de extractie a elementului de la pozitia position din vectorul listaDeArbori */
    NodeArbore getValue( int position );

  	/* Functia care schimba valoarea numarului de arbori din lista */
  	void setNumberOfTrees( int value );

  	/* Functia ce gaseste toate radacinile arborilor si returneaza o lista cu toti acestia */
  	void findAllRoots( ResizableMatrix< int >& listaDeAdiacenta, ResizableArray< int >& reverseIdUsers, Hashtable< int, infoUser >& mapUsers, int nrUsers, ResizableArray< bool >& areParinte );

};

#endif /* __Arbore_H_ */