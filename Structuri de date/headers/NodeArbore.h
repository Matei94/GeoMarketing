#ifndef __NodeArbore_H_
#define __NodeArbore_H_

/* NodeArbore - retine informatii cu privire la arborele curent */
class NodeArbore {

	/* root - radacina arborelui curent */
	unsigned long long root;

	/* numberOfElements - numarul de elemente al arborelui curent */
	unsigned long long numberOfElements;

	/* maxInvites - numarul maxim de invitatii pe care l-a trimis unul dintre userii din arborele curent */
	unsigned long long maxInvites;

	/* sumVisitis - numarul total de vizite pe care le-au facut userii din arborele curent */
	unsigned long long sumVisits;


  public:

	/* Constructor default */
	NodeArbore();

	/* Destructor */
	~NodeArbore();

	/* Copy-Constructor */
	NodeArbore( const NodeArbore& other );

	/* Suprascrierea operatorului de asignare */
	void operator=( const NodeArbore& other );

	/* Returneaza valoarea lui root */
	unsigned long long getRoot();

	/* Returneaza valoarea lui numberOfElements */
	unsigned long long getNumberOfElements();

	/* Returneaza valoarea lui maxInvites */
	unsigned long long getMaxInvites();

	/* Returneaza valoarea lui sumVisits */
	unsigned long long getSumVisits();

	/* Atribuie lui root o noua valoare */
	void setRoot( unsigned long long value );

	/* Atribuie lui numberOfElements o noua valoare */
	void setNumberOfElements( unsigned long long value );

	/* Atribuie lui maxInvites o noua valoare */
	void setMaxInvites( unsigned long long value );

	/* Atribuie lui sumVisits o noua valoare */
	void setSumVisits( unsigned long long value );

};


#endif /* __NodeArbore_H_ */