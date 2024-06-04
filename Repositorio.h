#pragma once
#pragma once
#include"Memento.h"

class Repositorio {    // Repositorio de Mementos...
private:
	Memento* vec[60];
	int can;
	int tam;
public:
	Repositorio() {
		can = 0;
		tam = 10;
		for (int i = 0; i < tam; i++)
			vec[i] = nullptr;
	}

	void agregaMemento(Memento* m) {
		if (can < tam) {
			vec[can++] = m;
		}
	}

	Memento* getMemento(int pos) {
		if (pos >= 0 && pos < can)
			return vec[pos];
		else
			return nullptr;
	}

	int getCan() { return can; }

	string toString() {
		stringstream s;
		s << "----Los mementos en orden cronologico que existen son:----" << endl;
		for (int i = 0; i < can; i++) {
			s << "No. " << i + 1 << "    Punto de Chequeo = "
				<< vec[i]->getPtrFoto()->getPuntoChequeo() << endl
				<< endl
				<< vec[i]->getPtrFoto()->dibujar() << endl << endl;
		}
		return s.str();
	}

};