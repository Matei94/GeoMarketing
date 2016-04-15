#include <iostream>
using namespace std;

template<typename T>
struct Array {
    int resultSize;
    T* resultData;

    Array(int resultSize, T* resultData) :
        resultSize(resultSize), resultData(resultData) {}
};

class Service {
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
    Array<pair<int, int>> mostCrowdedKTimeFrames(int K, int storeId);

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
    Array<pair<int, double>> averageVisitsPerUser();

    // Returneaza latitudine si longitudine pentru locatia recomandata pentru un nou magazin
    pair<double, double> newStoreCoordinates();
};
