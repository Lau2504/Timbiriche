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
	

	//virtual bool validarPunto(char, int, int);

	virtual int* origen();
	virtual int puntuacion(char);

	virtual int getCantidad();

	virtual Tablero* clone();
};
