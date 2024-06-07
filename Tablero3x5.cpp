#include "Tablero3x5.h"

Tablero3x5::Tablero3x5():Tablero(9,5)
{
	filas = 5;
	columnas = 9;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				mat[i][j] = '+';
			else mat[i][j] = ' ';
			/*if (i % 2 != 0 && j % 2 != 0)
				mat[i][j] = 'o';*/
		}
}

Tablero3x5::~Tablero3x5()
{
}

string Tablero3x5::toString()
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

void Tablero3x5::llenarMatriz()
{
}

void Tablero3x5::Add(Tablero* tab, int f, int c)
{
}

void Tablero3x5::Delete()
{
}

int Tablero3x5::getFilas()
{
	return filas;
}

int Tablero3x5::getColumnas()
{
	return columnas;
}

char Tablero3x5::getValor(int f, int c)
{
	return mat[f][c];
}

void Tablero3x5::agregarIzquierda(Tablero* tab)
{
}

void Tablero3x5::agregarDerecha(Tablero* tab)
{
}

void Tablero3x5::agregarArriba(Tablero* tab)
{
}

void Tablero3x5::agregarAbajo(Tablero* tab)
{
}


int* Tablero3x5::origen() {
	return new int[2] {columOrigen, filaOrigen};
}

int Tablero3x5::puntuacion(char c) {
	int n = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (mat[i][j] == c) n++;
		}
	}
	return n;
}

int Tablero3x5::getCantidad()
{
	return 0;
}

Tablero* Tablero3x5::clone()
{
	Tablero3x5* tablerito = new Tablero3x5();

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
