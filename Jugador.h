#ifndef JUGADOR_H
#define JUGADOR_H
//#include "TableroGlobal.h"
class Jugador {//<<Interfaz>>

public:
	Jugador();
	virtual ~Jugador();
	//virtual void setLetra(char)=0;
	virtual char getLetra()=0;
	virtual bool jugar(int, int) = 0;//devuelve true si la jugada tiene un punto
};
#endif