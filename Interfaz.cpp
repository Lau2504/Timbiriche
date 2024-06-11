#include "Interfaz.h"


Interfaz::Interfaz()
{
}

Interfaz::~Interfaz()
{
}

int Interfaz::menu()
{
	system("cls");
	int op;
	cout << " 1) Ver Juegos anteriores" << endl;
	cout << " 2) Nuevo Juego" << endl;
	cout << " 3) Salir" << endl;
	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	return op;
}

int Interfaz::menuInicio()
{
	system("cls");
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
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	return op;
}

int Interfaz::cuantosTableros(){
	int op;
	cout << "Digite la cantidad irregularidad (1-4): " << endl;
	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	if (op > 4)
		throw ExcepcionParametro();
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
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	return op;
}

int Interfaz::columna()
{
	int op;
	cout << "Digite la columna: " << endl;
	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
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

	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	if (op > 6 || op < 0) {
		throw ExcepcionParametro();
	}
	return op;
}

int Interfaz::cambiarEstrategia()
{
	int op;
	cout << "Desea cambiar la estrategia de la computadora:" << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl;

	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	return op;
}

int Interfaz::ganador(Juego* juego)
{
	int opc;
	cout << "El ganador es: " << juego->ganador() << endl << endl;
	cout << "1) Volver al menu principal" << endl;
	cout << "2)Salir" << endl;
	cin >> opc;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	if (opc == 2) {
		opc = 3;
	}
	return opc;
}

void Interfaz::noHayJugadas()
{
	cout << "No hay jugadas anteriores para ver " << endl;
}

void Interfaz::mostrarJuego(Juego* j) {
	cout << j->dibujar();
}

string Interfaz::mostrarHistorial(Repositorio* rep) {
	string input;
	cout << "lista de partidas: \n";
	cout << rep->listarPartidas();
	cout<<"Escriba el nombre de la partida que desea ver: ";
	cin>> input;
	return input;
}

void Interfaz::mostrarPartida(string nombre,Repositorio* repo) {
	cout<<repo->mostrarPartida(nombre);
}

int Interfaz::jugarSiempreMismaEstrategia()
{
	int op;
	cout << "Desea jugar con la misma estrategia toda la partida contra la computadora:" << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl;

	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw ExcepcionRango();
	}
	return op;
}
