#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Tablero {
protected:
	int filas;
	int columnas;
	char mat[30][30];
public:
	Tablero() {}
	virtual ~Tablero(){}
	virtual string toString() = 0;
	virtual int getFilas() = 0;
	virtual int getColumnas() = 0;
	virtual void llenarMatriz() = 0;
	virtual void añadirIzquierda(Tablero* tab) = 0;
	virtual void añadirDerecha(Tablero* tab) = 0;
	virtual void añadirArriba(Tablero* tab) = 0;
	virtual void añadirAbajo(Tablero* tab) = 0;
	virtual void Add(Tablero* tab, int f, int c) = 0;
	virtual void Delete() = 0;
	virtual char getValor(int f, int c) = 0;
};