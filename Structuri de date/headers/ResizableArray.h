#ifndef __RESIZABLE_ARRAY_H_
#define __RESIZABLE_ARRAY_H_

using namespace std;

template <typename T>
class ResizableArray {
	
	T *array;
	unsigned long long capacity;
	unsigned long long size;

	
  public:

	/* Constructor default */
	ResizableArray();
	
	/* Constructor */
	ResizableArray( unsigned long long capacity );

	/* Destructor */
	~ResizableArray();

	/* Functia de adaugare */
	void push_back( T value );

	/* Functia de extractie a capacity */
	unsigned long long getCapacity();

	/* Functia de extractie a size */
	unsigned long long getSize();

	/* Metoda care returneaza valoare de pe pozitie */ 
	T getValue( unsigned long long position );
   	
   	/* Metoda care sorteaza crescator elementele vectorului */
	void sortAscending();

	/* Metoda care afiseaza elementele vectorului */
	void printOnScreen();
};

#endif /* __RESIZABLE_ARRAY_H_ */