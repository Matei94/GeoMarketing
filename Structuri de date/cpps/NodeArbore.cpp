#include "../headers/NodeArbore.h"

using namespace std;


NodeArbore::NodeArbore() {

	this->root = 0;
	this->numberOfElements = 0;
	this->maxInvites = 0;
	this->sumVisitis = 0;

}

NodeArbore::~NodeArbore() {

	/* Do nothing */

}

NodeArbore::NodeArbore( const NodeArbore& other ) {

	this->root = other.root;
	this->numberOfElements = other.numberOfElements;
	this->maxInvites = other.maxInvites;
	this->sumVisitis = other.sumVisitis;

}

void NodeArbore::operator=( const NodeArbore& other ) {

	this->root = other.root;
	this->numberOfElements = other.numberOfElements;
	this->maxInvites = other.maxInvites;
	this->sumVisitis = other.sumVisitis;

}


unsigned long long NodeArbore::getRoot() {
	return this->root;
}

unsigned long long NodeArbore::getNumberOfElements() {
	return this->numberOfElements;
}

unsigned long long NodeArbore::getmaxInvites() {
	return this->maxInvites;
}

unsigned long long NodeArbore::getSumVisits() {
	return this->sumVisitis;
}

void NodeArbore::setRoot( unsigned long long value ) {
	this->root = value;
}

void NodeArbore::setNumberOfElements( unsigned long long value ) {
	this->numberOfElements = value;
}

void NodeArbore::setMaxInvites( unsigned long long value ) {
	this->maxInvites = value;
}

void NodeArbore::setSumVisits( unsigned long long value ) {
	this->maxInvites = value;
}








