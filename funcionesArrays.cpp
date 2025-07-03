#include <iostream>
#include <string>
#include "funciones.h"

using namespace std ;

// Función para mostrar los valores de un array de dados

void mostrarDados(const int dados[], int cantidadDados) {

    for (int i = 0; i < cantidadDados; i++) {

        cout << dados[i] << " " ;
    }}


// Función que agrega un valor a un array y retornar la nueva cantidad

int agregarDadoAlArray(int dados[], int cantidadDados, int valor) {

    if (cantidadDados < 12) { //  maxStock de 12 //  crucial para evitar un desbordamiento de búfer (buffer overflow)

        dados[cantidadDados] = valor ;

        return cantidadDados + 1 ; // Retorna la nueva cantidad

    } else {

        // cout << "Advertencia: Stock de dados lleno, no se puede agregar mas." << endl;

        return cantidadDados ; // La cantidad no cambia si no se pudo agregar
    }
}

int posicionNumeroEnVector(int v[],int tam, int numero){

    int i ;

    for (i = 0 ; i < tam ; i++){

        if(v[i] == numero) return i ; }

    return -1 ;
}



void copiarVector(int v[] , int v2[] , int tam){ //copia el vector v en v2

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



