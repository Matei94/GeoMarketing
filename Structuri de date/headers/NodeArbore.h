#ifndef __NodeArbore_H_
#define __NodeArbore_H_

/* NodeArbore - retine informatii cu privire la arborele curent */
class NodeArbore {

	/* root - radacina arborelui curent */
	int root;

	/* numberOfElements - numarul de elemente al arborelui curent */
	int numberOfElements;

	/* maxInvites - numarul maxim de invitatii pe care l-a trimis unul dintre userii din arborele curent */
	int maxInvites;

	/* idUser - id-ul userului cu cei mai multi utilizatori invitati de catre el */
	int idUser;

	/* sumVisitis - numarul total de vizite pe care le-au facut userii din arborele curent */
	int sumVisits;


  public:

	/* Constructor default */
	NodeArbore();

	/* Destructor */
	~NodeArbore();

	/* Copy-Constructor */
	NodeArbore( const NodeArbore& other );

	/* Suprascrierea operatorului de asignare */
	void operator=( const NodeArbore& other );

	/* Suprascrierea operatorului + */
	void operator+( const NodeArbore& other );

	/* Suprascrierea operatorului += */
	void operator+=( const NodeArbore& other );

	/* Returneaza valoarea lui root */
	int getRoot();

	/* Returneaza valoarea lui numberOfElements */
	int getNumberOfElements();

	/* Returneaza valoarea lui maxInvites */
	int getMaxInvites();

	/* Returneaza valoarea lui sumVisits */
	int getSumVisits();

	/* Returneaza valoarea lui idUser */
	int getIdUser();

	/* Atribuie lui root o noua valoare */
	void setRoot( int value );

	/* Atribuie lui numberOfElements o noua valoare */
	void setNumberOfElements( int value );

	/* Atribuie lui maxInvites o noua valoare */
	void setMaxInvites( int value );

	/* Atribuie lui sumVisits o noua valoare */
	void setSumVisits( int value );

	/* Atribuie lui idUser o noua valoare */
	void setIdUser( int value );

};


#endif /* __NodeArbore_H_ */