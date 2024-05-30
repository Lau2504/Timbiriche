#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {//<<Interfaz>>
public:
	Jugador();
	virtual ~Jugador();
	virtual void setLetra(char)=0;
	virtual char getLetra()=0;
	virtual void jugar(int, int) = 0;
};

Jugador::Jugador() {}
Jugador::~Jugador() {}

#endif