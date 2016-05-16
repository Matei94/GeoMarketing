#include "../headers/User.h"

User::User( ) {
	this->idUser = 0;
	this->homex = 0;
	this->homey = 0;
}

User::User( int idUser, double homex, double homey ) {
	this->idUser = idUser;
	this->homex = homex;
	this->homey = homey;
}

User::~User(){
	/* Do Nothing */
}

User::User( const User& obiectulUser ) {
	this->idUser = obiectulUser.idUser;
	this->homex = obiectulUser.homex;
	this->homey = obiectulUser.homey;
}

void User::operator= ( const User& obiectulUser ) {
	this->idUser = obiectulUser.idUser;
	this->homex = obiectulUser.homex;
	this->homey = obiectulUser.homey;
}

int User::getIdUser( ) {
	return idUser;
}

double User::getHomeX( ) {
	return homex;
}

double User::getHomeY( ){
	return homey;
}