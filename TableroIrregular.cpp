#include "TableroIrregular.h"

TableroIrregular::TableroIrregular()
{
	cantidad = 0;
	tamanio = 6;
	filas = 30;
	columnas = 30;
	for (int i = 0; i < tamanio; i++) {
		vec[i] = nullptr;
	}
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++) {
			mat[i][j] = ' ';
			/*if (i % 2 == 0 && j % 2 == 0)
				mat[i][j] = '+';
			else mat[i][j] = '-';
			if (i % 2 != 0 && j % 2 != 0)
				mat[i][j] = 'o';*/
		}
}

TableroIrregular::~TableroIrregular()
{
	for (int i = 0; i < cantidad; i++) {
		if (vec[i] != nullptr)
			delete vec[i];
	}
	delete[] vec;
}

string TableroIrregular::toString()
{
	stringstream s;
	int col = 0;
	s << "  ";
	do {
		s << col << "   ";
		col++;
	} while (col != 30);
	for (int i = 0; i < filas; i++) {
		s << i << "  ";
		for (int j = 0; j < columnas; j++) {
			s <</*"      "*/ mat[i][j] << "   ";
		}
		s << endl << endl;
	}
	
	return s.str();
}

void TableroIrregular::llenarMatriz(){}

void TableroIrregular::añadirIzquierda(Tablero* tab)
{
	int ancho = tab->getFilas() * 2;
	int largo = tab->getColumnas() * 2;
	int FOri = -1;
	int COri = -1;
	int pos = (rand() % 6) + 1;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (mat[i][j] == '+') {
				FOri = i;
				COri = j;
				break;
			}
			
		}
		if (FOri != -1) break; // ya se encontro el punto de origen
	}
	FOri += pos; //posicion randon de la columna de la matriz que ya existe, 6 porque todas las matrices tienen la misma cantidad de filas
	for (int i = FOri - ancho + 1; i <= FOri; i++) {
		for (int j = COri - largo; j < COri; j++) {
			if (mat[i][j] != ' ') {
				cout << "Excepcion lugar ocupado" << endl;
				return;
			}
		}
	}
	if (COri < largo) {
		cout << "No hay espacio para poner la matriz a la izquierda" << endl;
		return;
	}
	else {
		
		for (int i = FOri - ancho+1; i <= FOri; i++) {
			for (int j = COri - largo; j < COri; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					mat[i][j] = '+';
				}
				else if (i % 2 == 0) {
					mat[i][j] = '-';
				}
				else if (j % 2 == 0) {
					mat[i][j] = '|';
				}
				else {
					mat[i][j] = 'o';
				}	
			}
		}
	}
}

void TableroIrregular::añadirDerecha(Tablero* tab) {
	int ancho = tab->getFilas() * 2;
	int largo = tab->getColumnas() * 2;
	int Ffin = -1;
	int Cfin = -1;

	// Encontrar el '+' más a la derecha
	for (int i = 0; i < filas; i++) {
		for (int j = columnas - 1; j >= 0; j--) {
			if (mat[i][j] == '+') {
				Ffin = i;
				Cfin = j;
				break;
			}
		}
		if (Ffin != -1) break; // ya se encontró el punto de origen
	}

	if (Ffin == -1 || Cfin == -1) {
		cout << "No se encontró un punto final válido." << endl;
		return;
	}

	// Verificar si hay suficiente espacio a la derecha
	if (Cfin + 1 + largo > columnas || Ffin + ancho > filas) {
		cout << "No hay espacio para poner la matriz a la derecha" << endl;
		return;
	}

	// Verificar si el espacio está ocupado
	for (int i = Ffin; i < Ffin + ancho; i++) {
		for (int j = Cfin + 1; j < Cfin + 1 + largo; j++) {
			if (mat[i][j] != ' ') {
				cout << "Excepcion lugar ocupado" << endl;
				return;
			}
		}
	}
	// Colocar el nuevo sub-tablero a la derecha
	for (int i = Ffin; i < Ffin + ancho; i++) {
		for (int j = Cfin + 1; j < Cfin + largo + 2; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				mat[i][j] = '+';
			}
			else if (i % 2 == 0) {
				mat[i][j] = '-';
			}
			else if (j % 2 == 0) {
				mat[i][j] = '|';
			}
			else {
				mat[i][j] = 'o';
			}
		}
	}
}
void TableroIrregular::añadirArriba(Tablero* tab)
{
	int ancho = tab->getFilas() * 2;
	int largo = tab->getColumnas() * 2;
	int FOri = -1;
	int COri = -1;
	int pos = (rand() % 6) + 1;

	// Encontrar el primer punto de origen ('+')
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (mat[i][j] == '+') {
				FOri = i;
				COri = j;
				break;
			}
		}
		if (FOri != -1) break;
	}

	if (FOri == -1 || COri == -1) {
		cout << "No se encontró un punto de origen válido." << endl;
		return;
	}

	COri += pos; // Ajustar la posición en la columna

	// Verificar si hay suficiente espacio arriba y si la posición COri es válida
	if (FOri - ancho < 0 || COri < 0 || COri + largo > columnas) {
		cout << "No hay espacio para poner la matriz arriba" << endl;
		return;
	}

	// Verificar si el espacio está ocupado
	for (int i = FOri - ancho; i < FOri; i++) {
		for (int j = COri; j < COri + largo; j++) {
			if (mat[i][j] != ' ') {
				cout << "Excepcion lugar ocupado" << endl;
				return;
			}
		}
	}

	// Colocar el nuevo sub-tablero arriba
	for (int i = FOri - ancho; i < FOri; i++) {
		for (int j = COri; j < COri + largo; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				mat[i][j] = '+';
			}
			else if (i % 2 == 0) {
				mat[i][j] = '-';
			}
			else if (j % 2 == 0) {
				mat[i][j] = '|';
			}
			else {
				mat[i][j] = 'o';
			}
		}
	}
}



void TableroIrregular::añadirAbajo(Tablero* tab)
{
	int ancho = tab->getFilas() * 2;
	int largo = tab->getColumnas() * 2;
	int Ffin = -1;
	int Cfin = -1;

	// Encontrar el último punto de origen ('+')
	for (int i = filas - 1; i >= 0; i--) {
		for (int j = columnas - 1; j >= 0; j--) {
			if (mat[i][j] == '+') {
				Ffin = i;
				Cfin = j;
				break;
			}
		}
		if (Ffin != -1) break; // ya se encontró el punto final
	}

	if (Ffin == -1 || Cfin == -1) {
		cout << "No se encontró un punto final válido." << endl;
		return;
	}

	// Verificar si hay suficiente espacio abajo
	if (Ffin + 1 + ancho > filas || Cfin - largo + 1 < 0) {
		cout << "No hay espacio para poner la matriz abajo" << endl;
		return;
	}

	// Verificar si el espacio está ocupado
	for (int i = Ffin + 1; i <= Ffin + ancho; i++) {
		for (int j = Cfin - largo + 1; j <= Cfin; j++) {
			if (mat[i][j] != ' ') {
				cout << "Excepcion lugar ocupado" << endl;
				return;
			}
		}
	}

	// Colocar el nuevo sub-tablero abajo
	for (int i = Ffin + 1; i <= Ffin + ancho; i++) {
		for (int j = Cfin - largo + 1; j <= Cfin; j++) {
			if ((i - (Ffin + 1)) % 2 == 0 && (j - (Cfin - largo + 1)) % 2 == 0) {
				mat[i][j] = '+';
			}
			else if ((i - (Ffin + 1)) % 2 == 0) {
				mat[i][j] = '-';
			}
			else if ((j - (Cfin - largo + 1)) % 2 == 0) {
				mat[i][j] = '|';
			}
			else {
				mat[i][j] = 'o';
			}
		}
	}
}


void TableroIrregular::Add(Tablero* tab, int f, int c)
{
	//agregar tablero al vector
	if (cantidad < tamanio) {
		vec[cantidad++] = tab;
	}

	//puntos de origen

	filaOrigen = f;
	columOrigen = c;
	
	int ancho = tab->getFilas() * 2;
	int largo = tab->getColumnas() * 2;

	// Verificar si el tablero a insertar está dentro del rango del TableroIrregular
	if (f < 0 || f + ancho > 30 || c < 0 || c + largo > 30) {
		cout << "Excepcion rango" << endl;
		return;
	}

	// Verificar si el lugar está ocupado
	for (int i = f; i < f + ancho-1; i++) {
		for (int j = c; j < c + largo - 1; j++) {
			if (mat[i][j] != ' ') {
				cout << "Excepcion lugar ocupado" << endl;
				return;
			}
		}
	}
	// Agregar el tablero al TableroIrregular

	if (f % 2 != 0) f++;
	if (c % 2 != 0)c++;
	//Se coloca en una entrada par para poder llevar un orden siempre
	

	
	for (int i = f; i < f + ancho - 1; i++) {
		for (int j = c; j < c + largo - 1; j++) {
			if (j % 2 == 0)
				mat[i][j] = '|';
			else mat[i][j] = '-';
			if (i % 2 == 0 && j % 2 == 0)
				mat[i][j] = '+';
			if (i % 2 != 0 && j % 2 != 0)
				mat[i][j] = 'o';
		}
	}
}
//Para que se pueda hacer el dibujo bien, se debe poner en una entrada par para que vaya 
// correctamente 
// 
//si va  a jugar para abajo la fila es mayor a la columna o sea es vertical

//Hacer una función en juego que le de las coordenadas al Add para que las matrices queden a la par y 
//y preguntarle al usuario cuando está eligiendo el tamaño de las matrices, no donde ponerlas

void TableroIrregular::Delete()
{
}

int TableroIrregular::getFilas()
{
	return filas;
}

int TableroIrregular::getColumnas()
{
	return columnas;
}

char TableroIrregular::getValor(int f, int c)
{
	if (f < 0 || f  > 30 || c < 0 || c  > 30)
		//throw Excepcion Fuera de Rango
		return ' ';
	else
		return mat[f][c];
}

bool Tablero3x3::validarPunto(char c, int x, int y) {
	bool b = false;
	b = x % 2;//0 es par, por ende se coloco una linea vertical, y el "escaneo" es horizontal
	//de lo contrario, si no es a es b...
	
	return true;
}

bool TableroIrregular::agregarJugada(int x, int y) {
	int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 };
	for (int i = 0; i < cantidad; i++) {
		
		a=(vec[i]->origen()[0]);
		b=a+(vec[i]->getColumnas());
		c=(vec[i]->origen()[1]);
		d=c+3;
		if (a <= x and x <= b and c <= y and y <= d)
			vec[i]->agregarJugada(x - a, y - c);
	}
	return true;//probablemente sea una coordenada que no pertenece a ningunga matriz...
}

int* TableroIrregular::origen() {
	return nullptr;
}