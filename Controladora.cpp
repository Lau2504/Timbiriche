#include "Controladora.h"

Controladora::Controladora()
{
}

Controladora::~Controladora()
{
}

void Controladora::control0()
{
    int opc, fi=0, col=0, est;
	char per1, per2, comp;
	Juego* juego = nullptr;
	Persona* persona1 = nullptr;
	Persona* persona2 = nullptr;
	Computadora* compu = nullptr;
	Tablero* tab = nullptr;
    Estrategia* estra = nullptr;
	do {
		try {
            system("cls");
			tab = this->crearTablero();
            system("pause");
            system("cls");
            opc = Interfaz::menuInicio();
            system("cls");
			per1 = Interfaz::inicio();

			switch (opc)
			{
			case 1: // 2 jugadores    
            {
                per2 = Interfaz::otroJugador();
                juego = new Juego(persona1 = new Persona(per1), persona2 = new Persona(per2));
                juego->iniciarJuego(tab);

                while (juego->sigueJuego()) {
                    cout << juego->dibujar();
                    fi = Interfaz::fila();
                    col = Interfaz::columna();
                    //try catch aqui para ver los problemas que surgen en hacer jugada (espacios reservados, jugados o errores de dimensiones/posicion)
                    juego->hacerJugada(col, fi);
                   
                    /* system("cls");*/
                }
                cout << "El ganador es: " << juego->ganador() << endl;
                break;
            }
			case 2: //jugar contra la computadora //Corregir esto porque se vuelve loco
            {
                estra = this->decidirEstrategia();
                compu = new Computadora(estra);
                juego = new Juego(persona1 = new Persona(per1), compu);
                juego->iniciarJuego(tab);
                Interfaz::mostrarTablero(tab);
                while (juego->sigueJuego()) {
                    if (juego->getTurno()) {
                        est = Interfaz::cambiarEstrategia();
                        if (est == 1) {
                            estra = this->decidirEstrategia();
                            compu->setEstrategia(estra);
                        }

                        fi = Interfaz::fila();
                        col = Interfaz::columna();

                        juego->hacerJugada(fi, col);
                    }
                    else {
                        juego->setTurno(true);
                        juego->hacerJugada(fi, col);
                    }
                    cout << juego->dibujar();
                    /* system("cls");*/
                }
                cout << "El ganador es: " << juego->ganador() << endl;
                break;
            }
			default:
				break;
			}
		}
		catch (Excepcion& e) {
            cout << e.que() << endl;
            system("pause");
		}
    } while (opc != 1 || opc != 2);
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
