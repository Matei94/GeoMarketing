#include<iostream>
#include "../headers/AvlNode.h"

template< class T >
AvlNode<T>::AvlNode( T timestamp, AvlNode<T> *parinte, T discount, T capacity ) {
 this->timestamp = timestamp;
 this->balance = 0;
 this->parent = parent;
 this->left = NULL;
 this->right = NULL;
 this->discount = discount;
 ra = ResizableArray<T>(capacity); 
}

template< class T >
AvlNode<T>::~AvlNode() {
	delete left;
	delete right;
}

template< class T >
void AvlNode<T>::insertie( T idStore ) {
	if( this->ra.getSize() < idStore ) {
		this->ra.insert( idStore, 1 );
		this->ra.insert(0, 1);
	}
	else {
		this->ra.insert( idStore, ra[idStore] + 1 );
		this->ra.insert( 0, this->ra[0] + 1 );
	}	
}

template< class T >
void AvlNode<T>::inorder( ) {
	if( left != NULL )
		left->inorder();
	std::cout<<timestamp<<"\n";
	if( right != NULL )
		right->inorder();
}


template< class T >
void AvlNode<T>::nrVizite( T t1, T t2, int& nrVizite ) {
	 nrVizite = 0;
	if( t1 < this->timestamp )
		this->left->nrVizite( t1, t2, nrVizite );
	if( t1 <= this->timestamp && t2 >= this->timestamp )
		nrVizite += this->ra[0];
	if( t2 > this->timestamp )
		this->right->nrVizite( t1, t2, nrVizite );	
}

template< class T >
void AvlNode<T>::discountTotal( T t1, T t2, int &discountTotal ) {
	discountTotal = 0;
	if( t1 < this->timestamp )
		this->left->discountTotal( t1, t2, discountTotal );
	if( t1 <= this->timestamp && t2 >= this->timestamp )
		discountTotal += this->discount;
	if( t2 > this->timestamp )
		this->right->discountTotal( t1, t2, discountTotal );	
}

template< class T >
void AvlNode<T>::nrVizitePerMagazin( T idStore, T t1, T t2, int &nrVizite ) {
	nrVizite = 0;
	if( t1 < this->timestamp )
		this->left->nrVizitePerMagazin( idStore, t1, t2, nrVizite );
	if( t1 <= this->timestamp && t2 >= this->timestamp )
		nrVizite += this->ra[ idStore ];
	if( t2 > this->timestamp )
		this->right->nrVizitePerMagazin( idStore, t1, t2, nrVizite );	
}

template class AvlNode< int >;
