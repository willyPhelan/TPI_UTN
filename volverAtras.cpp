#include <iostream>
#include <ctime>
#include "funciones.h"


using namespace std ;

    int volver_atras(int opcion,int &maximoPuntaje,int &mayorPuntaje, string &mayorPuntajeJ1, string &mayorPuntajeJ2){

    int volver=-99999 ;

    // Primera solicitud de entrada

    cout << endl << "Ingrese 1 para volver al Menu o 0 para salir" << endl ;

    cin >> volver ;

    // Validacion de la entrada. Solo si la primera entrada es invalida, se pedira de nuevo.

    if(volver < 0 || volver > 1){

        cout << "EL numero Ingresado no es valido. Vuelva a intentarlo (1 para volver al Menu o 0 para salir)" ;

        cin >> volver ; // Segunda solicitud si la primera fue invalida
    }

    // A partir de aqui, 'volver' ya tiene un valor valido (0 o 1)

    switch (volver){

        case 1:

            // No hacemos system("cls") ni seleccionarOpcion() aqui.
            // El 'main' se encargara de esto.

            return 1 ; // Indica a 'main' que debe volver al menu

        case 0:

            system("cls") ; // Limpia la pantalla antes de salir

            cout << "Gracias por jugar!" << endl << endl ;

            return 0 ; // Indica a 'main' que debe salir del juego
    }

    return volver ; // Esta linea es un 'fallback', normalmente no se alcanzaria
}
