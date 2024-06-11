#pragma once
#include"Memento.h"
#include <string>
class Repositorio {    // Repositorio de Mementos...
private:
	Memento* vec[128];
	int can;
	int tam;
public:
	Repositorio() {
		can = 0;
		tam = 128;
		for (int i = 0; i < tam; i++)
			vec[i] = nullptr;
	}

	virtual ~Repositorio() {}

	void agregaMemento(Memento* m) {
		if (can < tam) {
			vec[can++] = m;
			cout << "Memento agregado en la posición: " << (can - 1) << endl;
		}
		else {
			cout << "No se puede agregar más mementos, el repositorio está lleno." << endl;
		}
	}


	Memento* getMemento(int pos) {
		if (pos >= 0 && pos < can)
			return vec[pos];
		else
			return nullptr;
	}

	int getCan() { return can; }

	string toString() {
		stringstream s;
		s << "----Los mementos en orden cronologico que existen son:----" << endl;
		for (int i = 0; i < can; i++) {
			s << "No. " << i + 1 << "    Punto de Chequeo = "
				<< vec[i]->getPtrFoto()->getPuntoChequeo() << endl
				<< endl
				<< vec[i]->getPtrFoto()->getTablero()->toString() << endl << endl; //esta llamando al tablero global no al tablero del memento
		}
		return s.str();
	}

	void guardarMementos() {
	
		int nPartida = 1;
		string aux;
		system("dir /b *.txt 1> archivos.log 2>nul");
		ifstream archivo("archivos.log");
		if(!archivo.is_open()){
			cout<< "Error al abrir el archivo"<<endl;
			return;
		}

		while (getline(archivo, aux, '\n')) 
			nPartida++;
		archivo.close();

		for (int i = 0; i < can; i++) 
			vec[i]->getPtrFoto()->guardarPartida("partida" + to_string(nPartida));
		system("del archivos.log");
	}

	string listarPartidas() {
		system("dir /b *.txt 1> archivos.log 2>nul");
		ifstream archivo("archivos.log");
		string nombreArchivo;
		stringstream ss;
		if (!archivo.is_open()) {	
			cout << "Error al abrir el archivo" << endl;
			return "";
		}

		while (getline(archivo, nombreArchivo)) {
			nombreArchivo.erase(nombreArchivo.end() - 4, nombreArchivo.end());
			ss << nombreArchivo << std::endl;
		}
		archivo.close();
		
		system("del archivos.log");

		if (ss.str().empty()) {
			ss<<"No hay partidas guardadas"<<endl;
		}
		return ss.str();
	}

	string mostrarPartida(string nombreArchivo) {
		ifstream archivo(nombreArchivo + ".txt");
		stringstream ss;
		string aux;
		if (!archivo.is_open()) {
			cout << "Error al abrir el archivo" << endl;
			return "";
		}
		
		while(getline(archivo,aux))
			ss << aux << endl;

		archivo.close();
	
		return ss.str();
	}
};