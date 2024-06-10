#pragma once
#include <iostream>
#include <sstream>
#include <locale>
#include "Excepciones.h"
//use esto cuando necesite poner la ñ o acentos
//std::setlocale(LC_ALL, "");
//se pone adentro de la funcion que tiene el cout
using namespace std;

class Interfaz {
public:
	Interfaz();
	virtual ~Interfaz();
	static int menu();
	static int menuInicio();
	static char inicio();
	static char otroJugador();
	static int tablero();
	static int cuantosTableros();
	static void mostrarTablero(Tablero* tab);
	static int fila();
	static int columna();
	static int escogerEstrategia();
	static int cambiarEstrategia();
	static int ganador(Juego*);
	static void noHayJugadas();
	static void mostrarJuego(Juego*);
	static string mostrarHistorial(Repositorio*);
	static void mostrarPartida(string nombre, Repositorio* re);
};