#include "EstrategiaCentral.h"

EstrategiaCentral::EstrategiaCentral() {
    Tablero* tablero = TableroGlobal::getInstancia()->getTablero();
    x = (tablero->getColumnas() / 2) ;
    y = (tablero->getFilas() / 2) ;  
    x += x % 2;
    y += y % 2;
}

int* EstrategiaCentral::ejecutarEstrategia(){
    //probar lados, guardar
    Tablero* tab=TableroGlobal::getInstancia()->getTablero();
    Vector<int> lados(4);//guarda los lados que se pueden mover, no la posicion x,y del punto donde se compara
    bool hayJugada = false;
    int X1=x, Y1=y;
    while (!hayJugada) {
        if(X1!=0)
            if (tab->getValor(Y1, X1 - 1) == ' ')
                lados.agregarFinal(new int[2] {X1-1, Y1});
        if (Y1!=0)
            if (tab->getValor(Y1+1, X1) == ' ')
                lados.agregarFinal(new int[2]{X1,Y1+1});
        if (Y1 != tab->getFilas() - 1)
            if (tab->getValor(Y1 - 1, X1) == ' ')
                lados.agregarFinal(new int[2] {X1, Y1-1});
        if (X1 != tab->getColumnas() - 1)
            if (tab->getValor(Y1, X1+1) == ' ')
                lados.agregarFinal(new int[2] {X1+1, Y1});
            
        if (lados.cantidad() > 0)
			hayJugada = true;
		else {
            Vector<int> posiblesPuntos(4);
            if (X1 + 2 < tab->getColumnas())
				posiblesPuntos.agregarFinal(new int[2]{X1 + 2, Y1});
            if (X1 - 2 >= 0)
                posiblesPuntos.agregarFinal(new int[2]{X1 - 2, Y1});
            if (Y1 + 2 < tab->getFilas())
                posiblesPuntos.agregarFinal(new int[2]{X1, Y1 + 2});
            if (Y1 - 2 >= 0)
                posiblesPuntos.agregarFinal(new int[2]{X1, Y1 - 2});
            int* punto = posiblesPuntos.sacar(rand() % posiblesPuntos.cantidad());
            X1 = punto[0];
            Y1 = punto[1];
            delete punto;
		}
	}
	
    srand(time(0));
    return lados.sacar(rand() % lados.cantidad());
}

EstrategiaCentral::~EstrategiaCentral(){
    
}
