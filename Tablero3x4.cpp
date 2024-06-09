#include "Tablero3x4.h"

Tablero3x4::Tablero3x4():Tablero(7,5)
{
	filas = 5;
	columnas = 7;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				mat[i][j] = '+';
			else mat[i][j] = ' ';
			/*else mat[i][j] = '-';
			if (i % 2 != 0 && j % 2 != 0)
				mat[i][j] = 'o';*/
		}
}

Tablero3x4::~Tablero3x4()
{
}

string Tablero3x4::toString()
{
	stringstream s;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			s << mat[i][j];
		}
		s << endl;
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

char Tablero3x4::getValor(int f, int c)
{
	return mat[f][c];
}




int* Tablero3x4::origen() {
	return new int[2] {columOrigen, filaOrigen};
}
int Tablero3x4::puntuacion(char c) {
	int n = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (mat[i][j] == c) n++;
		}
	}
	return n;
}

int Tablero3x4::getCantidad()
{
	return 0;
}

Tablero* Tablero3x4::clone()
{
	Tablero3x4* tablerito = new Tablero3x4();

	tablerito->filas = this->filas;
	tablerito->columnas = this->columnas;
	tablerito->filaOrigen = this->filaOrigen;
	tablerito->columOrigen = this->columOrigen;


	for (int i = 0; i < this->filas; ++i) {
		for (int j = 0; j < this->columnas; ++j) {
			tablerito->mat[i][j] = this->mat[i][j];
		}
	}

	return tablerito;
}
