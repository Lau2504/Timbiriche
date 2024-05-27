#pragma once
#include "Tablero.h"

class Tablero3x3 :public Tablero {
public:
	Tablero3x3();
	virtual ~Tablero3x3();
	virtual string toString();
	virtual void llenarMatriz();
	virtual void Add(Tablero* tab, int f, int c);
	virtual void Delete();
	virtual int getFilas();
	virtual int getColumnas();
	virtual char getValor(int f, int c);
	virtual void añadirIzquierda(Tablero* tab);
	virtual void añadirDerecha(Tablero* tab);
	virtual void añadirArriba(Tablero* tab);
	virtual void añadirAbajo(Tablero* tab);

	bool agregarJugada(int x, int y);
	virtual int* origen()override;
};
