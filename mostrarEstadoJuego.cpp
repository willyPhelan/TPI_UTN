#include <iostream>
#include <string>
#include "funciones.h"
#include "rlutil.h"


using namespace std ;

void mostrarEstadoJuego(int ronda, string &jugador1, int puntosJ1, int cantDadosJ1, string &jugador2, int puntosJ2, int cantDadosJ2) {

    rlutil::setBackgroundColor(rlutil::RED) ;
    cout << "Ronda: " << ronda << endl ;
    rlutil::setBackgroundColor(rlutil::BLACK) ;
    cout << "-------------------------------"  << endl ;
    cout << "-Estado Actual del Juego-" << endl ;
    cout << jugador1 << ": " << puntosJ1 << " puntos, " << cantDadosJ1 << " dados en stock." << endl ;
    cout << jugador2 << ": " << puntosJ2 << " puntos, " << cantDadosJ2 << " dados en stock." << endl ;
    cout << "-------------------------------" << endl << endl ;
}

void mostrarInfoTurno(int ronda, string &jugadorActual, int sumaObjetivo) {

    cout << "=== RONDA " << ronda << " ==="  << endl ;
    cout << "Turno de " << jugadorActual << endl ;
    cout << endl << "Numero objetivo: " << sumaObjetivo << endl ;
    cout << endl << jugadorActual << ", tira tus dados de 6 caras:" << endl << endl ;

}

