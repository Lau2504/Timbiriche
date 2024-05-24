#pragma once
class Jugador{
private:
	char letra;
public:
	Jugador(char);
	~Jugador();
	void setLetra(char);
	char getLetra();
	void jugar();
};

