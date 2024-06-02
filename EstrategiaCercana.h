#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaCercana : public Estrategia {
public:
	virtual int* ejecutarEstrategia();
	virtual ~EstrategiaCercana();
};
