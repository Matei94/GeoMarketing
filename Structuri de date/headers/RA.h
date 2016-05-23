#ifndef __RESIZABLE_ARRAY_H_
#define __RESIZABLE_ARRAY_H_

using namespace std;

template <typename T>
class ResizableArray {
	
	T *array;
	int capacity;
	int size;

	
  public:

	/* Constructor default */
	ResizableArray();
	
	/* Constructor */
	ResizableArray( int capacity );

	/* Destructor */
	~ResizableArray();

	/* Copy-constructor */
	ResizableArray( const ResizableArray& other );

	/* Supraincarcarea operatorului de asignare */
	void operator=( const ResizableArray& other );

	/* Supraincarcarea operatorului de accesare */
	T operator[]( int position );

	/* Functia de adaugare pe ultima pozitie */
	void push_back( T value );

	/* Functia de insertie la o anumita pozitie in vector */
	void insert( int position, T value );

	/* Functia de extractie a capacity */
	int getCapacity();

	/* Functia de extractie a size */
	int getSize();

	/* Setter pentru array */
	void setArray( T* newArray );

	/* Functia de redimensionare */
	void resize();

	/* Metoda care returneaza valoare de pe pozitie */ 
	T getValue( int position );
   	
   	/* Metoda care sorteaza crescator elementele vectorului */
	void sortAscending();

	/* Metoda care afiseaza elementele vectorului */
	//void printOnScreen();
};

#endif /* __RESIZABLE_ARRAY_H_ */