#include "Tablero3x4.h"

Tablero3x4::Tablero3x4()
{
	filas = 3;
	columnas = 4;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				mat[i][j] = '+';
			else mat[i][j] = '-';
			if (i % 2 != 0 && j % 2 != 0)
				mat[i][j] = 'o';
		}
}

Tablero3x4::~Tablero3x4()
{
}

string Tablero3x4::toString()
{
	stringstream s;
	//s << "           col = 0    col = 1    col = 2    col = 3    col = 4    col = 5    col = 6    col = 7    col = 8    col = 9    col = 10" << endl;
	for (int i = 0; i <= filas; i++) {
		for (int j = 0; j <= columnas; j++) {
		}
		s << endl << endl;
	}
	return s.str();
}

void Tablero3x4::llenarMatriz()
{
}

void Tablero3x4::Add(Tablero* tab, int f, int c)
{
}

void Tablero3x4::Delete()
{
}

int Tablero3x4::getFilas()
{
	return filas;
}

int Tablero3x4::getColumnas()
{
	return columnas;
}
