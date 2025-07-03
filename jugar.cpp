#include <iostream>
#include <ctime>
#include <string>
#include "funciones.h"

using namespace std ;

int jugar (int &maximoPuntaje, int &mayorPuntaje, string &nombreGanadorUltimaPartida, string &nombreGanadorHistorico){

    string jugador1, jugador2, primero_en_jugar, jugadorActual, oponente ;

    int suma_objetivo = 0 ; // Se inicializa a 0, su valor cambia en el bucle

    int puntosJ1=0, puntosJ2= 0 ;

    const int stock_maximo = 12 ; // Maximo de dados por jugador (todos los dados del juego)

    int stockJ1[stock_maximo] ;
    int stockJ2[stock_maximo] ;

    int cantDadosJ1 = 6 ; // Cantidad inicial de dados para el Jugador 1
    int cantDadosJ2 = 6 ; // Cantidad inicial de dados para el Jugador 2


    // === INICIALIZACION DE DADOS AL INICIO DEL JUEGO ===
    // Rellenar los stocks iniciales de dados (6 para cada jugador)


    for (int i = 0; i < cantDadosJ1; ++i) {
        stockJ1[i] = dado6caras() ; // Usa la función que devuelve un int
    }

    for (int i = 0; i < cantDadosJ2; ++i) {
        stockJ2[i] = dado6caras() ; // Usa la función que devuelve un int
    }


    cout << "--- A jugar! ---------" << endl << endl ;


    cout << "Ingrese el nombre del Jugador 1: " ;
    cin >> jugador1 ;

    cout << "Ingrese el nombre del Jugador 2: " ;
    cin >> jugador2 ;

    cout << endl ;

    // Determino quien va primero

    primero_en_jugar = determinarPrimerJugador(jugador1, jugador2) ; // fn en tirada.cpp


    // =======================================================================
    // === BUCLE PRINCIPAL DEL JUEGO: RONDA POR RONDA ===
    // =======================================================================

    int ronda = 1 ;

    bool juegoContinua = true ; // bandera para controlar el fin del juego por victoria automática

    while (ronda <= 3 && juegoContinua) {

        // Mostrar estado actual de los jugadores al inicio de la ronda

       mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2); // FN en  mostrarEstadoJuego.cpp

       cout << endl ;

        // TURNO DEL JUGADOR QUE EMPIEZA LA RONDA

        if (primero_en_jugar == jugador1) {

            jugadorActual = jugador1 ;

            oponente = jugador2 ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ; // definida en dado12caras.cpp

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;

            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ;

            system("pause") ;

            cout << endl << "Salieron los dados: " ;

            tirarDados6Caras(stockJ1, cantDadosJ1) ; // J1 tira sus dados Funcion definda en dado6caras

            juegoContinua = procesarTurnoJugador(stockJ1, cantDadosJ1, stockJ2, cantDadosJ2, suma_objetivo, puntosJ1, stock_maximo, jugador1, jugador2) ; // Fn definida en tirada.cpp

            // Mostrar estado de los jugadores después del turno del primer jugador

            mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2); // FN en  mostrarEstadoJuego.cpp

            system("pause") ; // Pausa para que el usuario vea el estado actualizado
            system("cls") ; // Limpia la pantalla para el siguiente turno/ronda

            if (!juegoContinua) break ; // Si hay victoria automática, salir del bucle de rondas

            // TURNO DEL SEGUNDO JUGADOR EN LA MISMA RONDA

            jugadorActual = jugador2 ; // Ahora el jugador 2 es el actual
            oponente = jugador1 ;

            cout << "=== RONDA " << ronda << " ===" << endl ;
            cout << "Turno de " << jugadorActual << " ---" << endl ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ; // El segundo jugador también tira los dados objetivo // FN definida en dados12caras.cpp

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;
            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ; // FN en  mostrarEstadoJuego.cpp

            system("pause") ;

            cout << endl << "Salieron los dados: " ;
            tirarDados6Caras(stockJ2, cantDadosJ2) ; // J2 tira sus dados // FN definida en dado6caras.cpp

            juegoContinua = procesarTurnoJugador(stockJ2, cantDadosJ2, stockJ1, cantDadosJ1, suma_objetivo, puntosJ2, stock_maximo, jugador2, jugador1) ; // FN en tirada.cpp

            // Mostrar estado de los jugadores después del turno del segundo jugador

            mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2) ; // FN en  mostrarEstadoJuego.cpp

            system("pause") ; // Pausa para que el usuario vea el estado actualizado
            system("cls") ; // Limpia la pantalla para el siguiente turno/ronda


        } else { // Si primero_en_jugar == jugador2

            jugadorActual = jugador2 ;
            oponente = jugador1 ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ; // FN en dado12caras

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;
            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ; // FN en  mostrarEstadoJuego.cpp

            system("pause") ;

            cout << endl << "Salieron los dados: " ;

            tirarDados6Caras(stockJ2, cantDadosJ2) ; // J2 tira sus dados // fn en dado6Caras.cpp

            juegoContinua = procesarTurnoJugador(stockJ2, cantDadosJ2, stockJ1, cantDadosJ1, suma_objetivo, puntosJ2, stock_maximo, jugador2, jugador1) ; // fn definida en tirada.cpp

            // Mostrar estado de los jugadores después del turno del primer jugador

            mostrarEstadoJuego(ronda, jugador1, puntosJ1, cantDadosJ1, jugador2, puntosJ2, cantDadosJ2) ; // FN en  mostrarEstadoJuego.cpp

            system("pause") ; // Pausa para que el usuario vea el estado actualizado
            system("cls") ; // Limpia la pantalla para el siguiente turno/ronda


            if (!juegoContinua) break ; // Si hay victoria automática, salir del bucle de rondas

            // TURNO DEL SEGUNDO JUGADOR EN LA MISMA RONDA

            jugadorActual = jugador1 ; // Ahora el jugador 1 es el actual
            oponente = jugador2 ;

            cout << "=== RONDA " << ronda << " ===" << endl ;
            cout << "Turno de " << jugadorActual << " ---" << endl ;

            suma_objetivo = tirarDadosObjetivo(jugadorActual) ; // El segundo jugador también tira los dados objetivo // FN en dado12Caras

            cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;
            cout << endl << "Hora de alcanzarlo! " << endl << endl ;

            system("pause") ;
            system("cls") ;

            mostrarInfoTurno(ronda, jugadorActual, suma_objetivo) ; // FN en  mostrarEstadoJuego.cpp

            system("pause") ;

            cout << endl << "Salieron los dados: " ;
            tirarDados6Caras(stockJ1, cantDadosJ1) ; // J1 tira sus dados - FN definida en dado6caras.cpp
            juegoContinua = procesarTurnoJugador(stockJ1, cantDadosJ1, stockJ2, cantDadosJ2, suma_objetivo, puntosJ1, stock_maximo, jugador1, jugador2) ; // FN defindia en tirada.cpp

            // Mostrar estado de los jugadores después del turno del segundo jugado


        }

        if (!juegoContinua) break ; // Si el segundo jugador obtuvo una victoria automática, sale del bucle de rondas

        // FIN DE RONDA: Lógica para la próxima ronda y condiciones de victoria
        // La victoria automática por 0 dados tiene prioridad.

        if (cantDadosJ1 <= 0) {

            cout << jugador2 << " ha ganado la partida. " << jugador1 << " se quedo sin dados." << endl ;

            juegoContinua = false ; // Fin del juego
        }

        if (cantDadosJ2 <= 0) {

            cout << jugador1 << " ha ganado la partida. " << jugador2 << " se quedo sin dados." << endl ;

            juegoContinua = false ; // Fin del juego
        }

        // Si no hay condicion de victoria y no se completaron las 3 rondas, el juego sigue

        if (ronda < 3 && juegoContinua) {

            cout << endl << "Presiona cualquier tecla para comenzar la Ronda " << ronda + 1 << "..." << endl ;

            system("pause") ;
            system("cls") ; // Limpia la pantalla para la siguiente ronda
        }

        ronda++ ; // Incrementar la ronda SÓLO después de que ambos jugadores hayan jugado

    }

    // FIN BUCLE PRINCIPAL DEL JUEGO

    // Logica final del juego, determinar ganador por puntos si las 3 rondas terminan

    if (ronda > 3 || !juegoContinua) { // Si el bucle terminó porque se completaron las 3 rondas o hubo victoria automática

        cout << "La partida ha terminado!" << endl << endl ;

        cout << jugador1 << " puntaje final: " << puntosJ1 << endl ;
        cout << jugador2 << " puntaje final: " << puntosJ2 << endl ;

        if (puntosJ1 > puntosJ2) {

            cout << endl << jugador1 << " ha ganado la partida!" << endl ;

        } else if (puntosJ2 > puntosJ1) {

            cout << endl << jugador2 << " ha ganado la partida!" << endl ;

        } else {

            cout << endl << "La partida ha terminado en empate!" << endl << endl ;
        }

        mejorJugador(puntosJ1, puntosJ2, jugador1, jugador2, nombreGanadorUltimaPartida, mayorPuntaje); // FN en maximoPuntaje.cpp
    }

    return 0 ; // juego termina
}




