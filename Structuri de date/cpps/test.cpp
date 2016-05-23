#include <iostream>
//#include "../headers/LinkedList.h"
#include "../headers/ListOfHeaps.h"

using namespace std;

int main () {

	ListOfHeaps<int> pula;

	pula.insert(0, 123 );
	cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	pula.insert(1, 123 );
	cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	pula.insert(2, 13244443 );
	pula.insert(2, 1323 );
	cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	pula.insert(2, 2423 );
	pula.insert(2, 23 );
	pula.insert(2, 24223 );
		pula.insert(2, 24223 );
	cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	pula.insert(3, 123 );
	cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	cout<<pula.getMaxim(2)<<'\n';
	cout<<pula.getMaxim(2)<<'\n';
		cout<<pula.getMaxim(2)<<'\n';
		cout<<pula.getMaxim(2)<<'\n';
	cout<<pula.getMaxim(2)<<'\n';
	cout<<pula.getMaxim(3)<<'\n';
	//cout<<pula.getMaxim(3)<<'\n';



//	LinkedList<int> lista[10];
//	lista[2].addFirst(2);
//	cout<<lista[2].front()->getValue();

	return 0;
}