#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaPeriferica : public Estrategia {
public:
	virtual int* ejecutarEstrategia();
	virtual ~EstrategiaPeriferica();
};

