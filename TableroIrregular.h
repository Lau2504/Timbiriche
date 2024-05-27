#pragma once
#include "Tablero.h"
#include "Tablero3x3.h"
#include "Tablero3x4.h"
#include "Tablero3x5.h"

class TableroIrregular :public Tablero {
	//Matriz grande que contiene otras matrices
private:
	int cantidad;
	int tamanio;
	Tablero* vec[6];
public:

	TableroIrregular();
	virtual ~TableroIrregular();
	virtual string toString();
	virtual void llenarMatriz();
	virtual void añadirIzquierda(Tablero* tab);
	virtual void añadirDerecha(Tablero* tab);
	virtual void añadirArriba(Tablero* tab);
	virtual void añadirAbajo(Tablero* tab);
	virtual void Add(Tablero* tab, int f, int c);
	virtual void Delete();
	virtual int getFilas();
	virtual int getColumnas();
	virtual char getValor(int f, int c);

	bool agregarJugada(int x, int y);
};