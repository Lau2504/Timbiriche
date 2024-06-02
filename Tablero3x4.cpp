#include "Tablero3x4.h"

Tablero3x4::Tablero3x4()
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


void Tablero3x4::agregarIzquierda(Tablero* tab)
{
}

void Tablero3x4::agregarDerecha(Tablero* tab)
{
}

void Tablero3x4::agregarArriba(Tablero* tab)
{
}

void Tablero3x4::agregarAbajo(Tablero* tab)
{
}
bool Tablero3x4::validarPunto(char c, int col, int fila) {
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
bool Tablero3x4::agregarJugada(int x, int y) {
	if (x < 0 or y < 0) throw ExcepcionRango();
	if (mat[x][y] != '\0') throw ExcepcionLugarOcupado();
	if (x == y) throw ExcepcionLugarReservado();

	char c = '\0';
	x % 2 == 0 ? c = '-' : c = 'l';
	mat[x][y] = c;
	return true;
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
