#include "funciones.h"
#include <iostream>
#include "rlutil.h"

using namespace std ;

#include "funciones.h"
#include <iostream>
// Ya no es necesario #include "rlutil.h" si no se usan funciones de rlutil en este archivo.

using namespace std ;

string determinarPrimerJugador(string jugador1, string jugador2) {

    int dado1, dado2 ;
    string primero_en_jugar ;

    system("cls"); // Limpia la pantalla

    rlutil::setBackgroundColor(rlutil::BLUE);

    cout << jugador1 << ", tira tu dado para ver quien comienza..." << endl << endl ;

    rlutil::setBackgroundColor(rlutil::BLACK) ;

    system("pause") ;

    dado1 = dado6caras() ;

    cout << endl << jugador1 << ", te salio el numero: " << endl;

    dibujarDado(dado1, 10, 6);

    cout << endl << endl ; // Añade saltos de línea para espacio

    system("pause") ;

    system("cls") ;

    rlutil::setBackgroundColor(rlutil::BLUE);

    cout << jugador2 << ", tira tu dado para ver quien comienza..." << endl << endl ;

    rlutil::setBackgroundColor(rlutil::BLACK) ;

    system("pause") ;

    dado2 = dado6caras() ;

    cout << endl << jugador2 << ", te salio el numero: " << endl << endl ;

    dibujarDado(dado2, 10, 6) ;

    cout << endl << endl ;

    system("pause") ;


    while (dado1 == dado2) {

        cout << endl << "Empate! Deben repetir la tirada inicial." << endl << endl ;

        system("pause") ;

        // Primer jugador repite tirada
        system("cls"); // Limpia para el mensaje de repetición del Jugador 1
        cout << jugador1 << ", te toca tirar de lanzar de nuevo." << endl ;

        system("pause") ;

        dado1 = dado6caras() ;
        system("cls"); // Limpia antes de mostrar nuevo dado
        cout << jugador1 << " te salio el numero: " << endl;
        dibujarDado(dado1, 10, 6);
        cout << endl << endl ;

        // Segundo jugador repite tirada
        cout << jugador2 << ", ahora te toca a vos tirar de lanzar de nuevo." << endl ;

        dibujarDado(dado1, 10, 6);

        system("pause") ;

        dado2 = dado6caras() ;
        system("cls"); // Limpia antes de mostrar nuevo dado
        cout << jugador2 << " te salio el numero: " << endl;
        dibujarDado(dado2, 10, 6);
        cout << endl << endl ;
    }

    system("cls"); // Limpia la pantalla para mostrar el resultado final
    cout << "----------------------------" << endl ;

    if (dado1 > dado2) {
        primero_en_jugar = jugador1 ;
        cout << jugador1 << " sacaste el dado mas alto, empiezas tu!" << endl ;
    } else {
        primero_en_jugar = jugador2 ;
        cout << jugador2 << " sacaste el dado mas alto, empiezas tu!" << endl ;
    }
    cout << "----------------------------" << endl ;
    system("pause"); // Pausa para que el usuario vea el resultado
    system("cls"); // Limpia antes de salir de la función
    return primero_en_jugar ;
}

bool procesarTurnoJugador(int stockActual[], int &cantActual, int stockOponente[], int &cantOponente,
                          int sumaObjetivo, int &puntosJugador, int stockMaximo,
                          string nombreJugadorActual, string nombreOponente) {

    int sumaSeleccionada = 0 ;

    int dadosElegidosValores[stockMaximo] ;

    int dadosElegidosCantidad = 0 ;

    bool tiradaExitosa = false ;

    int tempStock[stockMaximo] ;

    copiarVector(stockActual, tempStock, cantActual) ;

    int tempCant = cantActual ;

    mostrarDados(stockActual, cantActual) ;

    cout << endl ;

    rlutil::setBackgroundColor(rlutil::BLUE) ;

    cout << endl << "Ingresa los valores de los dados que deseas usar para sumar al objetivo (0 para terminar):" << endl << endl ;

    rlutil::setBackgroundColor(rlutil::BLACK) ;

    int dadoElegido ;

    while (true) {

        cout << "Suma actual: " << sumaSeleccionada << " / Objetivo: " << sumaObjetivo << endl ;

        cout << "Ingresa un dado para sumar (0 para terminar): " ;

        cin >> dadoElegido ;

        if (dadoElegido == 0) {

            rlutil::setBackgroundColor(rlutil::CYAN) ;

            cout  << endl << "Has decidido terminar tu turno con una suma de: " << sumaSeleccionada << " / Objetivo: " << sumaObjetivo << endl ;

            break ;
        }

        int pos = posicionNumeroEnVector(tempStock, tempCant, dadoElegido) ;

        if (pos != -1) {

            if (dadosElegidosCantidad < stockMaximo) {

                dadosElegidosValores[dadosElegidosCantidad] = dadoElegido ;

                sumaSeleccionada += dadoElegido ;

                _eliminarPrimerOcurrencia(tempStock, tempCant, dadoElegido) ;

                dadosElegidosCantidad++ ;

                cout << "Dado " << dadoElegido << " agregado. Suma actual: " << sumaSeleccionada << endl ;

                if (sumaSeleccionada == sumaObjetivo) {

                    tiradaExitosa = true ;

                    rlutil::setBackgroundColor(rlutil::GREEN) ;

                    cout << endl << "Alcanzaste el numero objetivo (" << sumaObjetivo << ") Tirada exitosa!" << endl ;

                    break ;
                }

                else if (sumaSeleccionada > sumaObjetivo) {

                    tiradaExitosa = false ;

                    rlutil::setBackgroundColor(rlutil::RED) ;

                    cout << endl << "Te pasaste del numero objetivo (" << sumaObjetivo << ") Tirada fallida!" << endl ;

                    break ;
                }

            } else {

                rlutil::setBackgroundColor(rlutil::RED) ;

                cout << endl << "Has seleccionado la cantidad maxima de dados. Finalizando seleccion." << endl ;

                break ;
            }

        } else {

            rlutil::setBackgroundColor(rlutil::RED) ;

            cout << endl << "No tenes el dado " << dadoElegido << " en tu stock o ya lo seleccionaste. Intenta de nuevo." << endl ;
        }
            cout << endl ;

    }

    system("pause") ;

    rlutil::setBackgroundColor(rlutil::BLACK) ;

    system("cls") ;

    cout << "--- FIN DE LA SELECCION DE DADOS ---" << endl ;
    cout << "Suma final de la seleccion: " << sumaSeleccionada << endl ;
    cout << "Numero objetivo: " << sumaObjetivo << endl << endl ;

    if (tiradaExitosa) {

        int puntosRondaActual = sumaSeleccionada * dadosElegidosCantidad ;

        puntosJugador += puntosRondaActual ;

        cout << endl << nombreJugadorActual << " suma " << puntosRondaActual << " puntos en esta ronda. Puntos totales de "<< nombreJugadorActual <<": " << puntosJugador << endl ;

        for (int i = 0 ; i < dadosElegidosCantidad ; i++) {

            int dadoAEnviar = dadosElegidosValores[i] ;

            _eliminarPrimerOcurrencia(stockActual, cantActual, dadoAEnviar) ;

            if (cantOponente < stockMaximo) {

                cantOponente = agregarDadoAlArray(stockOponente, cantOponente, dadoAEnviar) ;

            } else {

                cout << "Advertencia: El stock de " << nombreOponente << " esta lleno. El dado " << dadoAEnviar << " se pierde." << endl ;
            }
        }

         rlutil::setBackgroundColor(rlutil::GREEN) ;

        cout << "Se transfirieron " << dadosElegidosCantidad << " dados de " << nombreJugadorActual << " a " << nombreOponente << "." << endl ;


        rlutil::setBackgroundColor(rlutil::BLACK) ;

        if (cantActual <= 0) {

            rlutil::setBackgroundColor(rlutil::GREEN);

            puntosJugador += 10000 ;

            cout << endl << nombreJugadorActual << " se ha quedado sin dados y ha ganado la partida automaticamente!" << endl << endl ;

            return false ;
        }

    } else {

        if (sumaSeleccionada > sumaObjetivo) {

            cout << "LO SIENTO. Te pasaste del numero objetivo (" << sumaObjetivo << "). Tu suma fue " << sumaSeleccionada << "." << endl ;

        } else {

            rlutil::setBackgroundColor(rlutil::RED) ;

             cout << "No lograste una tirada exitosa. La suma seleccionada fue " << sumaSeleccionada << " pero el objetivo era " << sumaObjetivo << "." << endl ;
        }

        // Penalidad (transferencia de dado del oponente)

        if (cantOponente > 1) { // Oponente debe tener al menos 1 dado

            int dadoATransferir = obtenerDadoAleatorioDeStock(stockOponente, cantOponente) ; // Asumiendo que esta funcion existe

            if (dadoATransferir != -1) {

                if (_eliminarPrimerOcurrencia(stockOponente, cantOponente, dadoATransferir)) {

                    if (cantActual < stockMaximo) {

                        cantActual = agregarDadoAlArray(stockActual, cantActual, dadoATransferir) ;

                        cout << nombreOponente << " ha enviado un dado a " << nombreJugadorActual << " como penalidad." << endl ;

                        rlutil::setBackgroundColor(rlutil::BLACK) ;

                    } else {

                        cout << "Advertencia: El stock de " << nombreJugadorActual << " esta lleno. El dado " << dadoATransferir << " de penalidad se pierde." << endl ;

                    }
                }
            }

        } else {

            cout << "El oponente no tiene suficientes dados para penalizarte." << endl ;
        }
    }

    cout << endl ;

    system("pause") ;
    system("cls") ;

    return true ;
}
