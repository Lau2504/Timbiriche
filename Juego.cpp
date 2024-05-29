#include "Juego.h"

Juego::Juego(Jugador* jug1, Jugador* jug2) :turno { false } {
	if (jug1 == nullptr or jug2 == nullptr)
		throw ExcepcionParametro();
	jugadores->agregarInicio(jug1);
	jugadores->agregarFinal(jug2);

}

Juego::~Juego() {
	if(jugadores)delete jugadores;
}

void Juego::iniciarJuego(Tablero* tab) {
	std::cout << "Iniciando Juego\n";
	turno = 0;
	TableroGlobal::getInstancia()->setTablero(tab);
}

void Juego::hacerJugada(int col, int fil) {
	TableroGlobal* ptr=TableroGlobal::getInstancia();
	Tablero* tab=ptr->getTablero();
	tab->agregarJugada(col, fil);
	if (tab->validarPunto((jugadores[turno]).getLetra(), col, fil))
		jugadores[3];
}