#ifndef __Arbore_H_
#define __Arbore_H_

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

    /* Functia care returneaza continutul listaDeArbori */
    ResizableArray< NodeArbore > getListaDeArbori();

  	/* Functia care extrage numarul de arbori din lista */
  	int getNumberOfTrees();

  	/* Functia care schimba valoarea numarului de arbori din lista */
  	void setNumberOfTrees( int value );

  	/* Functia ce gaseste toate radacinile arborilor si returneaza o lista cu toti acestia */
  	void findAllRoots( ResizableMatrix< int >& listaDeAdiacenta, ResizableArray< int >& reverseIdUsers );

};

#endif /* __Arbore_H_ */