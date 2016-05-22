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
