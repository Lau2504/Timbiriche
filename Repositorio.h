#pragma once
#pragma once
#include"Memento.h"

class Repositorio {    // Repositorio de Mementos...
private:
	Memento* vec[128];
	int can;
	int tam;
public:
	Repositorio() {
		can = 0;
		tam = 128;
		for (int i = 0; i < tam; i++)
			vec[i] = nullptr;
	}

	void agregaMemento(Memento* m) {
		if (can < tam) {
			vec[can++] = m;
			cout << "Memento agregado en la posición: " << (can - 1) << endl;
		}
		else {
			cout << "No se puede agregar más mementos, el repositorio está lleno." << endl;
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
				<< vec[i]->getPtrFoto()->getTablero()->toString() << endl << endl; //esta llamando al tablero global no al tablero del memento
		}
		return s.str();
	}

};