#pragma once
#include "TableroGlobal.h"
#include <cstdlib>
#include <ctime>
#include "Vector.h"
class Estrategia {
public:
	virtual int* ejecutarEstrategia() = 0;
};