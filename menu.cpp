#include<iostream>
#include "funciones.h"

using namespace std ;


void mostrarCartelEnfrendados(){

cout << "    _______   ____________  _______   ______  ____   ____  ____  _____" << endl ;
cout << "   / ____/ | / / ____/ __ |/ ____/ | / / __ |/   |  / __ |/ __ |/ ___/" << endl ;
cout << "  / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / / /__ | " << endl ;
cout << " / /___/ /|  / __/ / __ _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /__/ /" << endl ;
cout << "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/|____/____/" << endl << endl ;

system("pause") ;
}

int seleccionarOpcion(){

    int opcion ;

    cout << "--- MENU PRINCIPAL ---" << endl ;
    cout << " 1 - JUGAR" << endl ;
    cout << " 2 - ESTADISTICAS" << endl ;
    cout << " 3 - CREDITOS" << endl ;
    cout << " 0 - SALIR" << endl ;
    cout << "---------------------" << endl ;

    cout << "Opcion: " ;
    cin >> opcion ;
    cout << endl ;

    while (opcion > 3 || opcion < 0){

        cout << "El numero ingresado no es correcto." << endl << "Ingrese otra opcion entre 1 y 3 o ingrese 0 para salir."  << endl << endl ;

        cout << "Opcion: " ;

        cin >> opcion ;
    }

    return opcion ;
}

void ejecutarOpcion (int opcion, int &maximoPuntaje, int &mayorPuntaje, string &nombreGanadorUltimaPartida, string &nombreGanadorHistorico){

    switch(opcion){

    case 1:

        system("cls") ;

        jugar(maximoPuntaje,mayorPuntaje,nombreGanadorUltimaPartida,nombreGanadorHistorico) ;

    break ;

    case 2:

        system("cls") ;

        encontrarMaximoPuntaje(maximoPuntaje,mayorPuntaje,nombreGanadorUltimaPartida,nombreGanadorHistorico) ;

    break ;

    case 3:

        system("cls") ;

        mostrarCreditos() ; // FN en menu.cpp

    break ;

    case 0:

    system("cls") ;

    cout << "El juego ha finalizado. Hasta la proxima!" << endl ;

    return ;

    }
}


/// OPCION 3 - CREDITOS

void mostrarCreditos(){

cout << "    ______ ____  __  __ ______ _____    _______" << endl ;
cout << "   / ____// __ |/ / / // __  // __  /  /__  __/" << endl ;
cout << "  / __  // /_/ / / / // /_/ // / / /     / /" << endl ;
cout << " / /_/ // __ _/ /_/ // ____// /_/ /   __/ /__" << endl ;
cout << "/_____//_/ |_/_____//_/    /_____/   /______/" << endl << endl ;

cout << endl ;
cout << "INTEGRANTES" << endl ;
cout << "===========" << endl << endl ;
cout << "| Guillermo Phelan - 33.407" << endl << endl ;
cout << "| Miguel Angel Chozza Baldassarri - 29.739" << endl << endl ;
cout << "| Rodrigo Nahuel Centurion - " << endl << endl ;
cout << "| Eliana Ayelen Martinez - 32.628 - " << endl << endl ;

cout << "PROFESORES" << endl ;
cout << "===========" << endl << endl ;
cout << "| Daniel Kloster" << endl << endl ;
cout << "| Brian Lara Campos" << endl << endl ;
cout << "| Veronica Carbonari" << endl << endl ;
cout << "| Tamara Vera" << endl << endl ;
cout << "| Maximiliano Sar Fernandez" << endl << endl ;
cout << "| Alejandro Gomez Nieto" << endl << endl ;
cout << "| Marina Chavez" << endl << endl ;
cout << "| Jose Alberto Rodriguez" << endl << endl ;

}


