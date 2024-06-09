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
	this->filas = fil;
	this->columnas = col;
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
		for (int j = 0; j < col; j++) {
			s << mat[i][j]<<"  ";
		}
		s <<i+1<< endl;
	}
	s << "   ";
	for (int i = 0; i < col; i++) {
		s << i + 1 << setw(3);
	}
	s << '\n';
	return s.str();
}

void TableroIrregular::llenarMatriz()
{
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
	ultimaColumna = col;
	ultimaFila = fila;
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
	if(!hayJugada)throw ExcepcionRango();
	ultimaColumna = col;
	ultimaFila = fila;
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
	if (tamanio < cantidad)throw ExcepcionRango();
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

	{//ajustar filas y columnas
		int col = vec[0]->getColumnas() + vec[0]->getColumOrigen();
		int fil = vec[0]->getFilas() + vec[0]->getFilaOrigen();
		for (int i = 1; i < cantidad; i++) {
			int x = vec[i]->getColumOrigen() + vec[i]->getColumnas();
			int y = vec[i]->getFilaOrigen() + vec[i]->getFilas();
			(x) > col ? col = x : col;
			(y) > fil ? fil = y : fil;
		}
		this->filas = fil;
		this->columnas = col;
	}

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
	return new TableroIrregular(*this);
}
