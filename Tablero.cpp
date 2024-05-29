#include "Tablero.h"

bool Tablero::estaLleno() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(mat[i][j] == '\0') {
				return false;
			}
		}
	}
	return true;
}