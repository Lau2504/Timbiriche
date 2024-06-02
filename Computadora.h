#pragma once
#include "Jugador.h"
#include "Estrategia.h"
class Computadora : public Jugador {
private:
	char c;
	Estrategia* estrategia;
public:
	Computadora(Estrategia* estrat);
	virtual ~Computadora();
	char getLetra()override;
	bool jugar(int,int)override;
	void setEstrategia(Estrategia* estra);

};
