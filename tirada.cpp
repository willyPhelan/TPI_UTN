#include "funciones.h"
#include <iostream>

using namespace std ;


// Nueva función genérica para la tirada inicial y determinar quién empieza


string determinarPrimerJugador(string jugador1, string jugador2) {

    int dado1, dado2 ;

    string primero_en_jugar ;

    cout << jugador1 << ", tira tu dado para ver quien comienza..." << endl ;

    system("pause") ;

    dado1 = dado6caras() ; // fn en dado6caras.cpp

    cout << endl << "Salio el dado numero: " << dado1 << endl << endl ;

    cout << jugador2 << ", tira tu dado para ver quien comienza..." << endl ;

    system("pause") ;

    dado2 = dado6caras() ; // // fn en dado6caras.cpp

    cout << endl << "Salio el dado numero: " << dado2 << endl << endl ;

    while (dado1 == dado2) {

        cout << "Empate! Deben repetir la tirada inicial." << endl ;

        cout << jugador1 << ", te toca tirar de lanzar de nuevo." << endl ;

        system("pause") ;

        dado1 = dado6caras() ; // fn en dado6caras.cpp

        cout << jugador1 << " te salio el numero: " << dado1 << endl << endl ;

        cout << jugador2 << ", ahora te toca a vos tirar de lanzar de nuevo." << endl ;

        system("pause") ;

        dado2 = dado6caras() ; // fn en dado6caras.cpp

        cout << jugador2 << " te salio el numero: " << dado2 << endl << endl ;
    }

    cout << "----------------------------" << endl ;

    if (dado1 > dado2) {

        primero_en_jugar = jugador1 ;

        cout << jugador1 << " sacaste el dado mas alto, vas primero!" << endl << endl ;

    } else {

        primero_en_jugar = jugador2 ;

        cout << jugador2 << ", sacaste el dado mas alto, vas primero!" << endl << endl ;
    }

    system("pause") ;
    system("cls") ;

    return primero_en_jugar ;
}


// NUEVA FUNCIÓN PARA PROCESAR LA SELECCIÓN DE DADOS, PUNTUACIÓN Y TRANSFERENCIA
// Retorna true si el juego continúa, false si hay una victoria automática


bool procesarTurnoJugador(int stockActual[], int &cantActual, int stockOponente[], int &cantOponente,
                          int sumaObjetivo, int &puntosJugador, int stockMaximo,
                          string nombreJugadorActual, string nombreOponente) {

    int sumaSeleccionada = 0 ;

    int dadosElegidosValores[stockMaximo] ; // Array C-style para almacenar los dados seleccionados temporalmente

    int dadosElegidosCantidad = 0 ;

    bool tiradaExitosa = false ; // Esta bandera ahora se usará INTERNAMENTE para decidir el resultado

    // Pedir al jugador que seleccione los dados

    int tempStock[stockMaximo] ; // Copia temporal del stock para validar y seleccionar sin modificar el original

    copiarVector(stockActual, tempStock, cantActual) ; // fn en funcionesArray.cpp

    int tempCant = cantActual ;

    cout << "Tus dados: " << endl ;

    mostrarDados(stockActual, cantActual) ; // fn en funcionesArray.cpp

    cout << endl ;

    cout << endl << "Ingresa los valores de los dados que deseas usar para sumar al objetivo (0 para terminar):" << endl << endl ;

    int dadoElegido ;

    // El cambio principal es que la condición del 'while' ahora permite un control más granular con 'break'

    while (true) {

        cout << "Suma actual: " << sumaSeleccionada << " / Objetivo: " << sumaObjetivo << endl ;

        cout << "Ingresa un dado para sumar (0 para terminar): " ;

        cin >> dadoElegido ;

        // Comprobar si la entrada fue un 0 (terminar turno)

        if (dadoElegido == 0) {

            cout  << endl << "Has decidido terminar tu turno con una suma de: " << sumaSeleccionada << " / Objetivo: " << sumaObjetivo << endl ;

            break ; // Salir del bucle de selección
        }

        // Valido que el dado elegido esté en el stock del jugador (en la copia del array)

        int pos = posicionNumeroEnVector(tempStock, tempCant, dadoElegido) ; // fn en funcionesArray.cpp

        if (pos != -1) { // lo que retorna posicionNumeroEnVector

            if (dadosElegidosCantidad < stockMaximo) { // Asegurarse de no desbordar el array de seleccionados

                dadosElegidosValores[dadosElegidosCantidad] = dadoElegido ;

                sumaSeleccionada += dadoElegido ;

                _eliminarPrimerOcurrencia(tempStock, tempCant, dadoElegido) ; // Eliminar de la copia temporal // FN en funcionesdeArrays.cpp

                dadosElegidosCantidad++ ;

                cout << "Dado " << dadoElegido << " agregado. Suma actual: " << sumaSeleccionada << endl ;

                // --- CONDICIONES DE CORTE AUTOMÁTICO Y DECLARACIÓN DE ÉXITO/FRACASO ---
                // Si la suma seleccionada es igual al objetivo, corte y éxito

                if (sumaSeleccionada == sumaObjetivo) {

                    tiradaExitosa = true ;

                    cout << endl << "Alcanzaste el numero objetivo (" << sumaObjetivo << ") Tirada exitosa!" << endl ;

                    break ; // Salir del bucle de selección inmediatamente
                }

                // Si la suma seleccionada supera el objetivo, corte y fracaso

                else if (sumaSeleccionada > sumaObjetivo) {

                    tiradaExitosa = false ; // Ya sería false, pero explícito

                    cout << endl << "Te pasaste del numero objetivo (" << sumaObjetivo << ") Tirada fallida!" << endl ;

                    break ; // Salir del bucle de selección inmediatamente
                }

                // Si ninguna condición de corte se cumple, el bucle continuará pidiendo más dados
            } else {

                cout << endl << "Has seleccionado la cantidad maxima de dados. Finalizando seleccion." << endl ;

                break ; // Salir del bucle de selección
            }

        } else {

            cout << endl << "No tenes el dado " << dadoElegido << " en tu stock o ya lo seleccionaste. Intenta de nuevo." << endl ;
        }
            cout << endl ; // Salto de línea para mejor legibilidad antes del próximo prompt si el bucle continúa

    }

    // --- FIN DEL BUCLE DE SELECCIÓN DE DADOS ---

    system("pause") ;
    system("cls") ;

    cout << "--- FIN DE LA SELECCION DE DADOS ---" << endl ;
    cout << "Suma final de la seleccion: " << sumaSeleccionada << endl ;
    cout << "Numero objetivo: " << sumaObjetivo << endl << endl ;


    // La lógica de éxito/fracaso y penalización/recompensa ahora se basa en 'tiradaExitosa'
    // y se ejecuta UNA SOLA VEZ después de que el bucle de selección termina.

    if (tiradaExitosa) { // Esta bandera ahora viene directamente del bucle de seleccion

        // Puntuacion ---------------------------------------------------

        int puntosRondaActual = sumaSeleccionada * dadosElegidosCantidad ;

        puntosJugador += puntosRondaActual ;

        cout << endl << nombreJugadorActual << " suma " << puntosRondaActual << " puntos en esta ronda. Puntos totales de "<< nombreJugadorActual <<": " << puntosJugador << endl ;

        // Transferencia de dados

        for (int i = 0 ; i < dadosElegidosCantidad ; i++) {

            int dadoAEnviar = dadosElegidosValores[i] ;

            _eliminarPrimerOcurrencia(stockActual, cantActual, dadoAEnviar) ; // Elimina del stock real

            if (cantOponente < stockMaximo) {

                cantOponente = agregarDadoAlArray(stockOponente, cantOponente, dadoAEnviar) ;

            } else {

                cout << "Advertencia: El stock de " << nombreOponente << " esta lleno. El dado " << dadoAEnviar << " se pierde." << endl ;
            }
        }

        cout << "Se transfirieron " << dadosElegidosCantidad << " dados de " << nombreJugadorActual << " a " << nombreOponente << "." << endl ;

        // Condicion de victoria automatica por quedarse sin dados

        if (cantActual <= 0) {

            puntosJugador += 10000 ; // Bono por victoria automática

            cout << endl << nombreJugadorActual << " se ha quedado sin dados y ha ganado la partida automaticamente!" << endl << endl ;

            return false ; // fin del juego
        }

    } else { // Si no fue tiradaExitosa (porque se pasó o terminó manualmente sin alcanzar)

        // Verificamos si se pasó del objetivo o si simplemente terminó sin alcanzarlo

        if (sumaSeleccionada > sumaObjetivo) {

            cout << "LO SIENTO. Te pasaste del numero objetivo (" << sumaObjetivo << "). Tu suma fue " << sumaSeleccionada << "." << endl ;

        } else {

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

    return true ; // Juego continua
}
