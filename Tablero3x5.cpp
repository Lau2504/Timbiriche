#include "Tablero3x5.h"

Tablero3x5::Tablero3x5()
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
bool Tablero3x5::validarPunto(char c, int fila, int col) {
	bool b{ false };
	bool hayPunto{ false };
	b = fila % 2;//0 es par, por ende se coloco una linea vertical, y el "escaneo" es horizontal
	//de lo contrario, si no es a es b...
	if (b) {
		if (fila != filas - 1)//leer abajo
			if (mat[fila + 2][col] != '\0' and mat[fila + 1][col + 1] != '\0' and mat[fila + 1][col - 1]) {
				mat[fila + 1][col] = c;
				hayPunto = true;
			}
		if (fila != 0)//leer arriba
			if (mat[fila - 2][col] != '\0' and mat[fila - 1][col + 1] != '\0' and mat[fila - 1][col - 1]) {
				mat[fila - 1][col] = c;
				hayPunto = true;
			}
	}
	else {//b==0->b%2==0->b es posicion de columna donde solo hay lineas verticales ║
		if (col != columnas - 1)//leer derecha
			if (mat[fila][col + 2] != '\0' and mat[fila + 1][col + 1] != '\0' and mat[fila - 1][col + 1]) {
				mat[fila][col + 1] = c;
				hayPunto = true;
			}
		if (col != 0)//leer izquierda
			if (mat[fila][col - 2] != '\0' and mat[fila + 1][col - 1] != '\0' and mat[fila - 1][col + 1]) {
				mat[fila][col - 1] = c;
				hayPunto = true;
			}
	}
	return hayPunto;
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
