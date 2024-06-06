#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaIsla : public Estrategia {
private:
	Vector<int>* jugadas;
	int isla;
	void arreglarJugadas();
public:
	EstrategiaIsla();
	virtual int* ejecutarEstrategia();
	virtual ~EstrategiaIsla();
};
