#include "Tablero3x3.h"
Tablero3x3::Tablero3x3()
{
	filas = 3;
	columnas = 3;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				mat[i][j] = '+';
			else mat[i][j] = '-';
			if (i % 2 != 0 && j % 2 != 0)
				mat[i][j] = 'o';
		}
}
Tablero3x3::~Tablero3x3()
{
}
string Tablero3x3::toString()
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

void Tablero3x3::llenarMatriz()
{
}

void Tablero3x3::Add(Tablero* tab, int f, int c)
{
}

void Tablero3x3::Delete()
{
}

int Tablero3x3::getFilas()
{
	return filas;
}

int Tablero3x3::getColumnas()
{
	return columnas;
}

char Tablero3x3::getValor(int f, int c)
{
	return 0;
}

void Tablero3x3::añadirIzquierda(Tablero* tab)
{
}

void Tablero3x3::añadirDerecha(Tablero* tab)
{
}

void Tablero3x3::añadirArriba(Tablero* tab)
{
}

void Tablero3x3::añadirAbajo(Tablero* tab)
{
}
bool Tablero3x3::validarPunto(char c, int x, int y) {
	return true;
}
bool Tablero3x3::agregarJugada(int x, int y) {
	if (x<0 or y<0) throw ExcepcionRango();
	if (mat[x][y] != '\0') throw ExcepcionLugarOcupado();
	if(x==y) throw ExcepcionLugarReservado();

	char c='\0';
	x%2==0?c=char(205):c=char(186);
	mat[x][y] = c;
	return true;
}

int* Tablero3x3::origen() {
	return new int[2] {columOrigen, filaOrigen};
}