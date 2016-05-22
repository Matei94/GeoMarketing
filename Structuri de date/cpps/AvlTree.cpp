#include <iostream>
#include "../headers/AvlTree.h"

template <class T>
void AvlTree<T>::rebalance( AvlNode<T> *n ) {

	/* calculez factorul de echilibru pentru nodul n */
	setBalance( n );

	/* un AVL are factorii de echilibru ai fiecarui nod -1, 0 sau 1 */
	/* arborele nu este echilibrat in cazul in care factorul de echilibru este 2 sau -2 */
	/* pentru ca arborele va fi echilibrat "de jos in sus" , nu vom avea noduri cu factorul de echilibru >2 sau < -2 */

	/* daca balance == -2 inseamna ca in stanga avem cu 2 noduri mai multe decat in dreapta */
	if( n->balance == -2 ) {

		/* ne uitam in stanga la subarborele stang si drept */
		/* daca in "stanga lui stanga lui n atarna mai mult decat in dreapta lui stanga lui n", facem o rotatie simppla la dreapta */
		if( height( n->left->left ) >= height( n->left->right ) )
			n = rotateRight( n );

		/* invers, facem o dubla rotatie: intai la stanga si apoi la dreapta */
		else
			n = rotateLeftThenRight( n );
	}

	/* daca balance == 2, atunci in dreapta avem cu 2 noduri mai mult decat in stanga */
	else if( n->balance == 2 ) {

		/* daca in "dreapta lui dreapta lui n atarna mai mult decat in stanga lui dreapta lui n" => rotatie spre stanga */
		if( height( n->right->right ) >= height( n->right->left ) )
			n = rotateLeft( n );
		else
			n = rotateRightThenLeft( n );
	}

	/* daca parintele nodului n exista ( n nu este radacina), echilibram arborele pornind din nodul parinte */
	if( n->parent != NULL ) {
		rebalance( n->parent );
	}

	/* daca nu, radacina este n */
	else {
		root = n;
	}
}

template< class T >
AvlNode<T>* AvlTree<T>::rotateLeft( AvlNode<T> *a ) {

	/* in cazul in care efectuam o rotatie la stanga din nodul a, este evident ca exista subarborele drept al lui a */
	/* b este fiul drept lui a */
	AvlNode<T> *b = a->right;
	/* parintele lui a devine parintele lui b */

	/* parintele lui b devine parintele lui a */
	b->parent = a->parent;

	/* noul fiu drept al lui a este vechiul fiu stang al lui b*/
	a->right = b->left;

	/* daca exista noul fiul drept, ii atasez parintele a */
	if( a->right != NULL )
		a->right->parent = a;

	/* b are fiu stang pe a*/
	b->left = a;

	/* parintele lui a este b */
	a->parent = b;

	/* daca exista parintele lui b( vechiul parinte al lui a, vedem daca a era fiu drept sau stang si face legatura respectiva de la printe la b ) */
	if( b->parent != NULL ) {
		if( b->parent->right == a ) {
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	/* calculez factorul de echilibru pentru a si pentru b*/
	setBalance( a );
	setBalance( b );

	/* afisez schimbarea */
	return b;
}

template< class T >
AvlNode<T>* AvlTree<T>::rotateRight( AvlNode<T> *a ) {

	/* in cazul in care efectuam o rotatie la dreapta din nodul a, este evident ca exista subarborele stang al lui a */
	/* b este fiul stang al lui a */
	AvlNode<T> *b = a->left;

	/* vechiul parinte al lui a este noul parinte al lui b */
	b->parent = a->parent;

	/* fiul drept al lui b este noul fiu stanga al lui a */
	a->left = b->right;

	/* daca noul fiu stang al lui a exista, ii impunem parintele a */
	if( a->left != NULL )
		a->left->parent = a;

	/* a devine fiul drept al lui b */
	b->right = a;

	/* parintele lui a este b */
	a->parent = b;

	/* daca vechiul parinte al lui a exista, vedem daca a era fiu stang sau drept, si face legatura de la parinte la b */
	if( b->parent != NULL ) {
		if( b->parent->right == a ) {
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	/* calculam factorul de echilibru pentru a si pentru b */
	setBalance(a);
	setBalance(b);

	/* returam schimbarea */
	return b;
}

template< class T >
AvlNode<T>* AvlTree<T>::rotateLeftThenRight( AvlNode<T> *n ) {

	/* facem o rotatie la stanga pornind din fiul stang al lui n */
	n->left = rotateLeft( n->left );

	/* facem o rotatie la dreapta pentru n si returnam schimbarea */
	return rotateRight(n);
}

template< class T >
AvlNode<T>* AvlTree<T>::rotateRightThenLeft( AvlNode<T> *n ) {

	/* facem o rotatie la dreapta pentru fiul drept al lui n */
	n->right = rotateRight( n->right );
	
	/* facem o rotatie la stanga pentru n si returnam schimbarea */
	return rotateLeft( n );
}

template< class T >
int AvlTree<T>::height( AvlNode<T> *n ) {

	/* calcuma inaltimea subarborelui dictat de n */

	/* conditia de oprire din recursivitate */
	if (n == NULL)
	return -1;
	
	/* daca n nu este NULL se apeleaza recursiv pentru stanga si dreapta si, seface maximul dintre cele doua inaltime si se aduna cu 1 */
	return 1 + std::max( height( n->left ), height( n->right ) );
}

template< class T >
void AvlTree<T>::setBalance( AvlNode<T> *n ) {

	/* se calculeaza factorul de echilibru ca fiind diferenta dintre inaltimea subarborelui drept si a celui stang */
	n->balance = height( n->right ) - height( n->left );
}

template< class T >
void AvlTree<T>::printBalance( AvlNode<T> *n ) {
	/* parcurge graful in inordine si afiseaza gradul de echilibru al fiecarui nod */
	if (n != NULL) {
		printBalance(n->left);
		std::cout << n->balance << " \n";
		std::cout<<n->ra[0]<<"\n ";
		printBalance(n->right);
	}
}


template< class T >
AvlTree<T>::AvlTree( ) : root( NULL ) {}

template< class T >
AvlTree<T>::~AvlTree( ) {
	delete root;
}
 
template< class T >
void AvlTree<T>::insert( T timestamp, AvlNode<T>* node, T discount, T idStore ) {
		if( node == NULL ) {
			node = new AvlNode<T>( timestamp, NULL, discount, idStore );
			//node->insertie( idStore );	
		}
		else {
			if( node-> timestamp == timestamp ) {
			 	node->discount =  node->discount + discount;
		//	node->insertie( idStore );	
			}					
			else if( node->timestamp > timestamp ) {
					if( node->left == NULL ) {
						node->left = new AvlNode<T>( timestamp, node, discount, idStore );
					//	node->left->insertie( idStore ); 
					}	
					else 
						insert( timestamp, node->left, discount, idStore );
				}			
				else {
					if( node->right == NULL ) {
						node->right = new AvlNode<T>(timestamp, node, discount, idStore );
						//node->right->insertie( idStore ); 
					}	
					else
			 			insert( timestamp, node->right, discount, idStore );
				}
			}	
	rebalance(node);
	}	

template< class T >
void AvlTree<T>::printBalance() {
	printBalance( root );
	std::cout << std::endl;
}

template< class T >
AvlNode<T>* AvlTree<T>::getRoot( ) {
	return root;
}

template class AvlTree< int >;