#pragma once
#include "Tablero.h"

class Tablero3x5 :public Tablero {
public:
	Tablero3x5();
	virtual ~Tablero3x5();
	virtual string toString();
	virtual void llenarMatriz();
	virtual void Add(Tablero* tab, int f, int c);
	virtual void Delete();
	virtual int getFilas();
	virtual int getColumnas();

};
