#include "Juego.h"

Juego::Juego(Jugador* jug1, Jugador* jug2) :turno { false } {
	if (jug1 == nullptr or jug2 == nullptr)
		throw ExcepcionParametro();
	jugadores= new Vector<Jugador>(2);
	jugadores->agregarInicio(jug1);
	jugadores->agregarFinal(jug2);

}

Juego::~Juego() {
	if(jugadores)delete jugadores;
}

bool Juego::getTurno() { return turno; }

void Juego::iniciarJuego(Tablero* tab) {
	std::cout << "Iniciando Juego\n";
	turno = 0;
	TableroGlobal::getInstancia()->setTablero(tab);
}

void Juego::hacerJugada(int col, int fil) {
	if ((*jugadores)[turno].jugar(col,fil))//si retorna false, no hubo punto. por lo tanto, cambio de turno
		turno = !turno;
}

bool Juego::sigueJuego() {
	return !TableroGlobal::getInstancia()->getTablero()->estaLleno();
}

string Juego::dibujar() {
	TableroGlobal* ptr = TableroGlobal::getInstancia();
	Tablero* tab = ptr->getTablero();
	stringstream s;
	s << "Puntuacion\n";
	s << "Jugador " << (*jugadores)[0].getLetra() << ": " << tab->puntuacion((*jugadores)[0].getLetra()) << " puntos\n";
	s << "Jugador " << (*jugadores)[1].getLetra() << ": " << tab->puntuacion((*jugadores)[0].getLetra()) << " puntos\n";
	s << tab->toString();
	return s.str();
}