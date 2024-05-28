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

char Tablero3x4::getValor(int f, int c)
{
	return 0;
}

void Tablero3x4::añadirIzquierda(Tablero* tab)
{
}

void Tablero3x4::añadirDerecha(Tablero* tab)
{
}

void Tablero3x4::añadirArriba(Tablero* tab)
{
}

void Tablero3x4::añadirAbajo(Tablero* tab)
{
}
bool Tablero3x4::validarPunto(char c, int x, int y) {
	return true;
}
bool Tablero3x4::agregarJugada(int x, int y) {
	if (x < 0 or y < 0) throw ExcepcionRango();
	if (mat[x][y] != '\0') throw ExcepcionLugarOcupado();
	if (x == y) throw ExcepcionLugarReservado();

	char c = '\0';
	x % 2 == 0 ? c = char(205) : c = char(186);
	mat[x][y] = c;
	return true;
}

int* Tablero3x4::origen() {
	return new int[2] {columOrigen, filaOrigen};
}