/* Clasa AvLNode repr. ce informatii contine un nod al AVL-ului*/

#ifndef __AVLNODE_H__
#define __AVLNODE_H__

#include "../headers/ResizableArray.h"

template< class T>
class AvlNode {
	public:

		/* timpestampul din nod */
		T timestamp;
		T discount;
		ResizableArray<T> ra;
		/* factorul de echilibru: inaltimea subarborelui drept - inaltimea sub. stang */
		int balance;

		/* copii si parintele */
		AvlNode<T> *left, *right, *parent;

		/* constructor care ii da cheia si parintele */
		AvlNode( T timestamp, AvlNode<T>* p, T discount);

		/* functia care imi modifica nr de vizite si total si pentru idStore */
		void insertie( T idStore );

		/* destructor */
		~AvlNode();

		/* parcurgerea in inordine */
		void inorder();

		/* returneaza fiul stang si fiul drept( timpestampurile)*/
		void fii();

		/* metoda pentru task1.1: calculam nr de vizite intre timestampul t1 si y2*/
		void nrVizite( T t1, T t2 ,int &nrVizite );

		/* metoda pentru task 1.2: face discountul total intre t1 si t2 */
		void discountTotal( T t1, T t2, T &value);

		/* metoda pentru task 2.1: facem nr de vzite pentru un magazin dat */
		void nrVizitePerMagazin( T idStore, T t1, T t2, int &nr );	

};

#endif /* __AVLNODE_H__*/
