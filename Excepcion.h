#ifndef EXCEPECION_H
#define EXCEPECION_H

#include <iostream>

class Excepcion{
	public:
	virtual const char* que(const char* mensaje) const=0;
};

#endif 