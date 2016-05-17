#include <iostream>

#include "../headers/ResizableArray.h"

using namespace std;
 
int main() {
 
	// Initializarea (alocarea vectorului intern). Presupunem ca are o dimensiune n;
	unsigned long long n;
	std::cout << "n = ";
	std::cin >> n;

	// Declararea unui element de tip ResizableArray
	ResizableArray<int> ra(n); 
 
	// Citirea si adaugarea a n elemente.
	for ( int i = 0; i < n; ++i ) {
		int x; // al i-lea element citit de la tastatura
		std::cin >> x;
		ra.push_back(x);
 
		// Observatie: Capacitatea vectorului intern nu se modifica.
		std::cout << "Dimensiune: " << ra.getSize() << " Capacitate " << ra.getCapacity() << '\n';
	}
 
	// Afisare continut vector
	//ra.printOnScreen();
 
	// Vom adauga in continuare inca m elemente;
	int m;
	std::cout << "m = ";
	std::cin >> m;
	for ( int i = 0; i < m; ++i ) {
		int x; // al i-lea element citit de la tastatura
		std::cin >> x;
		ra.push_back(x);
 
		// Observatie: Se poate modifica capacitatea vectorului intern!
		std::cout << "Dimensiune: " << ra.getSize() << " Capacitate " << ra.getCapacity() << '\n';
	}
 
	// Afisare continut vector
	std::cout << "Inainte de sortare\n";
	//ra.printOnScreen();
 
	// Vom sorta elementele apoi vom afisa din nou continutul.
	//ra.sort();
	std::cout << "Dupa sortare\n";
	//ra.printOnScreen();
 
	// Eliberare memorie	
	//ra.~ResizableArray();
 
	return 0;
}