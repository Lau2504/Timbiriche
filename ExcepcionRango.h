#pragma once
#include "Excepcion.h"

class ExcepcionRango :public Excepcion {
	virtual const char* que() const {
		return "Jugada invalida: la posicion seleccionada no esta en el rango del tablero. Escoja otra posicion";
	}
};