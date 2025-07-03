#include <iostream>
#include <string>
#include <ctime>
#include "funciones.h"

using namespace std ;

int main() {

    srand(time(0)) ;

    int opcion ;
    int maximoPuntaje = 0 ;
    int mayorPuntaje = 0 ;

    string nombreGanadorUltimaPartida = "" ;
    string nombreGanadorHistorico = "" ;

    mostrarCartelEnfrendados() ;  // FN en menu.cpp

    do {

        system("cls") ; // Borra la pantalla antes de mostrar el menu cada vez

        opcion = seleccionarOpcion() ; // FN en menu.cpp

        if (opcion == 0) {

            system("cls") ;

            cout << "El juego ha finalizado. Hasta la proxima!" << endl ;

            break ; // Salir del bucle
        }

          ejecutarOpcion(opcion, maximoPuntaje, mayorPuntaje, nombreGanadorUltimaPartida, nombreGanadorHistorico) ; // FN en menu.cpp

        // Despues de ejecutar una opcion, pregunta si el usuario quiere volver al menu o salir

          int volverMenu = volver_atras(opcion, maximoPuntaje, mayorPuntaje, nombreGanadorUltimaPartida, nombreGanadorHistorico) ; // FN en volverAtras.cpp

        if (volverMenu == 0) { // El usuario eligio salir

            break ;
        }

    } while (true) ; // Bucle indefinidamente hasta que el usuario elija salir

    return 0 ;
}
