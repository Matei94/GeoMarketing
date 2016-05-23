#include "../headers/ServiceAPI.h"


int Service::getNrUsers() {
    return this->nrUsers;
}

int Service::getNrMagazine() {
    return this->nrMagazine;
}

void Service::setNrUsers( int value ) {
    this->nrUsers = value;
}

void Service::setNrMagazine( int value ) {
    this->nrMagazine = value;
}



void Service::createUser( int id, double homeX, double homeY ) {

    cout << "Intra aici in create user.\n";

    /* daca nu avem bucketuri in map, initializam cu 65599 nr de bucketuri */
    if( mapUsers.Hashtable< int, infoUser >::getSize( ) == 0 ) {
        mapUsers.Hashtable< int, infoUser >::Initialize( 65599, sdbm );
        
        cout << "Intra in initialize pentru mapUsers.\n";
    }

    /* Daca nu a fost deja initializat, initializam reverseIdUser */
    if( reverseIdUsers.ResizableArray< int >::getSize( ) == 0 ) {
        reverseIdUsers.ResizableArray< int >::initialize();

        cout << "reverseIdUsers:\n";
        cout << "Capacity este ... " << reverseIdUsers.ResizableArray< int >::getCapacity() << '\n';
        cout << "Size este ... " << reverseIdUsers.ResizableArray< int >::getSize() << '\n';

        //reverseIdUsers.ResizableArray< int >::push_back( 0 );

        cout << "\n";
        cout << "Capacity este ... " << reverseIdUsers.ResizableArray< int >::getCapacity() << '\n';
        cout << "Size este ... " << reverseIdUsers.ResizableArray< int >::getSize() << '\n';

        //nrUsers++;
    }

    /* Incrementam numarul de useri inregistrati */
    nrUsers++;

    cout<<id<<'\n';

    /* Aplicam "functia inversa de hash" */
    reverseIdUsers.ResizableArray< int >::insert( nrUsers, id );

        cout << "\n";
        cout << "Capacity este ... " << reverseIdUsers.ResizableArray< int >::getCapacity() << '\n';
        cout << "Size este ... " << reverseIdUsers.ResizableArray< int >::getSize() << '\n';
        cout << reverseIdUsers[ 1 ] << '\n';


    infoUser user;

    /* Initializare informatii pe care le punem in hashatble-ul mapUsers*/
    user.numarDeCumparaturi = 0;
    user.numarDeVizite = 0;
    user.discountAcordat = 0;
    user.indexUser = nrUsers;
    user.userX = homeX;
    user.userY = homeY;

    /* inserez in mapUsers la cheia id, informatia din user */
    mapUsers.Insert( id, user );

    infoUser value;
    cout << "Hash: " << mapUsers.get( id, value ) << " " << value << "\n";

    /* Initializam in lista de adiacenta linia de vecini corespunzatoare userului tocmai creat */
    adjacencyList.ResizableMatrix< int >::insert( user.indexUser, 0 );

    cout << adjacencyList.ResizableMatrix< int >::getValue( user.indexUser, 1 ) << '\n';

}

void Service::createStore(int id, double storeX, double storeY) {

    /* Intializam hashtable-ul pentru magazine, in cazul in care nu s-a facut asta deja */
    if( mapMagazine.getSize() == 0 ) {
        mapMagazine.Initialize( 65599, sdbm );            
    }

    /* Incrementam numarul de magazine inregistrate */
    nrMagazine++;

    infoMagazin mag;

    /* Initializam informatiile pe care le punem in hashtbale-ul mapMagazine */
    mag.indexRA = nrMagazine;
    mag.storeX = storeX;
    mag.storeY = storeY;

    /* Inseram in hashtable-ul de magazine, magazinul curent; cheia fiind id-ul magazinul, iar valoarea, "obiectul" mag(azin) */
    mapMagazine.Insert( id, mag );

}

void Service::visit(int timestamp, int clientId, int storeId, int discount) {
    
    /*
    mapUsers.printTable( );
    mapMagazine.printTable( );
    reverseIdUsers.printOnScreen( );
    cout<<reverseIdUsers.getValue( 3 );
    */

    /* Extragem informatiile aferente magazinului curent din hashtable */
    infoMagazin currentStore;
    mapMagazine.Hashtable< int, infoMagazin >::get( storeId, currentStore );

    /* Extragem indexul aferent magazinului curent */
    int indexMagazin = currentStore.indexRA;

    /* Inseram in AVL magazinul curent cu informatiile aferente */
    t.AvlTree< int >::insert( timestamp, t.getRoot(), discount, indexMagazin );

}

void Service::invite(int userWhichInvites, int invitedUser) {

    /* Extragem valoarea obiectului user care invita */
    infoUser value;
    mapUsers.Hashtable< int, infoUser >::get( userWhichInvites, value );
    
    /* Extragem valoarea indexului asociat userului care face invitatia */
    int indexUserWhichInvites = value.indexUser;


    /* Extragem valoarea obiectului user care invita */
    mapUsers.Hashtable< int, infoUser >::get( invitedUser, value );
    
    /* Extragem valoarea indexului asociat userului care face invitatia */
    int indexInvitedUser = value.indexUser;    


    /* Adaug relatia in lista de adiacenta */
    adjacencyList.ResizableMatrix< int >::insert( indexUserWhichInvites, indexInvitedUser );

}

int Service::visitsInTimeframe(int startTime, int endTime) {

}

int Service::totalDiscountInTimeframe(int startTime, int endTime) {

}

Array<int> Service::usersWithBestBuyToDiscountRate() {

}

int Service::visitsInTimeframeOfStore(int startTime, int endTime, int storeId) {

}

Array<int> Service::biggestKDiscounts(int K, int storeId) {

}

Array<double> Service::biggestKClientDistances(int K, int storeId) {

}

Array<pair<int, int> > Service::mostCrowdedKTimeFrames(int K, int storeId) {

}

Array<int> Service::distinctGroupsOfUsers() {

}

int Service::userWithMostInvites() {

}

int Service::longestInvitesChainSize() {

}

Array<int> Service::topKGroupsWithMostVisitsOverall(int K) {

}

Array<pair<int, double> > Service::averageVisitsPerUser() {

}

pair<double, double> Service::newStoreCoordinates() {

}