#include "Persona.h"

Persona::Persona(char l) :Jugador(), letra{l} {}

Persona::~Persona() {}

//void Persona::setLetra(char l) { letra = l; }

char Persona::getLetra() { return letra; }

bool Persona::jugar(int col, int fila) {
	Tablero* tab = TableroGlobal::getInstancia()->getTablero();
	tab->agregarJugada(col, fila);
	return tab->validarPunto(letra, col, fila);
}