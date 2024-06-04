#include "Persona.h"

Persona::Persona(char l) :Jugador(), letra{l} {}

Persona::~Persona() {}

//void Persona::setLetra(char l) { letra = l; }

char Persona::getLetra() { return letra; }

bool Persona::jugar(int col, int fila) {
	Tablero* tab = TableroGlobal::getInstancia()->getTablero();
	if (!tab->agregarJugada(col, fila))
		throw ExcepcionRango();
	
	return tab->validarPunto(letra, col, fila);
}