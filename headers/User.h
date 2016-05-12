#ifndef __User_H_
#define __User_H_

class User {
	private:
		int idUser;
		double homex;
		double homey;

	public:

		/* Constructor default */
		User( );

		/* Constructor */
		User( int idUser, double homex, double homey );

		/* Destructor */
		~User( );

		/* Copy assignment */
		User( const User& obiectulUser );

		/* Suprascrierea operatorului de atribuire */
		void operator=( const User& obiectulUser );

		/* Extragere iduser */
		int getIdUser( );

		/* Extragere homex */
		double getHomeX( );

		/* Extragere homey */
		double getHomeY( );

};

#endif // __User_H_