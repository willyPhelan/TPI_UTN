#include <iostream>
#include <string>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"

using namespace std ;

int main() {

    srand(time(0)) ;

    int opcion ;
    int maximoPuntaje = 0 ;
    int mayorPuntaje = 0 ;

    string nombreGanadorUltimaPartida = "" ;
    string nombreGanadorHistorico = "" ;

    mostrarCartelEnfrendados() ;

    rlutil::resetColor();

    do {

        system("cls") ;

        opcion = seleccionarOpcion() ;

        if (opcion == 0) {

            system("cls") ;

            cout << "El juego ha finalizado. Hasta la proxima!" << endl ;

            break ;
        }

          ejecutarOpcion(opcion, maximoPuntaje, mayorPuntaje, nombreGanadorUltimaPartida, nombreGanadorHistorico) ;

          int volverMenu = volver_atras() ;

        if (volverMenu == 0) {

            break ;
        }

    } while (true) ;

    return 0 ;
}
