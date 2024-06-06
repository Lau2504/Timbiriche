#include "Tablero.h"

Tablero::Tablero():filaOrigen{0},columOrigen{0},filas{0},columnas{0} {
	for(int i = 0; i <filas; i++) {
		for(int j = 0; j < columnas; j++) {
			mat[i][j] = ' ';
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
bool Tablero::validarPunto(char c, int col, int fil) {
	bool b{ false };
	bool hayPunto{ false };
	b = col % 2;//0 es par, por ende se coloco una linea vertical, y el "escaneo" es horizontal
	//de lo contrario, si no es a es b...
	if (b) {
		if (fil != fil - 1)//leer abajo
			if (mat[fil + 2][col] != ' ' and mat[fil + 1][col + 1] != ' ' and mat[fil + 1][col - 1] != ' ') {
				mat[fil + 1][col] = c;
				hayPunto = true;
			}
		if (fil != 0)//leer arriba
			if (mat[fil - 2][col] != ' ' and mat[fil - 1][col + 1] != ' ' and mat[fil - 1][col - 1] != ' ') {
				mat[fil - 1][col] = c;
				hayPunto = true;
			}
	}
	else {//b==0->b%2==0->b es posicion de columna donde solo hay lineas verticales ║
		if (col != columnas - 1)//leer derecha
			if (mat[fil][col + 2] != ' ' and mat[fil + 1][col + 1] != ' ' and mat[fil - 1][col + 1] != ' ') {
				mat[fil][col + 1] = c;
				hayPunto = true;
			}
		if (col != 0)//leer izquierda
			if (mat[fil][col - 2] != ' ' and mat[fil + 1][col - 1] != ' ' and mat[fil - 1][col + 1] != ' ') {
				mat[fil][col - 1] = c;
				hayPunto = true;
			}
	}
	return hayPunto;
}

bool Tablero::agregarJugada(int x, int y) {
	if (x < 0 or y < 0) throw ExcepcionRango();
	if (!(x%2 xor y%2)) throw ExcepcionLugarReservado();
	if (mat[y][x] == '|' or mat[y][x]=='-') throw ExcepcionLugarOcupado();

	char c = '\0';
	x % 2 == 0 ? c = '|' : c = '-';
	mat[y][x] = c;
	return true;
}

void Tablero::setColumOrigen(int n) {columOrigen = n;}
void Tablero::setFilaOrigen(int n) { filaOrigen = n; }

int Tablero::getColumOrigen() { return columOrigen; }
bool Tablero::agregarJugadaCompu(int col, int fil)
{
	if (col < 0 or fil < 0) return false;
	if (!(col % 2 xor fil % 2)) return false;
	if (mat[fil][col] != ' ') return false;

	char c = '\0';
	col % 2 == 0 ? c = '|' : c = '-';
	mat[fil][col] = c;
	return true;
}
int Tablero::getFilaOrigen() { return filaOrigen; }