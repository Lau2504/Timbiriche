#pragma once
#include "Tablero.h"
#include "Tablero3x3.h"
#include "Tablero3x4.h"
#include "Tablero3x5.h"

class TableroIrregular :public Tablero {
	//Matriz grande que contiene otras matrices
public:

	TableroIrregular();
	virtual ~TableroIrregular();
	virtual string toString();
	virtual void llenarMatriz();
	virtual void Add(Tablero* tab, int f, int c);
	virtual void Delete();
	virtual int getFilas();
	virtual int getColumnas();
};