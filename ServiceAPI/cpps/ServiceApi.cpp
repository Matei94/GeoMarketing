#include "../headers/ServiceAPI.h"

	void Service::createUser( int id, double homeX, double homeY ) {

        /* daca nu avem bucketuri in map, initializam cu 65599 nr de bucketuri */
        if( mapUsers.getSize( ) == 0 ) {
            mapUsers.Initialize( 65599, sdbm );
        }

        if( reverseIdUsers.getSize( ) == 0 ) {
            reverseIdUsers.initialize();
            reverseIdUsers.push_back( 0 );
            nrUsers++;
        }

        cout<<id<<'\n';
        reverseIdUsers.push_back( id );
        nrUsers++;

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
        mapUsers.printTable( );
        mapMagazine.printTable( );
        reverseIdUsers.printOnScreen( );
        cout<<reverseIdUsers.getValue( 3 );
    }

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