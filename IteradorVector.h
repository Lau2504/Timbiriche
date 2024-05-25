#ifndef ITERADORVECTOR_H
#define ITERADORVECTOR_H

#include "Vector.h"
#include <iostream>
template <class T> class Vector;

template <class T>
class IteradorVector {
private:
	T** vector;
public:
	IteradorVector(T**);
	virtual ~IteradorVector();
	
	IteradorVector& operator++();
	bool operator!=(const IteradorVector&);
	T& operator*();
};

template <class T>
IteradorVector<T>::IteradorVector(T** vec): vector(vec) {}

template <class T>
IteradorVector<T>::~IteradorVector() {}

template <class T>
IteradorVector<T>& IteradorVector<T>::operator++() {
	vector++;
	return *this;
}

template <class T>
bool IteradorVector<T>::operator!=(const IteradorVector<T>& otro) {
	return vector != otro.vector;
}

template <class T>
T& IteradorVector<T>::operator*() {
	return **vector;
}
#endif