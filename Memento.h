#pragma once
#pragma once
#include"Juego.h"

class Memento {
private:
	Juego* ptrFoto;
public:
	Memento(Juego* foto) { ptrFoto = foto; }
	Juego* getPtrFoto() { return ptrFoto; }
};
