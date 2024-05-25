#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template <class T>
class Lista {
private:
	Nodo<T>* inicio;
public:
	Lista();
	~Lista();
	void insertarInicio(T);
	void insertarFinal(T);
	bool buscar(T);
	int cantidad();
	T getDato(int);
	void setDato(T, int);
};


#endif