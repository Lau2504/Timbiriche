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
    TableroIrregular* tableroIrregular = dynamic_cast<TableroIrregular*>(tab);
    int colu = 0, fil = 0;
    int* par = nullptr;
    srand(time(0));

    Vector<int>* oportunidades = tableroIrregular->oportunidadPunto();
    if (oportunidades->cantidad() > 0) { // si hay un posible punto
        par = oportunidades->sacar(rand() % oportunidades->cantidad());
        colu = par[1];
        fil = par[0];
        delete[] par; // Liberar memoria de par aquí
    }
    else {
        par = estrategia->ejecutarEstrategia();
        colu = par[0];
        fil = par[1];
        delete[] par; // Liberar memoria de par aquí también
    }
    delete oportunidades; // Liberar la memoria de oportunidades

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

