#pragma once
#include "Excepcion.h"

class ExcepcionParametro : public Excepcion {
	const char* que() const {
		return "Error en los parametros. Jugador no puede ser nullptr";
	}
};