#include <iostream>
#include <ctime>
#include <string>
#include "funciones.h"
#include "rlutil.h"

using namespace std ;

int jugar (int &maximoPuntaje, int &mayorPuntaje, string &nombreGanadorUltimaPartida, string &nombreGanadorHistorico){

    string jugador1, jugador2, primero_en_jugar, jugadorActual, oponente ;

    int suma_objetivo = 0 ;

    int puntosJ1=0, puntosJ2= 0 ;

    const int stock_maximo = 12 ;

    int stockJ1[stock_maximo] ;
    int stockJ2[stock_maximo] ;

    int cantDadosJ1 = 6 ;
    int cantDadosJ2 = 6 ;

    for (int i = 0; i < cantDadosJ1; ++i) {
        stockJ1[i] = dado6caras() ;
    }

    for (int i = 0; i < cantDadosJ2; ++i) {
        stockJ2[i] = dado6caras() ;
    }

    cout << "--- A jugar! ---------" << endl << endl ;

    cout << "Ingrese el nombre del Jugador 1: " ;
    cin >> jugador1 ;

    cout << "Ingrese el nombre del Jugador 2: " ;
    cin >> jugador2 ;

    cout << endl ;

    primero_en_jugar = determinarPrimerJugador(jugador1, jugador2) ;

    int ronda = 1 ;

    bool juegoContinua = true ;

    while (ronda <= 3 && juegoContinua) {

       mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2);

       cout << endl ;

        if (primero_en_jugar == jugador1) {

            jugadorActual = jugador1 ;

            oponente = jugador2 ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ;

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;

            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ;

            system("pause") ;

            cout << endl << "Salieron los dados: " ;

            tirarDados6Caras(stockJ1, cantDadosJ1) ;

            juegoContinua = procesarTurnoJugador(stockJ1, cantDadosJ1, stockJ2, cantDadosJ2, suma_objetivo, puntosJ1, stock_maximo, jugador1, jugador2) ;

            mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2) ;

            system("pause") ;
            system("cls") ;

            if (!juegoContinua) break ;

            jugadorActual = jugador2 ;
            oponente = jugador1 ;

            cout << "=== RONDA " << ronda << " ===" << endl ;
            cout << "Turno de " << jugadorActual << " ---" << endl ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ;

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;
            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ;

            system("pause") ;

            cout << endl << "Salieron los dados: " ;

            tirarDados6Caras(stockJ2, cantDadosJ2) ;

            juegoContinua = procesarTurnoJugador(stockJ2, cantDadosJ2, stockJ1, cantDadosJ1, suma_objetivo, puntosJ2, stock_maximo, jugador2, jugador1) ;

            mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2) ;

            system("pause") ;
            system("cls") ;


        } else {

            jugadorActual = jugador2 ;
            oponente = jugador1 ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ;

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;
            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ;

            system("pause") ;

            cout << endl << "Salieron los dados: " ;

            tirarDados6Caras(stockJ2, cantDadosJ2) ;

            juegoContinua = procesarTurnoJugador(stockJ2, cantDadosJ2, stockJ1, cantDadosJ1, suma_objetivo, puntosJ2, stock_maximo, jugador2, jugador1) ;

            mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2) ; // FN en  mostrarEstadoJuego.cpp

            system("pause") ;
            system("cls") ;


            if (!juegoContinua) break ;

            jugadorActual = jugador1 ;
            oponente = jugador2 ;

            cout << "=== RONDA " << ronda << " ===" << endl ;
            cout << "Turno de " << jugadorActual << " ---" << endl ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ;

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;
            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ;

            system("pause") ;

            cout << endl << "Salieron los dados: " ;

            tirarDados6Caras(stockJ1, cantDadosJ1) ;
            juegoContinua = procesarTurnoJugador(stockJ1, cantDadosJ1, stockJ2, cantDadosJ2, suma_objetivo, puntosJ1, stock_maximo, jugador1, jugador2) ;

        }

        if (!juegoContinua) break ;


        if (cantDadosJ1 <= 0) {

            cout << jugador2 << " ha ganado la partida. " << jugador1 << " se quedo sin dados." << endl ;

            juegoContinua = false ;
        }

        if (cantDadosJ2 <= 0) {

            cout << jugador1 << " ha ganado la partida. " << jugador2 << " se quedo sin dados." << endl ;

            juegoContinua = false ;
        }



        if (ronda < 3 && juegoContinua) {

            cout << endl << "Presiona cualquier tecla para comenzar la Ronda " << ronda + 1 << "..." << endl ;

            system("pause") ;
            system("cls") ;
        }

        ronda++ ;

    }

    if (ronda > 3 || !juegoContinua) {

        cout << "La partida ha terminado!" << endl << endl ;

        cout << jugador1 << " puntaje final: " << puntosJ1 << endl ;
        cout << jugador2 << " puntaje final: " << puntosJ2 << endl ;

        if (puntosJ1 > puntosJ2) {

            rlutil::setBackgroundColor(rlutil::GREEN);

            cout << endl << jugador1 << " ha ganado la partida!" << endl ;

        } else if (puntosJ2 > puntosJ1) {

            rlutil::setBackgroundColor(rlutil::GREEN);

            cout << endl << jugador2 << " ha ganado la partida!" << endl ;

        } else {

            rlutil::setBackgroundColor(rlutil::YELLOW) ;

            cout << endl << "La partida ha terminado en empate!" << endl << endl ;
        }

        mejorJugador(puntosJ1, puntosJ2, jugador1, jugador2, nombreGanadorUltimaPartida, mayorPuntaje);
    }

    return 0 ;
}




