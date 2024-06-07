#include "EstrategiaPeriferica.h"

int* EstrategiaPeriferica::ejecutarEstrategia()
{
    TableroIrregular* tableroIrregular = dynamic_cast<TableroIrregular*>(TableroGlobal::getInstancia()->getTablero());
    if (!tableroIrregular) {

        return nullptr;
    }

    Tablero** tableros = tableroIrregular->getTableros();
    int cantidad = tableroIrregular->getCantidad();
    int origenFila, origenColumna, filas, columnas;

    int minFila = 30, maxFila = 0, minColumna = 30, maxColumna = 0;
    for (int i = 0; i < cantidad; ++i) {
        int* coords = tableros[i]->origen();
        origenFila = coords[1];
        origenColumna = coords[0];
        filas = tableros[i]->getFilas();
        columnas = tableros[i]->getColumnas();

        if (origenFila < minFila) minFila = origenFila;
        if (origenColumna < minColumna) minColumna = origenColumna;
        if (origenFila + filas > maxFila) maxFila = origenFila + filas;
        if (origenColumna + columnas > maxColumna) maxColumna = origenColumna + columnas;

        delete[] coords;
    }

    
   const int maxBordes = 120; // Tamaño máximo posible
    pair<int, int> bordes[maxBordes];
    int contador = 0;

    // Añadir las coordenadas de la fila superior
    for (int col = minColumna; col <= maxColumna; ++col) {
        bordes[contador++] = { minFila, col };
    }

    // Añadir las coordenadas de la fila inferior
    for (int col = minColumna; col <= maxColumna; ++col) {
        bordes[contador++] = { maxFila, col };
    }

    // Añadir las coordenadas de la columna izquierda
    for (int fil = minFila; fil <= maxFila; ++fil) {
        bordes[contador++] = { fil, minColumna };
    }

    // Añadir las coordenadas de la columna derecha
    for (int fil = minFila; fil <= maxFila; ++fil) {
        bordes[contador++] = { fil, maxColumna };
    }

   
    for (int i = 0; i < contador; ++i) {
        int fil = bordes[i].first;
        int col = bordes[i].second;

        if (tableroIrregular->agregarJugadaCompu(fil, col)) {
            int* estra = new int[2] { fil, col };
            return estra;
        }

    }
    //si no encuentra más bordes
    srand(time(0));
    int fil = rand() % (maxFila - minFila + 1) + minFila;
    int col = rand() % (maxColumna - minColumna + 1) + minColumna;


    while (!tableroIrregular->agregarJugadaCompu(fil, col)) {
        fil = rand() % (maxFila - minFila + 1) + minFila;
        col = rand() % (maxColumna - minColumna + 1) + minColumna;
    }

    int* estra = new int[2] {fil, col};
    return estra;
    //Tengo que cambiar unas cosas e intentar hacerlo con como está hecho el toString de la matriz irregular
}

EstrategiaPeriferica::~EstrategiaPeriferica()
{
}
