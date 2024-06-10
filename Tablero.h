#pragma once
#include <iostream>
#include <sstream>


#include "ExcepcionLugarOcupado.h"
#include "ExcepcionRango.h"
#include "ExcepcionLugarReservado.h"


using namespace std;

class Tablero {
protected:
	int filaOrigen;
	int columOrigen;
	int filas;
	int columnas;
	char mat[30][30];
	int ultimaColumna; 
	int ultimaFila;    
public:
	Tablero(int col,int fil);
	virtual ~Tablero();
	virtual string toString() = 0;
	virtual int getFilas() = 0;
	virtual int getColumnas() = 0;
	virtual void llenarMatriz() = 0;
	virtual void Add(Tablero* tab, int f, int c) = 0;
	virtual void Delete() = 0;
	virtual char getValor(int f, int c) = 0;

	virtual bool validarPunto(char, int, int);
	virtual bool agregarJugada(int col, int fil);
	virtual int* origen() = 0;
	virtual int puntuacion(char) = 0;
	
	virtual bool estaLleno();
	virtual void setFilaOrigen(int);
	virtual void setColumOrigen(int);
	virtual int getFilaOrigen();
	virtual int getColumOrigen();

	virtual int getCantidad() = 0;

	virtual Tablero* clone() = 0;
	bool agregarJugadaCompu(int col, int fil);
	void deshacerJugada(int col, int fila);
	int* ultimaJugada();
	bool espacioValido(int col, int fil);
};