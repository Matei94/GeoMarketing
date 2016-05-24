#include <iostream>
//#include "../headers/LinkedList.h"
#include "../headers/ListOfHeaps.h"

using namespace std;

int main () {

	ListOfHeaps<int> pula;

	pula.initHeap( 0 );
//	pula.insert(0, 123 );
//	pula.insert(0, 1239 );
	//cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	pula.initHeap( 1 );
	pula.insert(1, 123 );
	pula.insert(1, 9923 );
	pula.insert(1, 923 );
	//cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	//pula.initHeap( 2 );
//	pula.insert(2, 13244443 );
//	pula.insert(2, 1323 );
	cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
/*	pula.insert(2, 2423 );
	pula.insert(2, 23 );
	pula.insert(2, 24223 );
	pula.initHeap( 3 );
	pula.insert(3, 13244443 );
	pula.insert(3, 1323 );
	//cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	pula.insert(3, 2423 );
	pula.insert(3, 23 );
	pula.insert(3, 24223 );
	//cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	pula.initHeap( 4 );
	pula.insert(4, 123 );
	pula.insert(4, 2423 );
	pula.insert(4, 23 );
	pula.insert(4, 24223 );
*/	//pula.initHeap( 5 );
	//pula.insert(5, 2414141);
	//cout<<pula.getNumberOfHeaps()<<' '<<pula.getCapacity()<<"\n";
	cout<<pula.getMaxim(1)<<'\n';
	//cout<<pula.getMaxim(2)<<'\n';
	//	cout<<pula.getMaxim(2)<<'\n';
	//	cout<<pula.getMaxim(2)<<'\n';
	//cout<<pula.getMaxim(3)<<'\n';
	//cout<<pula.getMaxim(3)<<'\n';
	//	cout<<pula.getMaxim(3)<<'\n';
	//	cout<<pula.getMaxim(3)<<'\n';
	//cout<<pula.getMaxim(4)<<'\n';
	//cout<<pula.getMaxim(5)<<'\n';
	//cout<<pula.getMaxim(5)<<'\n';
	//for( int i = 0; i < 6; i++)
	//	cout<<pula.getSizeHeap(i)<<' ';
	//cout<<pula.getMaxim(3)<<'\n';

	//	cout<<pula.getMaxim(1)<<'\n';
	//		cout<<pula.getMaxim(1)<<'\n';
/*
	int v[4];
	cout<<"\n";
	cout<<pula.getMaxim(1)<<'\n';
	pula.topK( 1, 4, v );
	for (int i = 0; i < 4; ++i)
	{
		cout<<v[i]<<' ';
	}
	cout<<"\n";
	cout<<pula.getMaxim(1)<<'\n';
	pula.topK( 1, 4, v );
	for (int i = 0; i < 4; ++i)
	{
		cout<<v[i]<<' ';
	}
	cout<<"\n";
*/

	return 0;
}