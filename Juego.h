#pragma once
#include "TableroGlobal.h"
#include "Jugador.h"
#include "Vector.h"
#include "ExcepcionParametro.h"
class Juego{
private:
	Vector<Jugador>* jugadores;
	bool turno;
	int puntoChequeo;
	//
	Tablero* tablero;

	public:
		Juego(Jugador* jugador1,Jugador* jugador2);
		virtual ~Juego();
		bool getTurno();//0 para jugador 1, 1 para jugador 2
		
		void iniciarJuego(Tablero*);//recibe por parametro el tablero con el que se va a jugar.
		//tambien se puede añadir directamente el tablero usando el singleton
		void hacerJugada(int,int);//si retorna true, hubo punto
		bool sigueJuego();
		string dibujar();
		void setTurno(bool n);
		char ganador();

		//Memento
		int getPuntoChequeo();
		void setPuntoChequeo(int);
		Juego(const Juego& otro);
		Juego& operator=(const Juego& otro);
};

