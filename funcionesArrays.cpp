#include <iostream>
#include <string>
#include "funciones.h"
#include "rlutil.h"

using namespace std ;


void dibujarDado(int numero, int posc, int posf) {

switch(numero){

    case 1:

            rlutil::locate(posc, posf);     cout << "+-------+";
            rlutil::locate(posc, posf + 1); cout << "|       |";
            rlutil::locate(posc, posf + 2); cout << "|   0   |";
            rlutil::locate(posc, posf + 3); cout << "|       |";
            rlutil::locate(posc, posf + 4); cout << "+-------+";
            break;

        case 2:
            rlutil::locate(posc, posf);     cout << "+-------+";
            rlutil::locate(posc, posf + 1); cout << "| 0     |";
            rlutil::locate(posc, posf + 2); cout << "|       |";
            rlutil::locate(posc, posf + 3); cout << "|     0 |";
            rlutil::locate(posc, posf + 4); cout << "+-------+";
            break;
        case 3:
            rlutil::locate(posc, posf);     cout << "+-------+";
            rlutil::locate(posc, posf + 1); cout << "| 0     |";
            rlutil::locate(posc, posf + 2); cout << "|   0   |";
            rlutil::locate(posc, posf + 3); cout << "|     0 |";
            rlutil::locate(posc, posf + 4); cout << "+-------+";
            break;

        case 4:
            rlutil::locate(posc, posf);     cout << "+-------+";
            rlutil::locate(posc, posf + 1); cout << "| 0   0 |";
            rlutil::locate(posc, posf + 2); cout << "|       |";
            rlutil::locate(posc, posf + 3); cout << "| 0   0 |";
            rlutil::locate(posc, posf + 4); cout << "+-------+";
            break;

        case 5:
            rlutil::locate(posc, posf);     cout << "+-------+";
            rlutil::locate(posc, posf + 1); cout << "| 0   0 |";
            rlutil::locate(posc, posf + 2); cout << "|   0   |";
            rlutil::locate(posc, posf + 3); cout << "| 0   0 |";
            rlutil::locate(posc, posf + 4); cout << "+-------+";
            break;

        case 6:

            rlutil::locate(posc, posf);     cout << "+-------+";
            rlutil::locate(posc, posf + 1); cout << "| 0   0 |";
            rlutil::locate(posc, posf + 2); cout << "| 0   0 |";
            rlutil::locate(posc, posf + 3); cout << "| 0   0 |";
            rlutil::locate(posc, posf + 4); cout << "+-------+";

            break;
    }
}

void mostrarDados(const int dados[], int cantidadDados) {

    int inicio_col = 5 ;
    int fila_dados = 15 ;
    int ancho_dado_con_espacio = 10; // Ancho del dado (8) + espacio entre dados (2)

    for (int i = 0; i < cantidadDados; i++) {
        // Calcula la posición para cada dado para que aparezcan uno al lado del otro
        dibujarDado(dados[i], inicio_col + (i * ancho_dado_con_espacio), fila_dados);
    }
    // Mueve el cursor a una posición debajo de los dados para que el texto subsiguiente
    // no los sobrescriba. El dado tiene 5 líneas de alto, así que 6 líneas debajo de 'fila_dados' es seguro.
    rlutil::locate(1, fila_dados + 6);
    cout << endl; // Asegura que cualquier 'cout' posterior empiece en una nueva línea
}

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



