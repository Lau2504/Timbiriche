#pragma once
#include "TableroGlobal.h"
#include "Jugador.h"
#include "Vector.h"
#include "ExcepcionParametro.h"
class Juego{
private:
	Vector<Jugador>* jugadores;
	bool turno;
	public:
		Juego(Jugador* jugador1,Jugador* jugador2);
		virtual ~Juego();

		void iniciarJuego(Tablero*);//recibe por parametro el tablero con el que se va a jugar.
		//tambien se puede añadir directamente el tablero usando el singleton

		void hacerJugada(int,int);
		bool getTurno();//0 para jugador 1, 1 para jugador 2
};

