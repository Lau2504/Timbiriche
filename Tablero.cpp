#include "Tablero.h"

Tablero::Tablero():filaOrigen{0},columOrigen{0},filas{0},columnas{0} {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			mat[i][j] = '\0';
		}
	}
}

Tablero::~Tablero() {}

bool Tablero::estaLleno() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) { //Por qué 3 ?
			if(mat[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

void Tablero::setColumOrigen(int n) {columOrigen = n;}
void Tablero::setFilaOrigen(int n) { filaOrigen = n; }