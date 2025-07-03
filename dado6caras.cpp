#include <ctime>
#include "funciones.h"
#include <iostream>

using namespace std ;

int dado6caras(){

    int random ;

    random = rand() % 6 + 1 ; // esto birndara numeros aleatoreos entre el 0 y el 5, si quiero que incluya el 6 le sumo 1.

    return random ; }


void tirarDados6Caras(int dados[], int cantidadDados) {

    for (int i = 0; i < cantidadDados; i++) {

        dados[i] = dado6caras() ; // Llama a la función dado6caras() para obtener el valor
    }
}

// Nueva función auxiliar para obtener un dado aleatorio del stock

int obtenerDadoAleatorioDeStock(int dados[], int cantidadDados) {

    if (cantidadDados <= 0) {

        return -1 ; // No hay dados en el stock
    }

    int indiceAleatorio = rand() % cantidadDados ;

    return  dados[indiceAleatorio] ;
}


