#include "Interfaz.h"


Interfaz::Interfaz()
{
}

Interfaz::~Interfaz()
{
}

int Interfaz::menuInicio()
{
	int op;
	cout << " 1) Jugar contra otro jugador" << endl;
	cout << " 2) Jugar contra la computadora" << endl;
	cout << " 3) Salir" << endl;
	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	return op;	
}

char Interfaz::inicio()
{
	char inicial;
	cout << "Digite la inicial para el jugador 1" << endl;
	cin >> inicial;
	//excepcion char 
	return inicial;
}

char Interfaz::otroJugador()
{
	char inicial;
	cout << "Digite la inicial para el Jugador 2" << endl;
	cin >> inicial;
	//excepcion char 
	return inicial;
}

int Interfaz::tablero()
{
	int op;
	cout << "Para empezar, escoja un tipo de tablero: " << endl
		<< " 1) Manual" << endl
		<< " 2) Aleatorio" << endl;
	cin >> op;
	return op;
}

int Interfaz::cuantosTableros(){
	int op;
	cout << "Digite la cantidad irregularidad (1-6): " << endl;
	cin >> op;
	return op;
}

void Interfaz::mostrarTablero(Tablero* tab)
{
	cout << tab->toString();
}

int Interfaz::fila()
{
	int op;
	cout << "Digite la fila: " << endl;
	cin >> op;
	return op;
}

int Interfaz::columna()
{
	int op;
	cout << "Digite la columna: " << endl;
	cin >> op;
	return op;
}

int Interfaz::escogerEstrategia()
{
	int op;
	cout << "Cuál estrategia desea que tenga la computadora: " << endl;
	cout << "1)Aleatoria" << endl;
	cout << "2)Central" << endl;
	cout << "3)Periferica" << endl;
	cout << "4)Isla" << endl;
	cout << "5)Cercana" << endl;
	cout << "6)Sorpresa" << endl;
	cout << "7)Regresar" << endl;

	cin >> op;
	return op;
}

int Interfaz::cambiarEstrategia()
{
	int op;
	cout << "Desea cambiar la estrategia de la computadora:" << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl;

	cin >> op;
	return op;
}
