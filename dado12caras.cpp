#include <iostream>
#include <ctime>
#include "funciones.h"

using namespace std ;

int dado12caras(){

    int random ;

    random = rand() % 12 + 1 ;

    return random ; }


int tirarDadosObjetivo(string jugadorActual) {

    int primer_tiro, segundo_tiro ;

    cout << jugadorActual << ", momento de tirar los dados objetivo!" << endl << endl ;

    system("pause") ;

    primer_tiro = dado12caras() ;
    segundo_tiro = dado12caras() ;

    cout << endl << "Salieron los numeros: " << endl << primer_tiro << " " << segundo_tiro << endl << endl ;

    return primer_tiro + segundo_tiro ;
}
