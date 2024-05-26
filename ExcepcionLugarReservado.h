#pragma once
#include "ExcepcionLugar.h"

class ExcepcionLugarOcupado :public ExcepcionLugar {
	virtual const char* que(const char* mensaje) const {
		return "No se puede hacer jugadas en esta posicion. Escoja otra posicion";
	}
};