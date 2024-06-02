#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaCentral: public Estrategia {
public:
	virtual int* ejecutarEstrategia();
	virtual ~EstrategiaCentral();
};


