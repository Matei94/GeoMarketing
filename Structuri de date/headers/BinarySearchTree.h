#ifndef __BINARY_SEARCH_TREE__H
#define __BINARY_SEARCH_TREE__H

#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
private:
  BinarySearchTree<T> *leftNode;
  BinarySearchTree<T> *rightNode;
  BinarySearchTree<T> *parent;
  T *pData;
public:
	BinarySearchTree();

	~BinarySearchTree();

	bool isEmpty();

	void insertKey(T x);

	BinarySearchTree<T>* searchKey(T x);

	void inOrderDisplay();

	BinarySearchTree<T>* removeKey(T x);
		

};

#endif // __BINARY_SEARCH_TREE_H
