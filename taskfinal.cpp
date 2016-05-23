#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#define inf 0x3f3f3f3f
using namespace std;
/*Un punct in plan, de coordonate x, y*/
struct pct{
	double x, y;
};
/*Distanta intre doua puncte.*/
double dist(pct a, pct b){
	return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

/*Functia de interschimbare a doua puncte dintr-un vector*/
void swap(int i, int j, pct *a){
    pct temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
/*Sortarea crescatoare dupa x a unui vector de puncte, folosind algoritmul quicksort*/
void quicksort(pct *a, int left, int right){
	int mid = (left + right) / 2;

	int i = left;
	int j = right;
	pct pivot = a[mid];

	while(left < j || i < right)
	{
		while(a[i].x < pivot.x){
			i++;
		}
		while(a[j].x > pivot.x){
			j--;
		}

		if(i <= j){
			swap(i, j, a);
			i++;
			j--;
		}
		else{
			if(left < j){
				quicksort(a, left, j);
			}
			if(i < right){
				quicksort(a, i, right);
			}
			return;
		}
	}
}

int main(){
	/*Retin pozitiile userilor si magazinelor*/
	pct* magazin;
	pct* user;
	pct* start;
	pct* stop;
	pct* v;
	int** mat;
	int i, j, n, m, k;
	pct sol_poz;
	ifstream cin("date.in");
	ofstream cout("date.out");
	cin >> n >> m;
	magazin = new pct[m + 1];
	user = new pct[n + 1];
	start = new pct [n + 1];
	stop = new pct [n + 1];
	v = new pct [n + 1];
	mat = new int*[m + 1];
	for (i = 0; i <= m; i++){
		mat[i] = new int[n + 1];
	}
	for(i = 1; i <= n; i++){
		cin >> user[i].x >> user[i].y;
	}
	for(i = 1; i <= m; i++){
		cin >> magazin[i].x >> magazin[i].y;
	}
	if (m == 0 || m == 1){
		sol_poz.x = 0;
		sol_poz.y = 0;
		for (i = 1; i <= n; i++){
			sol_poz.x = sol_poz.x + user[i].x / n;
			sol_poz.y = sol_poz.y + user[i].y / n;
		}
	}
	else {
		/*Calculez pentru fiecare user de ce magazin e cel mai aproape. Pe linia i si coloana 0 din matricea mat retin cati useri merg la magazinul i. Apoi, pe linia i si coloana j din mat retin pozitia din vectorul de useri a celui de al j-ules user care merge la magazinul i*/
		for(i = 1; i <= n; i++){
			int loc_magazin, minim = inf;
			for(j = 1; j <= m; j++){
				if(dist(user[i], magazin[j]) < minim){
					minim = dist(user[i], magazin[j]);
				        loc_magazin = j;
				}
			}
			mat[loc_magazin][0]++;
			mat[loc_magazin][mat[loc_magazin][0]] = i;
		}
		int sol=0;
		/*Pentru fiecare user, determin pe dreptele determinate de magazinul la care merge cu fiecare din celelalte magazine cate un segment, in interiorul caruia, daca ar fi plasat un nou magazin, ar fi mai aproape de userul respectiv. Unul din capetele acestui segment este chiar magazinul cel mai apropiat de user, celalalt fiind simetricul magazinul fata de piciorul perpendicularei duse din user pe dreapta celor doua magazine. Pentru fiecare segment, retin in start punctul cel mai din stanga (cu x-ul cel mai mic) si in stop capatul din dreapta*/
		for(i = 1; i <= m; i++){
			for(j = i + 1; j <= m; j++){
				int nr = 0;
				for(int k = 1; k <= mat[i][0]; k++){
					pct om = user[mat[i][k]];
					if (magazin[i].y == magazin[j].y){
						nr++;
						double x = 2 * om.x - magazin[i].x;
						if (x < magazin[i].x){
							start[nr].x = x;
							start[nr].y = magazin[i].y;
							stop[nr] = magazin[i];
						}
						else {
							stop[nr].x = x;
							stop[nr].y = magazin[i].y;
							start[nr] = magazin[i];
						}
					}
					else {
						nr++;
						double a = (magazin[j].y - magazin[i].y) / (magazin[j].x - magazin[i].x);
						double b = (magazin[i].y * magazin[j].x - magazin[j].y * magazin[i].x) / (magazin[j].x - magazin[i].x);
						double aprim = -1 / a;
						double bprim = om.y - aprim * om.x;
						double x1 = (b - bprim) / (aprim - a);
						double y1 = a * x1 + b;
						double x = 2 * x1 - magazin[i].x;
						double y = 2 * y1 - magazin[i].y;
						if (x < magazin[i].x){
							start[nr].x = x;
							start[nr].y = y;
							stop[nr] = magazin[i];
						}
						else {
							stop[nr].x = x;
							stop[nr].y = y;
							start[nr] = magazin[i];
						}
					}
				}
				for(int k = 1; k <= mat[j][0]; k++){
					pct om = user[mat[j][k]];
					if (magazin[i].y == magazin[j].y){
						nr++;
						double x = 2 * om.x - magazin[j].x;
						if (x < magazin[j].x){
							start[nr].x = x;
							start[nr].y = magazin[j].y;
							stop[nr] = magazin[j];
						}
						else {
							stop[nr].x = x;
							stop[nr].y = magazin[j].y;
							start[nr] = magazin[j];
						}
					}
					else {
						nr++;
						double a = (magazin[i].y - magazin[j].y) / (magazin[i].x - magazin[j].x);
						double b = (magazin[j].y * magazin[i].x - magazin[i].y * magazin[j].x) / (magazin[i].x - magazin[j].x);
						double aprim = -1 / a;
						double bprim = om.y - aprim * om.x;
						double x1 = (b - bprim) / (aprim - a);
						double y1 = a * x1 + b;
						double x = 2 * x1 - magazin[j].x;
						double y = 2 * y1 - magazin[j].y;
						if (x < magazin[j].x){
							start[nr].x = x;
							start[nr].y = y;
							stop[nr] = magazin[j];
						}
						else {
							stop[nr].x = x;
							stop[nr].y = y;
							start[nr] = magazin[j];
						}
					}
				}
				/*Sortez vectorii start si stop crescator dupa x*/
				quicksort(start, 1, nr);
				quicksort(stop, 1, nr);
				/*Aplic pentru fiecare dreapta smenul lui mars. Parcurg dreapta si de fiecare data cand gasesc un punct de start incrementez un contor, iar de fiecare data cand gasesc un punct de stop il decrementez. Caut (printre punctele de start) punctul care apartine intersectiei a cat mai multe segmente si care este diferit de magazinele deja existente. Acest punct este cel in care contorul are valoarea maxima (am intrat in cat mai multe segmente din care nu am iesit)*/
				int cnt_start = 1, cnt_stop = 1;
				int cnt = 0;			
				while(cnt_start <= nr && cnt_stop <= nr){
					if(start[cnt_start].x < stop[cnt_stop].x){
						cnt++;
						if(cnt > sol){
		 					if(start[cnt_start].x != magazin[i].x && start[cnt_start].x != magazin[j].x){
								sol_poz = start[cnt_start];
								sol = cnt;
							}
						}
						cnt_start++;
					}
					else {
						cnt--;
						cnt_stop++;
					}
				}
			}
		}
	}
	cout << fixed << setprecision(6);
	cout << sol_poz.x << " " << sol_poz.y;
	return 0;
}

	
			
