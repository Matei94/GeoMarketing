#include<iostream>
#include "AvlNode.h"

template< class T>
AvlNode<T>::AvlNode( T k, AvlNode<T> *p) : key( k ), balance( 0 ), parent( p ), left( NULL ), right( NULL ){}

template< class T>
AvlNode<T>::~AvlNode() {
	delete left;
	delete right;
}

template<class T>
void AvlNode<T>::inorder( ){
	if( left != NULL )
		left->inorder();
	std::cout<<key<<"\n";
	if( right != NULL )
		right->inorder();
}

template class AvlNode<int>;
