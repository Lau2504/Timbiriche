#pragma once
#include <cstdlib> 
#include <ctime>   
#include <iomanip>
#include <random>
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
	virtual void agregarIzquierda(Tablero* tab);
	virtual void agregarDerecha(Tablero* tab);
	virtual void agregarArriba(Tablero* tab);
	virtual void agregarAbajo(Tablero* tab);
	virtual void Add(Tablero* tab, int f, int c);
	virtual void Delete();
	virtual int getFilas();
	virtual int getColumnas();
	virtual char getValor(int f, int c);

	virtual bool validarPunto(char, int, int)override;
	virtual bool agregarJugada(int x, int y)override;
	int* origen()override;
	virtual int puntuacion(char);
	bool estaLleno()override;
	//metodo "propio" para agregar tableros en momento de cuando se pregunte
	//no se puede ver en la interfaz...
	void agregarTablero(Tablero* tab);
	

	virtual int getCantidad();
	Tablero** getTableros();

	TableroIrregular(const TableroIrregular& otro);
	virtual Tablero* clone();
};