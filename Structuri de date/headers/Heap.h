#ifndef __HEAP_H_
#define __HEAP_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Heap {
  private:
    int size, capacity;
    T* hip;

  public:

    /* Constructor Default */
    Heap();

    /* Constructor */
    Heap( int length );

    /* Destructor */
    ~Heap( );

    /* Copy-Constructor */
    Heap( const Heap<T>& other );

    /* Suprascrierea operatorului = */
    void operator=( const Heap<T>& other );

    /* Pseudo-supraincarcarea operatorului + */
    void operator+( const Heap<T>& other );

    /* Adauga un element in heap */
    void insert( T value );

    /* Urca un element in heap */
    void moveUp( int currentIndex );

    /* Coboara un element in heap */
    void moveDown( int currentIndex );

    /* Schimba pozitiile a doua valori in heap */
    void swapValues( int index1, int index2 );

    /* Returneaza si extrage elementul din varful heap-ului, dar verifica si daca heap-ul este sau nu gol */
    bool getMaxim( T& hipMaxim );

};

#endif /* __HEAP_H */
