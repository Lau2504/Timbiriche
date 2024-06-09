#include "EstrategiaCercana.h"


int* EstrategiaCercana::ejecutarEstrategia()
{
    Tablero* tab = TableroGlobal::getInstancia()->getTablero();
    TableroIrregular* tableroIrregular = dynamic_cast<TableroIrregular*>(TableroGlobal::getInstancia()->getTablero());
    if (!tableroIrregular) {
        return nullptr;
    }
    Tablero** tableros = tableroIrregular->getTableros();
    int cantidad = tableroIrregular->getCantidad();
    Vector<int> lados(4);//guarda los lados que se pueden mover, no la posicion x,y del punto donde se compara
    bool hayJugada = false;
    int X1 = 0, Y1 = 0;
    int* coords = tab->ultimaJugada();
    X1 = coords[0];
    Y1 = coords[1];
    do { // Se mueve de dos en dos porque si no choca con un + o un espacio reservado
        if (X1 != 0)
            if (tab->espacioValido(X1 - 2, Y1))
                lados.agregarFinal(new int[2] {X1 - 2, Y1});
        if (Y1 != 0)
            if (tab->espacioValido(X1, Y1 + 2))
                lados.agregarFinal(new int[2] {X1, Y1 + 2});
        if (Y1 != tab->getFilas() - 1)
            if (tab->espacioValido(X1, Y1 - 2))
                lados.agregarFinal(new int[2] {X1, Y1 - 2});
        if (X1 != tab->getColumnas() - 1)
            if (tab->espacioValido(X1 + 2, Y1))
                lados.agregarFinal(new int[2] {X1 + 2, Y1});

        if (lados.cantidad() > 0) 
            hayJugada = true;
        //Va moviendo los puntos que verifica si ya no encontro arriba un lugar donde hacer un movimiento
        else if (tab->espacioValido(X1 + 2, Y1))
            X1 += 2;
        else if (tab->espacioValido(X1 - 2, Y1))
            X1 -= 2;
        else if (tab->espacioValido(X1, Y1 + 2))
            Y1 += 2;
        else if (tab->espacioValido(X1, Y1 - 2))
            Y1 -= 2;



    } while (!hayJugada);

    srand(time(0));
    return lados.sacar(rand() % lados.cantidad());
}

EstrategiaCercana::~EstrategiaCercana()
{
}
       ////Por si no hay campo cerca de donde el jugador está jugando
       // int minFila = 30, maxFila = 0, minColumna = 30, maxColumna = 0;
       // for (int i = 0; i < cantidad; ++i) {
       //     int* coords = tableros[i]->origen();
       //     int origenFila = coords[1];
       //     int origenColumna = coords[0];
       //     int filas = tableros[i]->getFilas();
       //     int columnas = tableros[i]->getColumnas();

       //     if (origenFila < minFila) minFila = origenFila;
       //     if (origenColumna < minColumna) minColumna = origenColumna;
       //     if (origenFila + filas > maxFila) maxFila = origenFila + filas;
       //     if (origenColumna + columnas > maxColumna) maxColumna = origenColumna + columnas;

       //     delete[] coords;
       // }
       // srand(time(0));
       // int fil = rand() % (maxFila - minFila + 1) + minFila;
       // int col = rand() % (maxColumna - minColumna + 1) + minColumna;


       // while (!tableroIrregular->agregarJugadaCompu(fil, col)) {
       //     fil = rand() % (maxFila - minFila + 1) + minFila;
       //     col = rand() % (maxColumna - minColumna + 1) + minColumna;
       // }

       // int* estra = new int[2] {fil, col};
       // return estra;


