/* clasa AvlTree */

#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "AvlNode.h"

template< class T >
class AvlTree {
	private:

		/* radacina arborelui binar de cautare echilibrat */
		AvlNode<T> *root;

		/* rotatia la stanga pornind din nodul a */
		AvlNode<T>* rotateLeft( AvlNode<T> *a );

		/* rotatian la dreapta pornind din nodul a */
		AvlNode<T>* rotateRight( AvlNode<T> *a );

		/* rotatia la stanga din nodul n, urmata de o rotatie la dreapta */
		AvlNode<T>* rotateLeftThenRight( AvlNode<T> *n );

		/* rotatia la dreapta din nodul n, urmata de o rotatie la stanga */
		AvlNode<T>* rotateRightThenLeft( AvlNode<T> *n );

		/* functia care echilibreaza arborele pornind din nodul n*/
		void rebalance( AvlNode<T> *n );

		/* functie care calculeaza inaltimea subarborelui din nodul n */
		int height( AvlNode<T> *n );

		/* functie care calculeaza factorul de echilibru pentru nodul n */
		void setBalance( AvlNode<T> *n );

		/* functie care afiseaza factorul de echilibru pornind de la nodul  n */
		void printBalance( AvlNode<T> *n );

	public:

		/* constructor default */
		AvlTree( );

		/* destructor */
		~AvlTree( );

		/* functia de inserare a unei chei */
		bool insert( T key );

		/* functie care afiseaza factorul de echilibru al fiecarui nod din arbore, pornind de la radacina */
		void printBalance();

		/* functie care returneaza radacina arborelui */
		AvlNode<T>* getRoot();

};

#endif /* __AVLTREE_H__*/