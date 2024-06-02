#pragma once
#include <iostream>
#include <sstream>
#include "Interfaz.h"
using namespace std;

class Controladora {
public:
	Controladora();
	virtual ~Controladora();

	void control0();
	Tablero* crearTablero();
	Estrategia* decidirEstrategia();

};