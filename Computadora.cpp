#include "Computadora.h"


Computadora::Computadora(Estrategia* estrat):estrategia(estrat)
{
	c = 'C';
}

Computadora::~Computadora() {}

//void Computadora::setLetra(char l) { letra = l; }

char Computadora::getLetra() { return c; }

bool Computadora::jugar(int col, int fila) {
	Tablero* tab = TableroGlobal::getInstancia()->getTablero();
	int fil = estrategia->ejecutarEstrategia()[0];
	int colu = estrategia->ejecutarEstrategia()[1];
	tab->agregarJugada(colu, fila);
	return tab->validarPunto(c, colu, fila);
}

void Computadora::setEstrategia(Estrategia* estra)
{
	estrategia = estra;
}
