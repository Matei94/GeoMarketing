#include "../headers/Store.h"

Store::Store( ) {
	this->idStore = 0;
	this->storex = 0;
	this->storey = 0;
	this->discountgiven = 0;
}

Store::Store( int idStore, double storex, double storey, int discountgiven ) {
	this->idStore = idStore;
	this->storex = storex;
	this->storey = storey;
	this->discountgiven = discountgiven;
}

Store::~Store( ) {
	/* Do Nothing */
}

Store::Store( const Store& obiectulStore ) {
	this->idStore = obiectulStore.idStore;
	this->storex = obiectulStore.storex;
	this->storey = obiectulStore.storey;
	this->discountgiven = obiectulStore.discountgiven;
}

void Store::operator=( const Store& obiectulStore ) {
	this->idStore = obiectulStore.idStore;
	this->storex = obiectulStore.storex;
	this->storey = obiectulStore.storey;
	this->discountgiven = obiectulStore.discountgiven;
}

int Store::getIdStore( ) {
	return idStore;
}

double Store::getStoreX( ) {
	return storex;
}

double Store::getStoreY( ) {
	return storey;
}

int Store::getDiscountGiven( ){
	return discountgiven;
}

void Store::setDiscountGiven( int discount ){
	this->discountgiven = discount; 
}