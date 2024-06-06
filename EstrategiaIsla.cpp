#include "EstrategiaIsla.h"

EstrategiaIsla::EstrategiaIsla(){
	jugadas=nullptr;
	isla=TableroGlobal::getInstancia()->getTablero()->getCantidad()-1;
}

void EstrategiaIsla::arreglarJugadas() {
	if (jugadas != nullptr);
		delete jugadas;
	Tablero* tab = TableroGlobal::getInstancia()->getTablero();
	TableroIrregular* tabI = dynamic_cast<TableroIrregular*>(tab);
	if (tabI) {
		tab = ((tabI->getTableros()))[isla--];
	}
	//definir un punto de origen para la isla
	
	int Co = 0;
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(tab->getColumOrigen(), tab->getColumnas() + tab->getColumOrigen() - 2);
		Co = dis(gen);
		Co-=((Co%2));
	}
	int Fo = 0;
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(tab->getFilaOrigen(), tab->getFilas() + tab->getFilaOrigen() - 2);
		Fo = dis(gen);
		Fo -= ((Fo % 2));
	}
	//ahora buscamos una magnitud para el tamaño de la isla que no supere el tamaño de el tablero
	int Cm = 0;
	{
		//posibles jugadas totales
		//(tab->getColumnas()/2)
		//
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, ((Co-tab->getColumOrigen()))/2);
		Cm = dis(gen);
	}
	int Fm = 0;
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, ((Fo-tab->getFilaOrigen()))/2);
		Fm = dis(gen);
	}

	//sacamos el perimetro del rectangulo para saber la cantidad de posibles jugadas
	int perimetro = 2 * (Cm + Fm);
	jugadas = new Vector<int>(perimetro);
	//ahora llenamos el vector de jugadas
	for(int i=1;i<(Cm*2);i+=2){
		jugadas->agregarFinal(new int[2] {Co + i, Fo});
		jugadas->agregarFinal(new int[2] {Co + i, Fo+(Fm*2)});
	}
	for (int i = 1; i < (Fm * 2); i += 2) {
		jugadas->agregarFinal(new int[2] {Co, Fo + 1});
		jugadas->agregarFinal(new int[2] {Co + (Cm * 2), Fo + 1});
	}
}

int* EstrategiaIsla::ejecutarEstrategia(){
	if (isla == -1) {
		return nullptr;
	}
	if (jugadas == nullptr) {
		arreglarJugadas();
	}else if(jugadas->cantidad()==0){
		arreglarJugadas();
	}
	
	Tablero* tab=TableroGlobal::getInstancia()->getTablero();
	srand(time(0));
	int* par=jugadas->sacar(rand() % jugadas->cantidad());
	if (tab->getValor(par[1], par[0]) != ' ') {
		delete par;
		return ejecutarEstrategia();
	}
	
    return par;
}

EstrategiaIsla::~EstrategiaIsla(){
}
