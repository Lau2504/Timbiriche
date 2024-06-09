#include "EstrategiaAleatoria.h"
#include "TableroGlobal.h"
#include "TableroIrregular.h"
#include <cstdlib>
#include <ctime>

int* EstrategiaAleatoria::ejecutarEstrategia() {
    TableroIrregular* tableroIrregular = dynamic_cast<TableroIrregular*>(TableroGlobal::getInstancia()->getTablero());
    if (!tableroIrregular) {
        return nullptr;
    }

    Tablero** tableros = tableroIrregular->getTableros();
    int cantidad = tableroIrregular->getCantidad();

    int minFila = 30, maxFila = 0, minColumna = 30, maxColumna = 0;
    for (int i = 0; i < cantidad; ++i) {
        int* coords = tableros[i]->origen();
        int origenFila = coords[1];
        int origenColumna = coords[0];
        int filas = tableros[i]->getFilas();
        int columnas = tableros[i]->getColumnas();

        if (origenFila < minFila) minFila = origenFila;
        if (origenColumna < minColumna) minColumna = origenColumna;
        if (origenFila + filas > maxFila) maxFila = origenFila + filas;
        if (origenColumna + columnas > maxColumna) maxColumna = origenColumna + columnas;

        delete[] coords;
    }

    srand(time(0));
    int fil = rand() % (maxFila - minFila + 1) + minFila;
    int col = rand() % (maxColumna - minColumna + 1) + minColumna;


    while (!tableroIrregular->agregarJugadaCompu(fil, col)) {
        fil = rand() % (maxFila - minFila + 1) + minFila;
        col = rand() % (maxColumna - minColumna + 1) + minColumna;
    }

    int* estra = new int[2] {fil, col};
    return estra;
}

EstrategiaAleatoria::~EstrategiaAleatoria() {

}
