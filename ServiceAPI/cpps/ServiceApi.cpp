#include "../headers/ServiceAPI.h"

	void Service::createUser(int id, double homeX, double homeY) {

    std::cout << "Inserting integer values 1 to 10" << std::endl;

    infoUser ha;
    ha.numarDeCumparaturi = 1;
    ha.numarDeVizite = 4;
    ha.discountAcordat = 5;
    ha.userX = 6;
    ha.userY = 7;

    if( mapUsers.getSize() == 0 ) {
        mapUsers.Initialize( 65599, sdbm );
    }
    mapUsers.Insert( 2, ha );
    mapUsers.printTable( );

    t.insert(4, t.getRoot());
    t.insert(5, t.getRoot());
    t.insert(7, t.getRoot());
    t.insert(2, t.getRoot());
    t.insert(1, t.getRoot());
    t.insert(3, t.getRoot());
    t.insert(6, t.getRoot());


    std::cout << "Printing balance:\n";
    t.printBalance();

    std::cout<<"Printing inorder\n";
    t.getRoot()->inorder();
	}

    void Service::createStore(int id, double storeX, double storeY) {

        infoMagazin ha;
        ha.indexRA = 1;
        ha.storeX = 6;
        ha.storeY = 7;

        if( mapMagazine.getSize() == 0 ) {
            mapMagazine.Initialize( 65599, sdbm );            
        }

        mapMagazine.Insert( 1, ha );

    }

    void Service::visit(int timestamp, int clientId, int storeId, int discount) {
        mapUsers.printTable( );
        mapMagazine.printTable( );
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

    Array<pair<int, int>> Service::mostCrowdedKTimeFrames(int K, int storeId) {

    }

    Array<int> Service::distinctGroupsOfUsers() {

    }

    int Service::userWithMostInvites() {

    }

    int Service::longestInvitesChainSize() {

    }

    Array<int> Service::topKGroupsWithMostVisitsOverall(int K) {

    }

    Array<pair<int, double>> Service::averageVisitsPerUser() {

    }

    pair<double, double> Service::newStoreCoordinates() {

    }