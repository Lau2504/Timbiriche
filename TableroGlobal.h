#ifndef TABLEROGLOBAL_H
#define	TABLEROGLOBAL_H
#include "Tablero.h"
#include "TableroIrregular.h"
class TableroGlobal {//singleton
private:
	static TableroGlobal* instancia;
	TableroGlobal();
	Tablero* tablero;
public:
	static TableroGlobal* getInstancia();
	Tablero* getTablero();
	void setTablero(Tablero*);
	virtual ~TableroGlobal();
};

#endif