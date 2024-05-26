#ifndef NODO_H
#define NODO_H
template <class T>
class Nodo {
private:
	Nodo* sig;
	T* dato;
public:
	Nodo();
	Nodo(T*);
	virtual ~Nodo();
	void setDato(T* dato);
	T* getDato();
	void setSig(Nodo* sig);
	Nodo* getSig();

};

template <class T>
Nodo<T>::Nodo():dato{nullptr}, sig{nullptr}{}

template <class T>
Nodo<T>::Nodo(T* dato_info):dato{dato_info}, sig{nullptr} {}

template <class T>
Nodo<T>::~Nodo() {}

template <class T>
void Nodo<T>::setDato(T* dato) { this->dato = dato; }

template <class T>
T* Nodo<T>::getDato() { return dato; }

template <class T>
void Nodo<T>::setSig(Nodo* sig) { this->sig = sig; }

template <class T>
Nodo<T>* Nodo<T>::getSig() { return sig; }


#endif