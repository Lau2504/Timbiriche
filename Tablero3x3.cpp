#include "Tablero3x3.h"
Tablero3x3::Tablero3x3():Tablero(){
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

void Tablero3x3::agregarIzquierda(Tablero* tab)
{
}

void Tablero3x3::agregarDerecha(Tablero* tab)
{
}

void Tablero3x3::agregarArriba(Tablero* tab)
{
}

void Tablero3x3::agregarAbajo(Tablero* tab)
{
}
bool Tablero3x3::validarPunto(char c, int col, int fila) {
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
	} else {//b==0->b%2==0->b es posicion de columna donde solo hay lineas verticales ║
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

int Tablero3x3::puntuacion(char c) {
	int n = 0;
	for (int i = 0;i < filas; i++) {
		for (int j = 0;j < columnas; j++) {
			if (mat[i][j] == c) n++;
		}
	}
	return n;
}