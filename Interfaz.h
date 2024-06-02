#pragma once
#include <iostream>
#include <sstream>
#include "Excepciones.h"

using namespace std;

class Interfaz {
public:
	Interfaz();
	virtual ~Interfaz();
	static int menuInicio();
	static char inicio();
	static char otroJugador();
	static int tablero();
	static int cuantosTableros();
	static void mostrarTablero(Tablero* tab);
	static int fila();
	static int columna();
	static int escogerEstrategia();
	static int cambiarEstrategia();
};