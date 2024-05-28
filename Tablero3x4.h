#pragma once
#include "Tablero.h"

class Tablero3x4 :public Tablero {
public:
	Tablero3x4();
	virtual ~Tablero3x4();
	virtual string toString();
	virtual void llenarMatriz();
	virtual void Add(Tablero* tab, int f, int c);
	virtual void Delete();
	virtual int getFilas();
	virtual int getColumnas();
	virtual char getValor(int f, int c);
	virtual void a�adirIzquierda(Tablero* tab);
	virtual void a�adirDerecha(Tablero* tab);
	virtual void a�adirArriba(Tablero* tab);
	virtual void a�adirAbajo(Tablero* tab);

	virtual bool validarPunto(char, int, int);
	bool agregarJugada(int x, int y);
	virtual int* origen();
};
