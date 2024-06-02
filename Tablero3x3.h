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
	virtual void agregarIzquierda(Tablero* tab);
	virtual void agregarDerecha(Tablero* tab);
	virtual void agregarArriba(Tablero* tab);
	virtual void agregarAbajo(Tablero* tab);

	virtual bool validarPunto(char, int, int);
	bool agregarJugada(int x, int y);
	virtual int* origen()override;
	virtual int puntuacion(char);

	virtual int getCantidad();
};
