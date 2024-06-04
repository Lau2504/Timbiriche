#pragma once
#include"Memento.h"

class Originador {   // Lugar de transito...
private:
	Juego* estado;
public:
	void setEstado(Juego* est) { estado = est; }
	Juego* getEstado() { return estado; }
	Memento* retornarMemento() { return new Memento(estado); }
	void restaurarMemento(Memento* m) { estado = m->getPtrFoto(); }
};