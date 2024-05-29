#pragma once
#include "ExcepcionLugar.h"

class ExcepcionLugarReservado :public ExcepcionLugar {
	virtual const char* que() const {
		return "No se puede hacer jugadas en esta posicion. Escoja otra posicion";
	}
};