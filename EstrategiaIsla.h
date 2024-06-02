#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaIsla : public Estrategia {
public:
	virtual int* ejecutarEstrategia();
};
