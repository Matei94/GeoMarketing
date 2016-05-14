#ifndef __RESIZABLE_ARRAY__
#define __RESIZABLE_ARRAY__

using namespace std;

class ResizableArray {

	private:
		int *array;
		int capacity;
		int size;

	public:	

 	// Constructor default
	ResizableArray();
	
	// Constructor	
	ResizableArray(int capacity);

	// Destructor
	~ResizableArray();

	// Metoda de adaugare
	void AddElement(int value);

	// Metoda care returneaza valoare de pe pozitie
	// Pozitia este numerotata de la 1 
	int getValue(int position);
   	
   	// Metoda care sorteaza crescator elementele vectorului.
	void SortAscending();

	// Metoda care afiseaza elementele vectorului
	void PrintOnScreen();
};

#endif // __RESIZABLE_ARRAY__