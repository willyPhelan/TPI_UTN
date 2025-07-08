#include <iostream>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"

using namespace std ;

int dado12caras(){

    int random ;

    random = rand() % 12 + 1 ;

    return random ;
}

int tirarDadosObjetivo(string jugadorActual) {

    int primer_tiro, segundo_tiro ;

    rlutil::setBackgroundColor(rlutil::RED) ;

    cout << jugadorActual << ", momento de establecer tu objetivo!" << endl << endl ;

    rlutil::setBackgroundColor(rlutil::BLACK) ;

    system("pause") ;

    primer_tiro = dado12caras() ;
    segundo_tiro = dado12caras() ;

    cout << endl << "Salieron los numeros: " << endl << endl << primer_tiro << " " << segundo_tiro << endl << endl ;

    return primer_tiro + segundo_tiro ;
}
