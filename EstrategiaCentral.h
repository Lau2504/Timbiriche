#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaCentral: public Estrategia {
private:
	int* puntoInicio;
public:
	EstrategiaCentral();
	virtual int* ejecutarEstrategia();
	virtual ~EstrategiaCentral();
};


