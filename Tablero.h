#pragma once
#include <iostream>
#include <sstream>

#include "ExcepcionLugarOcupado.h"
#include "ExcepcionRango.h"
#include "ExcepcionLugarReservado.h"
using namespace std;

class Tablero {
protected:
	int filaOrigen;
	int columOrigen;
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
	virtual void a�adirIzquierda(Tablero* tab) = 0;
	virtual void a�adirDerecha(Tablero* tab) = 0;
	virtual void a�adirArriba(Tablero* tab) = 0;
	virtual void a�adirAbajo(Tablero* tab) = 0;
	virtual void Add(Tablero* tab, int f, int c) = 0;
	virtual void Delete() = 0;
	virtual char getValor(int f, int c) = 0;

	virtual bool validarPunto(char, int, int)=0;
	virtual bool agregarJugada(int x, int y) = 0;
	virtual int* origen() = 0;

};