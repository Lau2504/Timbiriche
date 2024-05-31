#ifndef PERSONA_H
#define PERSONA_H
#include "Jugador.h"
#include "TableroGlobal.h"
class Persona : public Jugador {
private:
	char letra;
public:
	Persona(char);
	virtual ~Persona();
	//void setLetra(char);
	char getLetra()override;
	bool jugar(int, int)override;
};

#endif