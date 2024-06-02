#pragma once
#include "TableroGlobal.h"
#include <cstdlib>
#include <ctime>
class Estrategia {
public:
	virtual int* ejecutarEstrategia() = 0;
};