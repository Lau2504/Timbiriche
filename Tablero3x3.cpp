#include "Tablero3x3.h"
Tablero3x3::Tablero3x3():Tablero(5,5){
	filas = 5;
	columnas = 5;
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
Tablero3x3::~Tablero3x3()
{
}
string Tablero3x3::toString(){
	stringstream s;/*
	//s << "           col = 0    col = 1    col = 2    col = 3    col = 4    col = 5    col = 6    col = 7    col = 8    col = 9    col = 10" << endl;
	for (int i = 0; i <= filas; i++) {
		for (int j = 0; j <= columnas; j++) {
		}
		s << endl << endl;
	}*/
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			s << mat[i][j];
		}
		s << endl;
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
	return mat[f][c];
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

int Tablero3x3::getCantidad()
{
	return 0;
}

Tablero* Tablero3x3::clone()
{
	Tablero3x3* tablerito = new Tablero3x3(); 

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


