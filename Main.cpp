#include "TableroIrregular.h"
#include "Controladora.h"
#include <iostream>

using namespace std;


int main() {
	/*
	TableroIrregular* tab = new TableroIrregular();
	Tablero* tab1 = new Tablero3x3();
	Tablero* tab2 = new Tablero3x4();
	Tablero* tab3 = new Tablero3x5();*/
	/*tab->Add(tab1, 2, 6);*/
	//Llamar función que me dice en que rango puedo poner la otra matriz para cuando el usuario la pone manualmente
	/*tab->Add(tab2, 6, 14); */

	//-tab->Add(tab3, 12, 10);
	//-tab->agregarIzquierda(tab1);
	/*tab->agregarIzquierda(tab1);*/ //Existe la matriz base y de ahí se agregan las otras matrices no se puede agregar a la izquierda porque ya hay una en ese lado

	//tab->agregarDerecha(tab2);
	//tab->agregarArriba(tab1);
	//-tab->agregarAbajo(tab1);
	//-cout << tab->toString();
		
	//-tab->agregarDerecha(tab2);
	/*tab->agregarArriba(tab1);*/
	//tab->agregarAbajo(tab1);
	//cout << tab->toString();
	
	//-----------------
 
	//tab->agregarTablero(tab1);
	//tab->agregarTablero(tab2);
	//tab->agregarTablero(tab3);
	//cout << tab->toString() << endl;

	Controladora* contro = new Controladora();
	contro->control0();
	system("Pause");
	return 0;
}