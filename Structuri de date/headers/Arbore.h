#ifndef __Arbore_H_
#define __Arbore_H_

#include "../headers/NodeArbore.h"
#include "../headers/ResizableArray.h"
#include "../headers/ResizableMatrix.h"


using namespace std;


template <typename T>
class Arbore {

	/* listaDeArbori - lista de arbori de useri pe care ii folosim la taskul 3 */
	ResizableArray< NodeArbore > listaDeArbori;

  public:

  	/* Functia ce gaseste toate radacinile arborilor si returneaza o lista cu toti acestia */
  	void findAllRoots( ResizableMatrix< unsigned long long >& listaDeAdiacenta );

};

#endif /* __Arbore_H_ */