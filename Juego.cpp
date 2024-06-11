#include "Juego.h"

Juego::Juego(Jugador* jug1, Jugador* jug2) :turno { false } {
	if (jug1 == nullptr or jug2 == nullptr)
		throw ExcepcionParametro();
	jugadores= new Vector<Jugador>(2);
	jugadores->agregarInicio(jug1);
	jugadores->agregarFinal(jug2);

	//
	TableroGlobal* ptr = TableroGlobal::getInstancia();
	tablero = ptr->getTablero();
}

Juego::~Juego() {
	if(jugadores)delete jugadores;
}

bool Juego::getTurno() { return turno; }

void Juego::iniciarJuego(Tablero* tab) {
	//std::cout << "Iniciando Juego\n";
	turno = 0;
	TableroGlobal::getInstancia()->setTablero(tab);
	//
	tablero = tab;
}

void Juego::hacerJugada(int col, int fil) {
	if (!(*jugadores)[turno].jugar(col-1,fil-1))//si retorna false, no hubo punto. por lo tanto, cambio de turno
		turno = !turno;
}

bool Juego::sigueJuego() {
	return !TableroGlobal::getInstancia()->getTablero()->estaLleno();
}

string Juego::dibujar() {
	TableroGlobal* ptr = TableroGlobal::getInstancia();
	Tablero* tab = ptr->getTablero();
	
	tablero = tab;
	stringstream s;
	s << "Puntuacion\n";
	s << "Jugador " << (*jugadores)[0].getLetra() << ": " << tab->puntuacion((*jugadores)[0].getLetra()) << " puntos\n";
	s << "Jugador " << (*jugadores)[1].getLetra() << ": " << tab->puntuacion((*jugadores)[1].getLetra()) << " puntos\n";
	s<<"\nTurno de: "<<(*jugadores)[turno].getLetra()<<endl;
	s << tab->toString();
	return s.str();
}

void Juego::setTurno(bool n)
{
	turno = n;
}

char Juego::ganador()
{
	TableroGlobal* ptr = TableroGlobal::getInstancia();
	Tablero* tab = ptr->getTablero();
	if (tab->puntuacion((*jugadores)[0].getLetra()) == tab->puntuacion((*jugadores)[1].getLetra()))
		return '!';//empate
	if (tab->puntuacion((*jugadores)[0].getLetra())>tab->puntuacion((*jugadores)[1].getLetra()))
		return ((*jugadores)[0].getLetra());
	else return ((*jugadores)[1].getLetra());
}

int Juego::getPuntoChequeo()
{
	return puntoChequeo;
}

void Juego::setPuntoChequeo(int n)
{
	puntoChequeo = n;
}

Juego::Juego(const Juego& otro) {
	this->turno = otro.turno;
	this->puntoChequeo = otro.puntoChequeo;
	this->jugadores = new Vector<Jugador>(*otro.jugadores);
	this->tablero = new TableroIrregular(*dynamic_cast<TableroIrregular*>(otro.tablero));
}

Juego& Juego::operator=(const Juego& otro)
{
	if (this == &otro) return *this; 
	delete this->jugadores;
	delete this->tablero;
	this->turno = otro.turno;
	this->puntoChequeo = otro.puntoChequeo;
	this->jugadores = new Vector<Jugador>(*otro.jugadores);
	this->tablero = new TableroIrregular(*dynamic_cast<TableroIrregular*>(otro.tablero));
	return *this;
}

Tablero* Juego::getTablero()
{
	return tablero;
}

void Juego::guardarPartida(string nombreArchivo) {
	ofstream archivo(nombreArchivo + ".txt", ios::app);

	if (!archivo.is_open()) {
		cout<<"Error al abrir el archivo"<<endl;
		return;
	}
	
	archivo << "===============================================" << endl;
	archivo << "Punto de chequeo: " << puntoChequeo << endl;
	archivo << "Jugador " << (*jugadores)[0].getLetra() << ": " << tablero->puntuacion((*jugadores)[0].getLetra()) << " puntos\n";
	archivo<< "Jugador " << (*jugadores)[1].getLetra() << ": " << tablero->puntuacion((*jugadores)[1].getLetra()) << " puntos\n";
	archivo<< "\nTurno de: " << (*jugadores)[turno].getLetra() << endl;
	archivo << tablero->toString();
	archivo << "===============================================" << endl;
	archivo.close();
}