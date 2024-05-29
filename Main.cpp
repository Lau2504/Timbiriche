#include "TableroIrregular.h"
#include <iostream>
using namespace std;


int main() {
	Tablero* tab = new TableroIrregular();
	Tablero* tab1 = new Tablero3x3();
	Tablero* tab2 = new Tablero3x4();
	Tablero* tab3 = new Tablero3x5();
	/*tab->Add(tab1, 2, 6);*/
	//Llamar función que me dice en que rango puedo poner la otra matriz para cuando el usuario la pone manualmente
	/*tab->Add(tab2, 6, 14); */

	tab->Add(tab3, 12, 10);
	tab->añadirIzquierda(tab1);
	/*tab->añadirIzquierda(tab1);*/ //Existe la matriz base y de ahí se agregan las otras matrices no se puede agregar a la izquierda porque ya hay una en ese lado

	//tab->añadirDerecha(tab2);
	//tab->añadirArriba(tab1);
	tab->añadirAbajo(tab1);
	cout << tab->toString();
		
	tab->añadirDerecha(tab2);
	/*tab->añadirArriba(tab1);*/
	tab->añadirAbajo(tab1);
	cout << tab->toString();


	system("Pause");
	return 0;
}