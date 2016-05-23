#include<iostream>
#include "../headers/AvlNode.h"

template< class T >
AvlNode<T>::AvlNode( T timestamp, AvlNode<T> *parinte, T discount ) {
 this->timestamp = timestamp;
 this->balance = 0;
 this->parent = parent;
 this->left = NULL;
 this->right = NULL;
 this->discount = discount;
 //ResizableArray<T> ra();
 ra.initialize( );
}

template< class T >
AvlNode<T>::~AvlNode() {
	if( left != NULL )
		delete left;
	if( right != NULL )
		delete right;	
}

template< class T >
void AvlNode<T>::insertie( T idStore ) {
	//std::cout<<"size: "<<ra.getSize()<<"\n";
	//std::cout<<"capacity: "<<ra.getCapacity()<<"\n";
	//std::cout<<ra[idStore]<<"\n un cacat\n";
	this->ra.insertInPlus( idStore, 1);
	this->ra.insertInPlus( 0, 1);
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
	if( t1 < this->timestamp ) {
		if( left != NULL )
		this->left->nrVizite( t1, t2, nrVizite );
	}

	if( t1 <= this->timestamp && t2 >= this->timestamp )
		nrVizite += this->ra[0];
	
	if( t2 > this->timestamp ) {
		if( right != NULL )
		this->right->nrVizite( t1, t2, nrVizite );	
	}
}

template< class T >
void AvlNode<T>::discountTotal( T t1, T t2, T &value ) {

	if( t1 < this->timestamp ) {
		if( left != NULL)
		this->left->discountTotal( t1, t2, value );
	}

	if( t1 <= this->timestamp && t2 >= this->timestamp )
		value += this->discount;
	
	if( t2 > this->timestamp ) {
		if( right != NULL )
		this->right->discountTotal( t1, t2, value );	
	}
}

template< class T >
void AvlNode<T>::nrVizitePerMagazin( T idStore, T t1, T t2, int &nrVizite ) {
	
	if( t1 < this->timestamp ) {
		if( left != NULL )
			this->left->nrVizitePerMagazin( idStore, t1, t2, nrVizite );
	}

	if( t1 <= this->timestamp && t2 >= this->timestamp )
		if( this->ra.getCapacity() > idStore )
			nrVizite += this->ra[ idStore ];
	
	if( t2 > this->timestamp ){
		if( right != NULL )
			this->right->nrVizitePerMagazin( idStore, t1, t2, nrVizite );	
	}
}

template < class T>
void AvlNode<T>::fii() {
	cout<<left->timestamp<<" "<<right->timestamp<<" \n";
}
template class AvlNode< int >;
