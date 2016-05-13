#include "../headers/BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	this->leftNode = NULL;
	this->rightNode = NULL;
	this->parent = NULL;
	this->pData = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	if(leftNode != NULL) {
		delete leftNode;
	}
	if(rightNode != NULL) {
		delete rightNode;
	}
	if(pData != NULL) {
		delete pData;
	}
}

bool BinarySearchTree::isEmpty() {
	return (pData == NULL);
}

void BinarySearchTree::insertKey(T x) {
	if(pData == NULL) {
		pData = new T;
		*pData = x;
		return;
	}
	if(x < *pData) {
		if(leftNode == NULL) {
			leftNode = new BinarySearchTree<T>;
			leftNode->parent = this;
		}
		leftNode->insertKey(x);
	}
	else {
		if(rightNode == NULL) {
			rightNode = new BinarySearchTree<T>;
			rightNode->parent = this;
		}
		rightNode->insertKey(x);
	}
	
}

BinarySearchTree::BinarySearchTree<T>* searchKey(T x) {
	if(pData == NULL) {
		return NULL;
	}
	if(x == *pData) {
		return this;
	}
	else if(x < *pData && leftNode != NULL) {
		return leftNode->searchKey(x);
	}
	else if(rightNode != NULL) {
		return rightNode->searchKey(x);
	}
	return NULL;
}

void BinarySearchTree::inOrderDisplay() {
	if(pData == NULL) {
		return;
	}
	if(leftNode != NULL) {
		leftNode->inOrderDisplay();
	}
	cout<<*pData<<" ";
	if(rightNode != NULL) {
		rightNode->inOrderDisplay();
	}
}

BinarySearchTree::BinarySearchTree<T>* removeKey(T x) {
	if(pData == NULL) {
		return this;
	}

	if(x == *pData) {
		if(leftNode == NULL) {
			if(rightNode == NULL) {
				if(parent != NULL) {
					if(parent->leftNode == this) {
						parent->leftNode = NULL;
					}
					else {
						parent->rightNode = NULL;
					}
					delete this;
					return NULL;
				}
				else {
					delete pData;
					pData = NULL;
					return this;
				}
			}
			else {
				BinarySearchTree<T>* aux = rightNode;
				if(parent != NULL) {
					if(parent->leftNode == this) {
						parent->leftNode = rightNode;
					}
					else {
						parent->rightNode = rightNode;
					}
					rightNode->parent = parent;
					rightNode = NULL;
					delete this;
					return aux;
				}
				else {
					rightNode->parent = NULL;
					rightNode = NULL;
					delete this;
					return aux;
				}
			}
		}
		if(rightNode == NULL) {
			BinarySearchTree<T>* aux = leftNode;
			if(parent != NULL) {
				if(parent->leftNode == this) {
					parent->leftNode = leftNode;
				}
				else {
					parent->rightNode = leftNode;
				}
				leftNode->parent = parent;
				leftNode = NULL ;
				delete this;
				return aux;
			}
			else {
				leftNode->parent = NULL;
				leftNode = NULL;
				delete this;
				return aux;
			}
		}
		else {
			BinarySearchTree<T>* aux = leftNode;
			while(aux->rightNode != NULL) {
				aux = aux->rightNode;
		}

			*pData = *(aux->pData);

			if(aux->leftNode == NULL) {
				if(aux->parent->leftNode == aux) {
						aux->parent->leftNode = NULL;
				}
				else {
					aux->parent->rightNode = NULL;
				}
				delete aux;
				return this;
			}
			else {
				BinarySearchTree<T>* aux2 = aux->leftNode;
				if(aux->parent->leftNode == aux) {
					aux->parent->leftNode = aux2;
				}
				else {
					aux->parent->rightNode = aux2;
				}
				aux->leftNode->parent = parent;
				aux->leftNode = NULL;
				delete aux;
				return this;
			}
		}

	}
	else if(x < *pData) {
		if(leftNode != NULL) {
			leftNode = leftNode->removeKey(x);
		}
	}
	else {
		if(rightNode != NULL) {
			rightNode = rightNode->removeKey(x);
		}
	}


	return this;
}


