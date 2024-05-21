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

};
