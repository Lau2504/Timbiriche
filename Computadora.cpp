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
    int* par = estrategia->ejecutarEstrategia();
    int colu = par[0], fil = par[1];
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

//hacer método en Tablero Irregular
bool Computadora::juegaPunto(int& col, int& fila) {
    Tablero* tab = TableroGlobal::getInstancia()->getTablero();
    TableroIrregular* tableroIrregular = dynamic_cast<TableroIrregular*>(tab);
    if (!tableroIrregular) {
        return false;
    }

    Tablero** vec = tableroIrregular->getTableros();
    int cantidad = tableroIrregular->getCantidad();

    for (int i = 0; i < cantidad; i++) {
        int* coords = vec[i]->origen();
        for (int j = 0; j < vec[i]->getFilas(); j++) {
            for (int k = 0; k < vec[i]->getColumnas(); k++) {
                int x = k + coords[0];
                int y = j + coords[1];
                if (tab->getValor(y, x) == ' ') {
                    try {
                        if (tab->agregarJugadaCompu(x, y)) {
                            if (tab->validarPunto(c, x, y)) {

                                col = x;
                                fila = y;
                                return true; // Se hizo un punto
                            }
                        }

                        else {
                            tab->deshacerJugada(x, y);
                        }
                    }
                    catch (const ExcepcionLugarOcupado&) {
                        // Si el lugar está ocupado, continuamos
                    }
                    catch (const ExcepcionRango&) {
                        // Si la jugada está fuera de rango, continuamos
                    }
                    catch (const ExcepcionLugarReservado&) {
                        // Si el lugar está reservado, continuamos
                    }
                }
            }
        }
        delete[] coords;
    }
    return false; // No se encontró ninguna jugada que haga un punto
}


