#include "EstrategiaAleatoria.h"

int* EstrategiaAleatoria::ejecutarEstrategia()
{
	srand(time(0));
	int filas = TableroGlobal::getInstancia()->getTablero()->getFilas();
	int columnas = TableroGlobal::getInstancia()->getTablero()->getColumnas();
	int col = rand() % columnas + 1, fil = rand() % filas + 1;
	int* estra = new int[2] {fil, col};
	return estra;
}

