#include "TableroIrregular.h"

TableroIrregular::TableroIrregular()
{
	filas = 30;
	columnas = 30;
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
}

string TableroIrregular::toString()
{
	stringstream s;
	s << "           col = 0    col = 1    col = 2    col = 3    col = 4    col = 5    col = 6    col = 7    col = 8    col = 9    col = 10" << endl;
	for (int i = 0; i < filas; i++) {/*
		s << "fil = " << i << "  ";*/
		for (int j = 0; j < columnas; j++) {
			s <</* "      "*/ mat[i][j] << "   ";
		}
		s << endl << endl;
	}
	
	return s.str();
}

void TableroIrregular::llenarMatriz()
{
}

void TableroIrregular::Add(Tablero* tab, int f, int c)
{
	int ancho = tab->getFilas() * 2;
	int largo = tab->getColumnas() * 2;

	// Verificar si el tablero a insertar está dentro del rango del TableroIrregular
	if (f < 0 || f + ancho > 30 || c < 0 || c + largo > 30) {
		cout << "Excepcion rango" << endl;
		return;
	}

	// Verificar si el lugar está ocupado
	for (int i = f; i < f + ancho-1; i++) {
		for (int j = c; j < c + largo-1; j++) {
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
 
//void TableroIrregular::Add(Tablero* tab, int f, int c)
//{
//	int ancho = tab->getFilas()*2;
//	int largo = tab->getColumnas()*2;
//	bool si = false;
//	do {
//		if (f > 30 || f < 0 || c>30 || c < 0) {
//			cout << "Excepcion rango" << endl;
//			break;
//			//throw "Excepcion rango";//
//		}
//		if (mat[f][c] != '.') {
//			cout << "Excepcion lugar ocupado " << endl;
//			//throw "Excepcion lugar ocupado ";//
//			break;
//		}
//		else {
//			for (int i = f; i < ancho; i++)
//				for (int j = c; j < largo; j++) {
//					if (mat[i][j] != '.')
//						cout << "Excepcion lugar ocupado " << endl;
//						break;
//					/*throw "Excepcion lugar ocupado";*/
//				}
//			for (int i = f; i < ancho; i++)
//				for (int j = c; j < largo; j++) {
//					/*if (i % 2 == 0 && j % 2 == 0)*/
//					mat[i][j] = '*';
//					/*else mat[i][j] = '-';
//					if (i % 2 != 0 && j % 2 != 0)
//						mat[i][j] = 'o';*/
//				}
//		}
//	} while (si);
//}

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
