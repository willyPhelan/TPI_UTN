#include <ctime>
#include "funciones.h"
#include <iostream>

using namespace std ;

int dado6caras(){

    int random ;

    random = rand() % 6 + 1 ;

    return random ; }


void tirarDados6Caras(int dados[], int cantidadDados) {

    for (int i = 0; i < cantidadDados; i++) {

        dados[i] = dado6caras() ;
    }
}


int obtenerDadoAleatorioDeStock(int dados[], int cantidadDados) {

    if (cantidadDados <= 0) {

        return -1 ;
    }

    int indiceAleatorio = rand() % cantidadDados ;

    return  dados[indiceAleatorio] ;
}


