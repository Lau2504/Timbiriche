#pragma once
#include "Excepcion.h"

class ExcepcionLugar :public Excepcion {
	virtual const char* que() const = 0;
};