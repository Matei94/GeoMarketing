#include <iostream>
#include "../headers/AvlTree.h"
#include "../headers/AvlNode.h"
#include "../headers/Hashtable.h"
int main( )
{
	AvlTree<int> t;

	std::cout << "Inserting integer values 1 to 10" << std::endl; 
//	for (int i = 1; i <= 10; ++i)
	t.insert(4, t.getRoot(), 5, 1 );
	t.insert(4, t.getRoot(), 5, 1 );
	//std::cout<<"pula\n";
	//std::cout<<t.getRoot()->timestamp<<"\n";
	t.insert(5, t.getRoot(), 5, 1 );
	t.insert(5, t.getRoot(), 5, 1 );
	t.insert(7, t.getRoot(), 5, 1 );
	t.insert(7, t.getRoot(), 5, 1 );
	t.insert(2, t.getRoot(), 5, 1 );
	t.insert(2, t.getRoot(), 5, 1 );
	t.insert(1, t.getRoot(), 5, 1 );
	t.insert(1, t.getRoot(), 5, 1 );
	t.insert(3, t.getRoot(), 5, 1 );
	t.insert(3, t.getRoot(), 5, 1 );
	t.insert(6, t.getRoot(), 5, 1 );
	t.insert(6, t.getRoot(), 5, 1 );
	t.insert(6, t.getRoot(), 5, 1 );
		t.insert(6, t.getRoot(), 5, 2 );
			t.insert(6, t.getRoot(), 5, 2 );


	std::cout << "Afiseaza factorul de echilibru si discountul pentru fiecare nod:\n";
//	t.printBalance();

	std::cout<<"Printing inorder\n";
	t.getRoot()->inorder();

	std::cout<<"fiul stang, fiul drept\n";
	t.getRoot()->fii();
	std::cout<<"task1.2:\n";
	int value = 0;
	t.getRoot()->discountTotal(1, 7, value);
	cout<<value<<"\n";
	value = 0;
	t.getRoot()->nrVizite( 1, 7, value );
	cout<<"nr de vizite "<<value<<"\n";
	value = 0;
	t.getRoot()->nrVizitePerMagazin( 2, 1, 7, value );
	cout<<"vizitele pe magazinul 1 "<<value<<"\n";	

	cout<<t.getRoot()->ra.getValue( 6 )<<'\n';
	cout<<t.getRoot()->ra.getSize()<<'\n';


}