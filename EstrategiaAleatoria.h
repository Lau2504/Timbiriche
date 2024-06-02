#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaAleatoria: public Estrategia {
public:
	virtual int* ejecutarEstrategia();
	virtual ~EstrategiaAleatoria();
};

