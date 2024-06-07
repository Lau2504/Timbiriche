#include "TableroIrregular.h"



TableroIrregular::TableroIrregular():Tablero(30,30)
{
	cantidad = 0;
	tamanio = 4;
	filas = 30;
	columnas = 30;
	for (int i = 0; i < tamanio; i++) {
		vec[i] = nullptr;
	}
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++) {
			mat[i][j] = char(39);
			/*if (i % 2 == 0 && j % 2 == 0)
				mat[i][j] = '+';
			else mat[i][j] = '-';
			if (i % 2 != 0 && j % 2 != 0)
				mat[i][j] = 'o';*/
		}
}

TableroIrregular::~TableroIrregular(){
	for (int i = 0; i < cantidad; i++){
		if (vec[i] != nullptr)
			delete vec[i];
	}
}

string TableroIrregular::toString(){
	stringstream s;

	//=========================================
	int col = vec[0]->getColumnas()+ vec[0]->getColumOrigen();
	int fil = vec[0]->getFilas()+vec[0]->getFilaOrigen();
	for (int i = 1; i < cantidad; i++) {
		int x = vec[i]->getColumOrigen() + vec[i]->getColumnas();
		int y = vec[i]->getFilaOrigen() + vec[i]->getFilas();
		(x) > col ? col = x : col;
		(y) > fil ? fil = y : fil;
	}
	
	for (int i = 0; i < cantidad; i++) {
		int* coords = vec[i]->origen();
		for (int j = 0; j < vec[i]->getFilas(); j++) {
			for (int k = 0; k < vec[i]->getColumnas(); k++) {
				mat[j + coords[1]][k + coords[0]] = vec[i]->getValor(j, k);
			}
		}
		delete[] coords;
	}
	s << "   ";
	for (int i = 0; i < col; i++) {
		s<<i+1<<setw(3);
	}
	s <<'\n';
	
	for (int i = 0; i < fil; i++) {
		s << setw(3) <<i+1;
		for (int j = 0; j <= col+1; j++) {
			s << mat[i][j]<<"  ";
		}
		s << endl;
	}

	return s.str();
}

void TableroIrregular::llenarMatriz(){}

void TableroIrregular::agregarIzquierda(Tablero* tab)
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
			if ((this->mat[i][j]) != ' ') {
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

void TableroIrregular::agregarDerecha(Tablero* tab) {
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

void TableroIrregular::agregarArriba(Tablero* tab)
{
	int ancho = tab->getFilas() * 2;
	int largo = tab->getColumnas() * 2;
	int FOri = -1;
	int COri = -1;
	int pos = (rand() % 6) + 1;

	// Encontrar el primer punto de origen ('+')
	for (int i = 0; i < this->filas; i++) {
		for (int j = 0; j < this->columnas; j++) {
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

void TableroIrregular::agregarAbajo(Tablero* tab)
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

void TableroIrregular::Add(Tablero* tab, int f, int c){

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

bool TableroIrregular::validarPunto(char ch, int col, int fila) {
	int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 };
	bool hayPunto{false};
	for (int i = 0; i < cantidad; i++) {
		//recoger datos
		int* coords = vec[i]->origen();
		a = (coords[0]);
		b = a + (vec[i]->getColumnas());
		c = (coords[1]);
		d = c + vec[i]->getFilas();
		//verificar si el punto pertenece a la matriz
		if (a <= col and col <= b and c <= fila and fila <= d) {
			//verificar si aumenta la puntuacion
			if(vec[i]->validarPunto(ch, col - a, fila - c))
				hayPunto = true;
		}		
		delete[] coords;
	}
	return hayPunto;
}

bool TableroIrregular::agregarJugada(int col, int fila) {
	int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 };
	bool hayJugada{ false };
	for (int i = 0; i < cantidad; i++) {
		int* coords = vec[i]->origen();
		a=(vec[i]->origen()[0]);
		b=a+(vec[i]->getColumnas());
		c=(vec[i]->origen()[1]);
		d = c + vec[i]->getFilas();
		//verificar si el punto pertenece a alguna matriz
		if (a <= col and col <= b and c <= fila and fila <= d)
			//verificar si se agrega la jugada
			if(vec[i]->agregarJugada(col - a, fila - c))
				hayJugada = true;
		delete[] coords;
	}
	return hayJugada;
}

int* TableroIrregular::origen() {
	return nullptr;
}

int TableroIrregular::puntuacion(char c) {
	int n = 0;
	for(int i=0;i<cantidad;i++)
		n += vec[i]->puntuacion(c);
	return n;
}

bool TableroIrregular::estaLleno() {
	for (int i = 0; i < cantidad; i++) {
		if (!vec[i]->estaLleno())
			return false;
	}
	return true;
}

void TableroIrregular::agregarTablero(Tablero* tab) {
	if (cantidad == 0) {
		vec[cantidad++] = tab;
		return;
	}
	std::srand(std::time(0));
	bool b=rand()%2;
	
	if (b) {//empujar todo derecha
		for (int i = 0; i < cantidad; i++) {
			int *coords = vec[i]->origen();
			vec[i]->setColumOrigen(coords[0]+tab->getColumnas()-1);
			delete[] coords;
		}
		int min = vec[cantidad - 1]->getFilaOrigen() - tab->getFilas();
		if (min < 0) min = 0;
		int max = vec[cantidad - 1]->getFilaOrigen() + vec[cantidad - 1]->getFilas();
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(min, max);
		int nOrigen = dis(gen);
		tab->setFilaOrigen(nOrigen-(!(nOrigen%2==0)));
			
	}else{//empujar todo abajo
		for (int i = 0; i < cantidad; i++) {
			int* coords = vec[i]->origen();
			vec[i]->setFilaOrigen(coords[1] + tab->getFilas() - 1);
			delete[] coords;
		}
		int min = vec[cantidad - 1]->getColumOrigen() - tab->getColumnas();
		if (min < 0) min = 0;
		int max = vec[cantidad - 1]->getColumOrigen() + vec[cantidad - 1]->getColumnas();
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(min, max);
		int nOrigen = dis(gen);
		tab->setColumOrigen(nOrigen-(!(nOrigen%2==0)));
	}
	vec[cantidad++] = tab;
}

int TableroIrregular::getCantidad()
{
	return cantidad;
}

Tablero** TableroIrregular::getTableros()
{
	return vec;
}

TableroIrregular::TableroIrregular(const TableroIrregular& otro):Tablero(30,30){
	cantidad = otro.cantidad;
	tamanio = otro.tamanio;
	filas = otro.filas;
	columnas = otro.columnas;

	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			mat[i][j] = otro.mat[i][j];
		}
	}
	for (int i = 0; i < cantidad; i++) {
		if (otro.vec[i] != nullptr) {
			vec[i] = otro.vec[i]->clone(); 
		}
		else {
			vec[i] = nullptr;
		}
	}
}

Tablero* TableroIrregular::clone()
{
	return nullptr;
}
