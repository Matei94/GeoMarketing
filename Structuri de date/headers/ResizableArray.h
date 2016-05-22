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

	/* Copy-constructor */
	ResizableArray( const ResizableArray& other );

	/* Supraincarcarea operatorului de asignare */
	void operator=( const ResizableArray& other );

	/* Supraincarcarea operatorului de accesare */
	T operator[]( unsigned long long position );

	/* Functia de adaugare pe ultima pozitie */
	void push_back( T value );

	/* Functia de insertie la o anumita pozitie in vector */
	void insert( unsigned long long position, T value );

	/* Functia de extractie a capacity */
	unsigned long long getCapacity();

	/* Functia de extractie a size */
	unsigned long long getSize();

	/* Setter pentru array */
	void setArray( T* newArray );

	/* Functia de redimensionare */
	void resize();

	/* Metoda care returneaza valoare de pe pozitie */ 
	T getValue( unsigned long long position );
   	
   	/* Metoda care sorteaza crescator elementele vectorului */
	void sortAscending();

	/* Metoda care afiseaza elementele vectorului */
	//void printOnScreen();
};

#endif /* __RESIZABLE_ARRAY_H_ */