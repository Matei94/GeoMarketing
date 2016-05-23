#include "../headers/ServiceAPI.h"

	void Service::createUser( int id, double homeX, double homeY ) {
        /* clasa user pentru utilizatorul dat */
        infoUser user;

        /* Initializare informatii pe care le punem in hashatble-ul mapUsers*/
        user.numarDeCumparaturi = 0;
        user.numarDeVizite = 0;
        user.discountAcordat = 0;
        user.userX = homeX;
        user.userY = homeY;

        /* daca nu avem bucketuri in map, initializam cu 65599 nr de bucketuri */
        if( mapUsers.getSize() == 0 ) {
            mapUsers.Initialize( 65599, sdbm );
        }

    infoUser ha;
    ha.numarDeCumparaturi = 1;
    ha.numarDeVizite = 4;
    ha.discountAcordat = 5;
    ha.indexUser = 3;
    ha.userX = 6;
    ha.userY = 7;

    if( mapUsers.getSize() == 0 ) {
        mapUsers.Initialize( 65599, sdbm );
    }
    mapUsers.Insert( 2, ha );
  //  mapUsers.printTable( );
    std::cout << "Inserting integer values 1 to 10" << std::endl; 
//  for (int i = 1; i <= 10; ++i)
    t.insert(4, t.getRoot(), 5, 1 );
    t.insert(4, t.getRoot(), 5, 1 );
    //std::cout<<"pula\n";
    //std::cout<<t.getRoot()->timestamp<<"\n";
    t.insert(5, t.getRoot(), 5, 1 );
    t.insert(5, t.getRoot(), 5, 1 );
    t.insert(7, t.getRoot(), 5, 1 );
    t.insert(7, t.getRoot(), 5, 1 );
    t.insert(2, t.getRoot(), 5, 1 );
    t.insert(2, t.getRoot(), 5, 1 );
    t.insert(1, t.getRoot(), 5, 1 );
    t.insert(1, t.getRoot(), 5, 1 );
    t.insert(3, t.getRoot(), 5, 1 );
    t.insert(3, t.getRoot(), 5, 1 );
    t.insert(6, t.getRoot(), 5, 1 );
    t.insert(6, t.getRoot(), 5, 1 );


    std::cout << "Afiseaza factorul de echilibru si discountul pentru fiecare nod:\n";
    t.printBalance();

    std::cout<<"Printing inorder\n";
    t.getRoot()->inorder();

    std::cout<<"fiul stang, fiul drept\n";
    t.getRoot()->fii();
    std::cout<<"task1.2:\n";
    int value = 0;
    t.getRoot()->discountTotal(1, 7, value);
    cout<<value<<"\n";
    value = 0;
    t.getRoot()->nrVizite( 1, 7, value );
    cout<<"nr de vizite "<<value<<"\n";
    value = 0;
    t.getRoot()->nrVizitePerMagazin( 1, 1, 7, value );
    cout<<"vizitele pe magazinul 1 "<<value<<"\n";  


	}
        /* inserez in mapUsers la cheia id, informatia din user */
        mapUsers.Insert( id, user );

        /* afisez hashtable ul*/
        mapUsers.printTable( );
}

    void Service::createStore(int id, double storeX, double storeY) {

        if( mapMagazine.getSize() == 0 ) {
            mapMagazine.Initialize( 65599, sdbm );            
        }

        nrMagazine++;

        infoMagazin mag;
        mag.indexRA = nrMagazine;
        mag.storeX = storeX;
        mag.storeY = storeY;

        mapMagazine.Insert( id, mag );

    }

    void Service::visit(int timestamp, int clientId, int storeId, int discount) {
       // mapUsers.printTable( );
   /*     mapUsers.printTable( );
        mapMagazine.printTable( );
    */}

    void Service::invite(int userWhichInvites, int invitedUser) {

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