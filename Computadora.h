#pragma once
#include "Jugador.h"
#include "Estrategia.h"
class Computadora : public Jugador {
private:
	char c;
	Estrategia* estrategia;
public:
	Computadora(char c, Estrategia* estrategia);
	virtual ~Computadora();
	char getLetra()override;
	bool jugar(int,int)override;

};
