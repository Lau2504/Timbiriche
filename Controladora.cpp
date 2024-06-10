#include "Controladora.h"

Controladora::Controladora()
{
}

Controladora::~Controladora()
{
}
void Controladora::control0()
{
    int op;
    Originador* originador = new Originador();
    Repositorio* repo = new Repositorio();

    do {
        try {
            op = Interfaz::menu();
            switch (op)
            {
            case 1:
                mostrarMementos(repo);
                break;
            case 2:
                iniciarNuevaPartida(originador, repo);
                break;
            case 3:
                op = 3;
                break;
            default:
                break;
            }
        }
        catch (Excepcion& e) {
            cout << e.que() << endl;
            system("pause");
        }
    } while (op != 3);

    delete originador;
    delete repo;
}


void Controladora::mostrarMementos(Repositorio* repo) {
    string partida;
    if (repo->getCan() != 0) {
        partida=Interfaz::mostrarHistorial(repo);
        system("cls");
        Interfaz::mostrarPartida(partida, repo);
        system("pause");   
    }
    else {
        Interfaz::noHayJugadas();
    }
}

void Controladora::iniciarNuevaPartida(Originador* originador, Repositorio* repo) {
    system("cls");
    Tablero* tab = crearTablero();
    system("pause");
    system("cls");
    int opc = Interfaz::menuInicio();
    if (opc == 3) return;

    system("cls");
    char per1 = Interfaz::inicio();
    Juego* juego = nullptr;

    switch (opc)
    {
    case 1:
        iniciarJuegoDosJugadores(juego, per1, originador, repo, tab);
        break;
    case 2:
        iniciarJuegoContraComputadora(juego, per1, originador, repo, tab);
        break;
    default:
        break;
    }
}

void Controladora::iniciarJuegoDosJugadores(Juego* juego, char per1, Originador* originador, Repositorio* repo, Tablero* tab) {
    char per2 = Interfaz::otroJugador();
    juego = new Juego(new Persona(per1), new Persona(per2));
    juego->iniciarJuego(tab);

    int contJugadas = 0;
    guardarMemento(juego, originador, repo, contJugadas);

    while (juego->sigueJuego()) {
        cout << juego->dibujar();
        int fi = Interfaz::fila();
        int col = Interfaz::columna();

        try {
            juego->hacerJugada(col, fi);
        }
        catch (Excepcion& e) {
            cout << e.que() << endl;
        }

        guardarMemento(juego, originador, repo, contJugadas);
    }

    Interfaz::ganador(juego);
}

void Controladora::iniciarJuegoContraComputadora(Juego* juego, char per1, Originador* originador, Repositorio* repo, Tablero* tab) {
    Estrategia* estra = decidirEstrategia();
    Computadora* compu = new Computadora(estra);
    juego = new Juego(new Persona(per1), compu);
    int fi = 0, col = 0;
    juego->iniciarJuego(tab);

    //Interfaz::mostrarTablero(tab);
    while (juego->sigueJuego()) {
        cout << endl << "---------------------------------------" << endl;
        cout << juego->dibujar();
        
        if (!juego->getTurno()) {/*
            int est = Interfaz::cambiarEstrategia();
            if (est == 1) {
                estra = decidirEstrategia();
                compu->setEstrategia(estra);
            }*/
           fi = Interfaz::fila();
           col = Interfaz::columna();
           juego->hacerJugada(col, fi);
        }
        else {
            //juego->setTurno(true);
            juego->hacerJugada(col, fi);
        }
        
    }

    cout << "El ganador es: " << juego->ganador() << endl;
}

void Controladora::guardarMemento(Juego* juego, Originador* originador, Repositorio* repo, int& contJugadas) {
    juego->setPuntoChequeo(contJugadas++);
    originador->setEstado(juego);
    repo->agregaMemento(originador->retornarMemento());
}

Tablero* Controladora::crearTablero()
{
    int op = Interfaz::tablero();
    int cant, t, n =0;
    TableroIrregular* tab = new TableroIrregular();
    TableroGlobal::getInstancia()->setTablero(tab);
    Tablero* tab3x = nullptr;
    srand(time(0));

    if (op == 1) {
        cant = Interfaz::cuantosTableros();
       }
    else {
        cant = rand() % 4 + 1;
    }
    
    while (n++ != cant) {
        t = rand() % 3 + 1; 
        switch (t) {
        case 1:
            tab3x = new Tablero3x3();
            break;
        case 2:
            tab3x = new Tablero3x4();
            break;
        case 3:
            tab3x = new Tablero3x5();
            break;
        default:
            tab3x = nullptr;
            break;
        }
        if (tab3x) {
            tab->agregarTablero(tab3x);
        }
    }
    Interfaz::mostrarTablero(tab);
    return tab;  
}

Estrategia* Controladora::decidirEstrategia()
{
    Estrategia* estra = nullptr;
    int est = Interfaz::escogerEstrategia();
    switch (est)
    {
    case 1: estra = new EstrategiaAleatoria(); break;
    case 2: estra = new EstrategiaCentral(); break;
    case 3: estra = new EstrategiaPeriferica(); break;
    case 4: estra = new EstrategiaIsla(); break;
    case 5: estra = new EstrategiaCercana(); break;
    default: break;
    }
  return estra;
}
