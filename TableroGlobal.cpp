#include "TableroGlobal.h"

TableroGlobal* TableroGlobal::instancia = 0;

TableroGlobal::TableroGlobal() {
	tablero = nullptr;
}

TableroGlobal::~TableroGlobal() {
	if (tablero != nullptr) {
		delete tablero;
	}
}

TableroGlobal* TableroGlobal::getInstancia() {
	if (instancia == nullptr) {
		instancia = new TableroGlobal();
	}
	return instancia;
}

void TableroGlobal::setTablero(Tablero* tablero_dato) {
	this->tablero = tablero_dato;
}

Tablero* TableroGlobal::getTablero() {
	return tablero;
}