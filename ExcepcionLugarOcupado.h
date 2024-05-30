#pragma once
#include "Excepcion.h"

class ExcepcionLugarOcupado :public Excepcion {
	virtual const char* que() const {
		return "Jugada invalida: ya existe una jugada en esa posicion. Escoja otra posicion";
	}
};