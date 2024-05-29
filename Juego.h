#pragma once
#include "TableroGlobal.h"
#include "Jugador.h"
#include "Vector.h"
class Juego{
private:
	Vector<Jugador>* jugadores;
	bool turno;
	public:
		Juego(Jugador* jugador1,Jugador* jugador2);
		~Juego();
		void iniciarJuego();
		void jugar(int,int);

};

