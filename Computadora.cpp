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

	int* par=estrategia->ejecutarEstrategia();
	int colu = par[0],fil=par[1];
	delete[] par;
	tab->agregarJugada(colu, fil);
	return tab->validarPunto(c, colu, fil);
}

void Computadora::setEstrategia(Estrategia* estra)
{
	estrategia = estra;
}

Estrategia* Computadora::getEstrategia()
{
	return estrategia;
}
