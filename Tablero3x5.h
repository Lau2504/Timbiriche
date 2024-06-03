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
	virtual char getValor(int f, int c);
	virtual void agregarIzquierda(Tablero* tab);
	virtual void agregarDerecha(Tablero* tab);
	virtual void agregarArriba(Tablero* tab);
	virtual void agregarAbajo(Tablero* tab);

	//virtual bool validarPunto(char, int, int);
	
	virtual int* origen();
	virtual int puntuacion(char);

	virtual int getCantidad();
};
