#ifndef VECTOR_H
#define VECTOR_H
#include "IteradorVector.h"
#include "ExcepcionRango.h"
template <class T> class IteradorVector;
template <class T>
class Vector {
private:
	T** vec;
	int tam;
	int can;
public:
	Vector(int tam);
	virtual ~Vector();
	IteradorVector<T> inicio();
	IteradorVector<T> ultimo();
	int cantidad();
	T* sacar(int=0);
	bool agregarInicio(T*);
	bool agregarFinal(T*);
	T& operator[](int);
	
};

template <class T>
Vector<T>::Vector(int tam_dato) :can{ 0 }, tam{ tam_dato }, vec{ new T * [tam_dato] } {
	for(int i=0;i<tam;i++) this->vec[i] = nullptr;
}

template <class T>
Vector<T>::~Vector() {//este vector borra todos los elementos que contiene
	for (int i = 0; i < tam; i++) {
		if (vec[i] != nullptr) delete vec[i];
	}
	delete[] vec;
}

template <class T>
int Vector<T>::cantidad() {
	return can;
}

template <class T> 
IteradorVector<T> Vector<T>::inicio() {
	return IteradorVector<T>(vec);
}

template <class T>
IteradorVector<T> Vector<T>::ultimo() {
	return IteradorVector<T>(vec + can);//gracias a la aritemtica de punteros y vectores, se puede dar un puntero a un vector que apunte al final de este
}

template <class T>
T* Vector<T>::sacar(int pos) {
	if (pos < 0 or pos >= can) return nullptr;
	T* dato = vec[pos];
	for (int i = pos; i < can - 1; i++) {
		vec[i] = vec[i + 1];
	}
	can--;
	return dato;
}

template <class T>
bool Vector<T>::agregarInicio(T* dato) {
	if (can >= tam) return false;
	for (int i = can; i > 0; i--) {
		vec[i] = vec[i - 1];
	}
	vec[0] = dato;
	can++;
	return true;
}

template <class T>
bool Vector<T>::agregarFinal(T* dato) {
	if (can >= tam) return false;
	vec[can++] = dato;
	return true;
}

template <class T>
T& Vector<T>::operator[](int pos) {
	if (pos < 0 or pos >= can) throw ExcepcionRango();
	return *(vec[pos]);
}

#endif