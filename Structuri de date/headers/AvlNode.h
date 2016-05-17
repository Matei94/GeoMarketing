/* Clasa AvLNode repr. ce informatii contine un nod al AVL-ului*/

#ifndef __AVLNODE_H__
#define __AVLNODE_H__

template< class T>
class AvlNode {
	public:

		/* informatia din nod */
		T key;

		/* factorul de echilibru: inaltimea subarborelui drept - inaltimea sub. stang */
		int balance;

		/* copii si parintele */
		AvlNode<T> *left, *right, *parent;

		/* constructor care ii da cheia si parintele */
		AvlNode( T key, AvlNode<T>* p);

		/* destructor */
		~AvlNode();

		/* parcurgerea in inordine */
		void inorder();
};

#endif /* __AVLNODE_H__*/
