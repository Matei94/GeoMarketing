/*

Intelegerea pe deplin a hashtable-ului a fost facuta la site-ul acesta: 
"https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250#.1c96qyu6p"

Logica Hashtable-ului nostru este in principiu exacta cu cea de la site-ul de sus avand mici modificari.
(nu s-a dat nicio secunda copy-paste, dar cum s-a zis, implementarea noastra a fost masiv influentata de ideea site-ului de mai sus)

*/

#ifndef __Hashtable_H_
#define __Hashtable_H_

#include <iostream>

using namespace std;


struct infoMagazin {
	int indexRA;
	double storeX;
	double storeY;

	void operator= ( const infoMagazin& mag ) {
		this->indexRA = mag.indexRA;
		this->storeX = mag.storeX;
		this->storeY = mag.storeY;
	}

	friend ostream& operator<< ( ostream& out, const infoMagazin& mag ) {
		out << " InfoMagazin { indexRA, storeX, storeY }: { " << mag.indexRA << ", " << mag.storeX << ", " << mag.storeY << " }";
		return out;
	}

};

struct infoUser {
	int numarDeCumparaturi;
	int numarDeVizite;
	int discountAcordat;
	double userX;
	double userY;

	void operator= ( const infoUser& user ) {
		this->numarDeCumparaturi = user.numarDeCumparaturi;
		this->numarDeVizite = user.numarDeVizite;
		this->discountAcordat = user.discountAcordat;
		this->userX = user.userX;
		this->userY = user.userY;
	}

	friend ostream& operator<< ( ostream& out, const infoUser& user ) {
		out << " InfoUser { numarDeCumparaturi, numarDeVizite, discountAcordat, userX, userY }: { " << user.numarDeCumparaturi << ", " << user.numarDeVizite << ", " << user.discountAcordat << ", " << user.userX << ", " << user.userY << " }";
		return out;
	}

};

/* Hashnode - structura de baza a hashtable-ului; un fel de unitate de masura, care are o cheie, o valoare si o legatura cu urmatorul element */
template<typename Tkey, typename Tvalue>
struct Hashnode {
	Tkey key;
	Tvalue value;
	Hashnode *next;

};


/* Hashtable - Structura de date definita ca o clasa */
template<typename Tkey, typename Tvalue>
class Hashtable {
	/* size = numarul de bucketuri
	**Bucket - pointer la inceputul hashtable-ului */
	private:
		int size;
		int ( *Hash ) ( Tkey );
		Hashnode<Tkey,Tvalue> **Bucket;

	public:
		/* Constructorul ce primeste ca parametru numarul de bucketuri pe care il va avea hashtableul */
		Hashtable( int length, int ( *h ) ( Tkey ) );

		/* Destructor */
		~Hashtable();

		/* Functia de insertie a unui nou element in Hashtable, la cheia key si valoarea value */
		void Insert( Tkey key, Tvalue value );

		/* Functia care cauta existenta unui element la cheia key si returneaza true sau false, in functie de rezultatul cautarii, dar returneaza si valoarea pe care o are acesta,
		 prin intermediul parametrului trimis ca referinta: "value" */
		bool get ( Tkey key, Tvalue& value );

		/* Elimina primul element din bucketul aferent cheii "key" */
		void remove( Tkey key );

		/* Afiseaza hashtable-ul  */
		void printTable( );

};

#endif /* __Hashtable_H_ */