#ifndef __AVLNODE_H__
#define __AVLNODE_H__

template< class T>
class AvlNode {
public:
	T key;
	int balance;
	AvlNode<T> *left, *right, *parent;
	AvlNode( T key, AvlNode<T>* p);
	~AvlNode();
	void inorder();
};

#endif /* __AVLNODE_H__*/
