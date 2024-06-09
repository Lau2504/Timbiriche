#pragma once
#include "Estrategia.h"
#include "TableroGlobal.h"
class EstrategiaPropia : public Estrategia {
public:
	virtual int* ejecutarEstrategia();
	virtual ~EstrategiaPropia();
};
