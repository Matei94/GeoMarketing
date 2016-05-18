#include "Auxilar.h"

using namespace std;

/* 
Exemplu de timeStamp extras din csv-uri:
'2016-09-09 00:13:07' 
*/


/* Functie de extragere a lunii din timeStamp */
int getMonth( string timeStamp ) {

	/* Pe pozitiile 5 si 6 se gasesc cifrele corespunzatoare lunii in timeStamp */
	return (timeStamp[5] - '0') * 10 + (timeStamp[6] - '0');
}


/* Functie de extragere a zilei din timeStamp */
int getDay( string timeStamp ) {

	/* Pe pozitiile 8 si 9 se gasesc cifrele corespunzatoare zilei in timeStamp */
	return (timeStamp[8] - '0') * 10 + (timeStamp[9] - '0');
}


/* Functia de extragere a orei din timeStamp */
int getHour( string timeStamp ) {

	/* Pe pozitiile 11 si 12 se gasesc cifrele corespunzatoare orei in timeStamp */
	return (timeStamp[11] - '0') * 10 + (timeStamp[12] - '0'); 
}


/* Functia de extragere a minutului din timeStamp */
int getMinute( string timeStamp ) {

	/* Pe pozitiile 14 si 15 se gasesc cifrele corespunzatoare minutului in timeStamp */
	return (timeStamp[14] - '0') * 10 + (timeStamp[15] - '0');
}


/* Functia de extragere a secundei din timeStamp */
int getSecond( string timeStamp ) {

	/* Pe pozitiile 17 si 18 se gasesc cifrele corespunzatoare secundei in timeStamp */
	return (timeStamp[17] - '0') * 10 + (timeStamp[18] - '0');
}


/* Functia de conversie propriu-zisa */
int Auxilar::convertTime( string timeStamp ) {

	/* Numarul de secunde dintr-o zi, o ora, un minut */
	const int secondsInADay = 86400;
	const int secondsInAnHour = 3600;
	const int secondsInAMinute = 60;

	/* numberofDays - numarul de zile din fiecare luna dintr-un an bisect */
	int numberOfDays[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	/* secondsInAMonth - numarul de secunde de la inceputul anului pana la sfarsitul lunii curente */
	int *secondsInAMonth = new int[13];
	
	secondsInAMonth[0] = 0;
	for ( int i = 1; i < 13; ++i )
		secondsInAMonth[i] = secondsInAMonth[i-1] + numberOfDays[i] * secondsInADay;

	/* Extragem luna, ziua, ora, minutul, respectiv secunda din timeStamp-ul dat ca parametru */
	int month = getMonth( timeStamp );
	int day = getDay( timeStamp );
	int hour = getHour( timeStamp );
	int minute = getMinute( timeStamp );
	int second = getSecond( timeStamp );

	/* convertedTime - timpul convertit in secunde */
	int convertedTime = secondsInAMonth[ month - 1 ];
	convertedTime += secondsInADay * (day - 1);
	convertedTime += secondsInAnHour * hour;
	convertedTime += secondsInAMinute * minute;
	convertedTime += second;

	/* Returnam rezultatul cautat */
	return convertedTime;
}