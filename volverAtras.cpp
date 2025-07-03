#include <iostream>
#include <ctime>
#include "funciones.h"

using namespace std ;

    int volver_atras(int opcion,int &maximoPuntaje,int &mayorPuntaje, string &mayorPuntajeJ1, string &mayorPuntajeJ2){

    int volver=-99999 ;

    cout << endl << "Ingrese 1 para volver al Menu o 0 para salir" << endl ;

    cin >> volver ;

    if(volver < 0 || volver > 1){

        cout << "EL numero Ingresado no es valido. Vuelva a intentarlo (1 para volver al Menu o 0 para salir)" ;

        cin >> volver ;
    }

    switch (volver){

        case 1:

            return 1 ;

        case 0:

            system("cls") ;

            cout << "Gracias por jugar!" << endl << endl ;

            return 0 ;
    }

    return volver ;
}
