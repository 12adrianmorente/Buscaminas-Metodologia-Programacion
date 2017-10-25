#include "tablero.h"
#include "campominas.h"

/*--------------------------------------------------------------*/

int main(){
	int filas_user, columnas_user, minas_user, auxminas;
	srand(time(0));

	do{
		cout << "Introduce numero de filas y columnas (>=4) (separados por espacio): ";
		cin >> filas_user;
		cin >> columnas_user;
	}
	while(filas_user < 4 && columnas_user < 4);

	auxminas = (filas_user*columnas_user)/2;

	do{
		cout << "Introduce el numero de minas (debe ser minimo 5 y maximo " << auxminas << "): ";
		cin >> minas_user;
	}while(minas_user < 5 || minas_user > auxminas);

	Campominas juego_nuevo(filas_user, columnas_user, minas_user);

	while(juego_nuevo.Estado() && !juego_nuevo.CheckVictoria()){
		juego_nuevo.PrettyPrint();
		juego_nuevo.Menu();
	}

	if(juego_nuevo.CheckVictoria())
		cout << "\n\nEnhorabuena, has ganado.\n\n";
}

/*--------------------------------------------------------------*/
