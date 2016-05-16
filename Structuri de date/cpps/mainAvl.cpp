#include<iostream>
#include "AvlTree.h"
#include "AvlNode.h"

int main( )
{
	AvlTree<int> t;

	std::cout << "Inserting integer values 1 to 10" << std::endl;
//	for (int i = 1; i <= 10; ++i)
	t.insert(4);
	t.insert(5);
	t.insert(7);
	t.insert(2);
	t.insert(1);
	t.insert(3);
	t.insert(6);


	std::cout << "Printing balance: ";
	t.printBalance();

	std::cout<<"print inorder ";
	t.getRoot()->inorder();
	return 0;
}