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
    try {
        do {

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

        } while (op != 3);
    }
    catch (Excepcion& e) {
        cout << e.que() << endl;
        system("pause");
    }
    delete originador;
    delete repo;
}


void Controladora::mostrarMementos(Repositorio* repo) {
    string NombrePartida;

    NombrePartida =Interfaz::mostrarHistorial(repo);
    system("cls");
    Interfaz::mostrarPartida(NombrePartida, repo);
    system("pause");   

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

    int contJugadas = 1;
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
    int fi = 0, col = 0, contJugadas=1;
    juego->iniciarJuego(tab);
    int est = 0, opi = 0;

    opi = Interfaz::jugarSiempreMismaEstrategia();
    while (juego->sigueJuego()) {
        cout << endl << "---------------------------------------" << endl;
        cout << juego->dibujar();

        try {

        
         if (!juego->getTurno()) {
             if (opi == 2) { // Si había decidido ir cambiando la estrategia
                 est = Interfaz::cambiarEstrategia(); //Consulta si quiere seguir con la misma o no

                if (est == 1) {
                    estra = decidirEstrategia();
                    compu->setEstrategia(estra);
                }
            //Falta agregar que quiera cambiar la estrategia
                fi = Interfaz::fila();
                col = Interfaz::columna();
                juego->hacerJugada(col, fi);
            }
            else {

                juego->hacerJugada(col, fi);
            }
            this->guardarMemento(juego, originador, repo, contJugadas);

        }
        catch (Excepcion& e) {
            cout<<e.que()<<endl;
        }
        catch (...) {
            cout<<"error desconocido"<<endl;
        }
    }
    Interfaz::ganador(juego);

    repo->guardarMementos();
    system("pause");
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
    Estrategia* estra = new EstrategiaAleatoria(); 
    int est = Interfaz::escogerEstrategia();
    switch (est)
    {
    case 1: estra = new EstrategiaAleatoria(); break;
    case 2: estra = new EstrategiaCentral(); break;
    case 3: estra = new EstrategiaPeriferica(); break;
    case 4: estra = new EstrategiaIsla(); break;
    case 5: estra = new EstrategiaCercana(); break;
    case 6: estra = new EstrategiaPropia(); break;
    default: break;
    }
  return estra;
}
