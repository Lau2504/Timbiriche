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




};
