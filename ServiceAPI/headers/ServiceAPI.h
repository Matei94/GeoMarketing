#ifndef __SERVICEAPI_H_
#define __SERVICEAPI_H_

#include <iostream>

#include "../../Structuri de date/headers/AvlTree.h"
#include "../../Structuri de date/headers/Hashtable.h"
#include "../../Structuri de date/headers/Arbore.h"
#include "../../Structuri de date/headers/ResizableArray.h"
#include "../../Structuri de date/headers/ListOfHeaps.h"

using namespace std;

template<typename T>
struct Array {
    int resultSize;
    T* resultData;

    Array() {
        resultSize = 0;
        resultData = NULL;
    }

    Array( int resultSize ) {
        this->resultSize = resultSize;
        this->resultData = new T[ resultSize + 1 ];
    }

    Array(int resultSize, T* resultData) :
        resultSize(resultSize), resultData(resultData) {}

    void insert( int position, T value ) {
        resultData[ position ] = value;
    }

    Array( const Array& other ) {
        this->resultSize = other.resultSize;
        this->resultData = other.resultData;        
    }

    void operator=( const Array& other ) {
        this->resultSize = other.resultSize;
        this->resultData = other.resultData;
    }

    void operator[]( int position ) {

        if( position >= resultSize ) {
            cout << "Boss, nu esti in zona de memorie buna in Array.\n";
            return T();
        }

        return resultData[ position ];
    }

};

inline int sdbm( int key ) {
    unsigned long hash = 0;

    while( key ) {
        hash = ( ( key % 10 ) + '0' ) + ( hash << 6 ) + ( hash << 16 ) - hash;
        key = key / 10;
    }

    return hash % 65599;

}


class Service {

  private:

    /* t - AVL ul pe care il folosim pentru primele (sub)task-uri */
    AvlTree<int> t;

    /* mapMagazine - hashtable-ul in care vom retine informatiile aferente magazinelor */
    Hashtable<int, infoMagazin> mapMagazine;

    /* mapUsers - hashtable-ul in care vom retine informatiile aferente userilor */
    Hashtable<int, infoUser> mapUsers;

    /* listOfTrees - lista in care vom retine informatii cu privire la fiecare arbore in parte */
    Arbore listOfTrees;

    /* adjacencyList - lista de adiacenta aferenta grafului de useri */
    ResizableMatrix< int > adjacencyList;

    /* distantePerMagazin - heap-ul in care se retin distantele de la user la magazine */
    ListOfHeaps<int> distantePerMagazin;

    /* discountPerMagazin - heap-ul in care se retin discount-urile acordate la fiecare magazin */
    ListOfHeaps<int> discountPerMagazin;

    /* nrUsers - numarul de utilizatori ai aplicatiei */
    int nrUsers;

    /* nrMagazine - numarul de magazine  */
    int nrMagazine;

    /* reverseIdUsers - vectorul in care retinem carui index ii corespunde ce idUser */
    ResizableArray< int > reverseIdUsers;

    /* areParinte - vectorul de tip bool care retine daca nodul curent are sau nu parinte */
    ResizableArray< bool > areParinte;

  public:

    /* Extragerea valorii nrUsers */
    int getNrUsers();

    /* Extragerea valorii nrMagazine */
    int getNrMagazine();

    /* Setarea valorii nrUsers */
    void setNrUsers( int value );

    /* Setarea valorii nrMagazine */
    void setNrMagazine( int );


    void createUser(int id, double homeX, double homeY);
    void createStore(int id, double storeX, double storeY);

    // discount = -1 daca userul nu a cumparat nimic si, astfel nu s-a acordat discount
    void visit(int timestamp, int clientId, int storeId, int discount);
    void invite(int userWhichInvites, int invitedUser);

    int visitsInTimeframe(int startTime, int endTime);

    int totalDiscountInTimeframe(int startTime, int endTime);

    // Returneaza un Array cu id-urile user-ilor
    Array<int> usersWithBestBuyToDiscountRate();

    int visitsInTimeframeOfStore(int startTime, int endTime, int storeId);

    Array<int> biggestKDiscounts(int K, int storeId);

    Array<double> biggestKClientDistances(int K, int storeId);

    // Returneaza un array cu intervalele de timp. Fiecare pair contine startTime, endTime
    Array<pair<int, int> > mostCrowdedKTimeFrames(int K, int storeId);

    // Returneaza un array cu dimensiunile grupurilor de utilizatori
    Array<int> distinctGroupsOfUsers();

    int userWithMostInvites();

    // Lungimea celui mai lung lant de invitatii
    int longestInvitesChainSize();

    // Id-urile grupurilor cu cele mai multe invitatii overall
    // Id-ul unui grup se considera minimul id-urilor utilizatorilor din acel grup
    Array<int> topKGroupsWithMostVisitsOverall(int K);

    // O lista de perechi de forma (idGrup, numarMediuDeVizite)
    // Id-ul unui grup se considera minimul id-urilor utilizatorilor din acel grup
    Array<pair<int, double> > averageVisitsPerUser();

    // Returneaza latitudine si longitudine pentru locatia recomandata pentru un nou magazin
    pair<double, double> newStoreCoordinates();
};

#endif /* __CITIRE_H_ */
