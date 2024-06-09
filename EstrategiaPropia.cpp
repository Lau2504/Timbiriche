#include "EstrategiaPropia.h"

//La estrategia propia consiste en tomar cada uno de los tableros pequeños que están en el tablero irregular
// e ir armando la figura de una esvastica en el centro lo cual va cortando la posibilidad de que 
// el contrincante arme hilos largos que le permitan obtener la victoria
// cuando ya se hicieron las figuras en el centro se harán los hilos más largos
// La figura de la esvastica se va formando al siempre poner una línea 
//adyacente a la cual el jugador acaba de poner 
int* EstrategiaPropia::ejecutarEstrategia()
{
    Tablero* tab = TableroGlobal::getInstancia()->getTablero();
    Vector<int> lados(4);//guarda los lados que se pueden mover, no la posicion x,y del punto donde se compara

    TableroIrregular* tableroIrregular = dynamic_cast<TableroIrregular*>(TableroGlobal::getInstancia()->getTablero());
    if (!tableroIrregular)
        return nullptr;
    Tablero** tableros = tableroIrregular->getTableros();
    int cantidad = tableroIrregular->getCantidad();


    bool hayJugada = false;
    int X1 = 0, Y1 = 0;
    int* coords = tab->ultimaJugada();
    X1 = coords[0];
    Y1 = coords[1];
    delete[] coords;

    srand(time(0));

    do { //Toma la última jugada y va buscando los lados adyacentes 
        if (X1 != 0)
            if (tab->espacioValido(X1 + 1, Y1 - 1))
                lados.agregarFinal(new int[2] {X1 + 1, Y1 - 1});
        if (Y1 != 0)
            if (tab->espacioValido(X1 - 1, Y1 - 1))
                lados.agregarFinal(new int[2] {X1 - 1, Y1 - 1});
        if (Y1 != tab->getFilas() - 1)
            if (tab->espacioValido(X1 - 1, Y1 + 1))
                lados.agregarFinal(new int[2] {X1 - 1, Y1 + 1 });
        if (X1 != tab->getColumnas() - 1)
            if (tab->espacioValido(X1 + 1, Y1 + 1))
                lados.agregarFinal(new int[2] {X1 + 1, Y1 + 1});

        if (lados.cantidad() > 0)
            hayJugada = true;
        // si ya no hay adyacentes, que busque armar cadenas
        else {
            Vector<int>* verticales = tableroIrregular->posicionesVertical();
            if (verticales->cantidad() > 0) {
                int* v1 = verticales->sacar(rand() % verticales->cantidad());
                int x1 = v1[0];
                int y1 = v1[1];
                delete[] v1;

                if (tableroIrregular->espacioValido(x1 - 2, y1)) return new int[2] {x1 - 2, y1};
                if (tableroIrregular->espacioValido(x1 + 2, y1)) return new int[2] {x1 + 2, y1};
            }

            Vector<int>* horizontales = tableroIrregular->posicionesHorizontal();
            if (horizontales->cantidad() > 0) {
                int* h1 = horizontales->sacar(rand() % horizontales->cantidad());
                int x1 = h1[0];
                int y1 = h1[1];
                delete[] h1;

                if (tableroIrregular->espacioValido(x1, y1 - 2)) return new int[2] {x1, y1 - 2};
                if (tableroIrregular->espacioValido(x1, y1 + 2)) return new int[2] {x1, y1 + 2};
            }

            delete verticales;
            delete horizontales;
        }


    } while (!hayJugada);


    return lados.sacar(rand() % lados.cantidad());
}

EstrategiaPropia::~EstrategiaPropia()
{
}
// Si no hay movimientos válidos adyacentes o cercanos, buscar formar hileras largas
//if (lados.cantidad() == 0) {
//    // Aquí se podría implementar la lógica para buscar y formar hileras largas
//    for (int i = 0; i < tab->getColumnas(); ++i) {
//        for (int j = 0; j < tab->getFilas(); ++j) {
//            if (tab->espacioValido(i, j)) {
//                // Verificar si agregar una línea en (i, j) puede formar una hilera larga
//                // Esta verificación se puede basar en la cantidad de líneas continuas en
//                // las cuatro direcciones posibles: horizontal, vertical, y dos diagonales
//                // Ejemplo de verificación:
//                int horizontalCount = 0;
//                for (int k = i; k < tab->getColumnas() && tab->espacioValido(k, j); ++k)
//                    horizontalCount++;
//                if (horizontalCount >= 3) {
//                    lados.agregarFinal(new int[2] {i, j});
//                }
//                int verticalCount = 0;
//                for (int k = j; k < tab->getFilas() && tab->espacioValido(i, k); ++k)
//                    verticalCount++;
//                if (verticalCount >= 3) {
//                    lados.agregarFinal(new int[2] {i, j});
//                }
//            }
//        }
//    }
//}