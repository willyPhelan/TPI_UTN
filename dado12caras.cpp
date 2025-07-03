#include <iostream>
#include <ctime>
#include "funciones.h"

using namespace std ;

int dado12caras(){

    int random ;

    random = rand() % 12 + 1 ; // esto birndara numeros aleatoreos entre el 1 y el 12, originalmente  rand() % 12 retorna nums entre 0 y 11 - si quiero aumentar el rango uno mas hacia la derecha +1 y el rango sera de 1 a 12.

    return random ; }


// función para gestionar la tirada de dados objetivo (12 caras)

int tirarDadosObjetivo(string jugadorActual) {

    int primer_tiro, segundo_tiro ;

    cout << jugadorActual << ", momento de tirar los dados objetivo!" << endl << endl ;

    system("pause") ;

    primer_tiro = dado12caras() ; // Lanza el primer dado de 12 caras
    segundo_tiro = dado12caras() ; // Lanza el segundo dado de 12 caras

    cout << endl << "Salieron los numeros: " << endl << primer_tiro << " " << segundo_tiro << endl << endl ;

    return primer_tiro + segundo_tiro ;
}
