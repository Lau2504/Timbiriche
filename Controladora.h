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
	void mostrarMementos(Repositorio*);
	void iniciarNuevaPartida(Originador*, Repositorio*);
	void iniciarJuegoDosJugadores(Juego*, char, Originador*, Repositorio*, Tablero*);
	void iniciarJuegoContraComputadora(Juego*,char, Originador*, Repositorio*, Tablero*);
	void guardarMemento(Juego*, Originador*, Repositorio*, int&);

};