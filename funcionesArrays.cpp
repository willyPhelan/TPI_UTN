#include <iostream>
#include <string>
#include "funciones.h"

using namespace std ;

void mostrarDados(const int dados[], int cantidadDados) {

    for (int i = 0; i < cantidadDados; i++) {

        cout << dados[i] << " " ;
    }}

int agregarDadoAlArray(int dados[], int cantidadDados, int valor) {

    if (cantidadDados < 12) {

        dados[cantidadDados] = valor ;

        return cantidadDados + 1 ;

    } else {

        return cantidadDados ;
    }
}

int posicionNumeroEnVector(int v[],int tam, int numero){

    int i ;

    for (i = 0 ; i < tam ; i++){

        if(v[i] == numero) return i ; }

    return -1 ;
}



void copiarVector(int v[] , int v2[] , int tam){

    int i ;

    for( i = 0 ; i < tam ; i++){ v2[i] = v[i] ;
    }
}


bool _eliminarPrimerOcurrencia(int v[], int &cant, int valor) {

    int pos = posicionNumeroEnVector(v, cant, valor) ;

    if (pos != -1) {

        for (int i = pos ; i < cant - 1 ; i++) {

            v[i] = v[i + 1] ;
        }

        cant-- ;

        return true ;
    }

    return false ;
}



