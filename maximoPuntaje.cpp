#include <iostream>
#include "funciones.h"

using namespace std ;

void mejorJugador(int &puntosJ1, int &puntosJ2, string &jugador1, string &jugador2, string &nombreMayorPuntaje, int &mayorPuntaje){

if(puntosJ1 > puntosJ2){

    mayorPuntaje = puntosJ1 ;
    nombreMayorPuntaje = jugador1 ; }

    else {
            mayorPuntaje = puntosJ2 ;
            nombreMayorPuntaje = jugador2 ; }
}

void encontrarMaximoPuntaje(int &maximoPuntaje, int &mayorPuntaje, string &nombreMayorPuntaje, string &mejorMayor){

    if(mayorPuntaje > maximoPuntaje){

        maximoPuntaje = mayorPuntaje ;
        mejorMayor = nombreMayorPuntaje ;
    }

    if(maximoPuntaje > 0){

        cout << "El puntaje maximo registrado es " << maximoPuntaje << " del jugador " << mejorMayor << endl << endl ;

    } else {

        cout << "Todavia no se ha jugado ninguna partida." << endl << endl ;
    }
}
