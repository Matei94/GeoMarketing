#include "../headers/NodeArbore.h"

using namespace std;


NodeArbore::NodeArbore() {

	this->root = 0;
	this->numberOfElements = 0;
	this->maxInvites = 0;
	this->sumVisits = 0;

}

NodeArbore::~NodeArbore() {

	/* Do nothing */

}

NodeArbore::NodeArbore( const NodeArbore& other ) {

	this->root = other.root;
	this->numberOfElements = other.numberOfElements;
	this->maxInvites = other.maxInvites;
	this->sumVisits = other.sumVisits;

}

void NodeArbore::operator=( const NodeArbore& other ) {

	this->root = other.root;
	this->numberOfElements = other.numberOfElements;
	this->maxInvites = other.maxInvites;
	this->sumVisits = other.sumVisits;

}


void NodeArbore::operator+=( const NodeArbore& other ) {
	return ;
}


int NodeArbore::getRoot() {
	return this->root;
}

int NodeArbore::getNumberOfElements() {
	return this->numberOfElements;
}

int NodeArbore::getMaxInvites() {
	return this->maxInvites;
}

int NodeArbore::getSumVisits() {
	return this->sumVisits;
}

int NodeArbore::getIdUser() {
	return this->idUser;
}

void NodeArbore::setRoot( int value ) {
	this->root = value;
}

void NodeArbore::setNumberOfElements( int value ) {
	this->numberOfElements = value;
}

void NodeArbore::setMaxInvites( int value ) {
	this->maxInvites = value;
}

void NodeArbore::setSumVisits( int value ) {
	this->sumVisits = value;
}

void NodeArbore::setIdUser( int value ) {
	this->idUser = value;
}




