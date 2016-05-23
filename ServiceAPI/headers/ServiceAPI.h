#ifndef __SERVICEAPI_H_
#define __SERVICEAPI_H_

#include <iostream>

#include "../../Structuri de date/headers/AvlTree.h"
#include "../../Structuri de date/headers/Hashtable.h"
<<<<<<< HEAD
#include "../../Structuri de date/headers/Arbore.h"
=======
#include "../../Structuri de date/headers/Heap.h"
#include "../../Structuri de date/headers/ResizableArray.h"
>>>>>>> a905826244d4c52ba29ed9c3429fdc54ecb4db28

using namespace std;

template<typename T>
struct Array {
    int resultSize;
    T* resultData;

    Array(int resultSize, T* resultData) :
        resultSize(resultSize), resultData(resultData) {}

<<<<<<< HEAD
    void insert( int position, T value ) {
        resultData[ position ] = value;
    }

};

inline int sdbm( int key ) {
    unsigned long hash = 0;

    while( key ) {
        hash = ( ( key % 10 ) + '0' ) + ( hash << 6 ) + ( hash << 16 ) - hash;
        key = key / 10;
    }
=======
inline int sdbm( int key ) {
    unsigned long hash = 0;

    while( key ) {
        hash = ( ( key % 10 ) + '0' ) + ( hash << 6 ) + ( hash << 16 ) - hash;
        key = key / 10;
    }

    return hash % 65599;

}
>>>>>>> a905826244d4c52ba29ed9c3429fdc54ecb4db28

    return hash % 65599;

}


class Service {

  private:

    AvlTree<int> t;
    Hashtable<int, infoMagazin> mapMagazine;
    Hashtable<int, infoUser> mapUsers;
<<<<<<< HEAD
    Arbore listOfTrees;
    ResizableMatrix<unsigned long long> adjacencyList;
=======
    unsigned long long nrUsers = 0;
    unsigned long long nrMagazine = 0;
    ResizableArray<unsigned long long> reverseIdUsers;

>>>>>>> a905826244d4c52ba29ed9c3429fdc54ecb4db28

  public:
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
