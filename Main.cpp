#include "TableroIrregular.h"

int main() {
	Tablero* tab = new TableroIrregular();
	Tablero* tab1 = new Tablero3x3();
	Tablero* tab2 = new Tablero3x4();
	Tablero* tab3 = new Tablero3x5();
	/*tab->Add(tab1, 2, 6);*/
	//Llamar función que me dice en que rango puedo poner la otra matriz para cuando el usuario la pone manualmente
	/*tab->Add(tab2, 6, 14); */

	tab->Add(tab3, 15, 15);
	tab->añadirIzquierda(tab1);
	cout << tab->toString();

	system("Pause");
	return 0;
}