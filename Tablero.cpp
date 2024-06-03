#include "Tablero.h"

Tablero::Tablero():filaOrigen{0},columOrigen{0},filas{0},columnas{0} {
	for(int i = 0; i <filas; i++) {
		for(int j = 0; j < columnas; j++) {
			mat[i][j] = '\0';
		}
	}
}

Tablero::~Tablero() {}

bool Tablero::estaLleno() {
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) { //Por qué 3 ? //edit: ups...
			if(mat[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

bool Tablero::agregarJugada(int x, int y) {
	if (x < 0 or y < 0) throw ExcepcionRango();
	if (mat[y][x] != ' ') throw ExcepcionLugarOcupado();
	if (x == y) throw ExcepcionLugarReservado();

	char c = '\0';
	x % 2 == 0 ? c = 'l' : c = '-';
	mat[y][x] = c;
	return true;
}

void Tablero::setColumOrigen(int n) {columOrigen = n;}
void Tablero::setFilaOrigen(int n) { filaOrigen = n; }

int Tablero::getColumOrigen() { return columOrigen; }
int Tablero::getFilaOrigen() { return filaOrigen; }