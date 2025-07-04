#pragma once
#include <string>

using namespace std ;

int dado6caras() ;// fn en dado6caras.cpp

int dado12caras() ; // fn en  dado12caras.cpp

int volver_atras() ;// fn en volverAtras.cpp

int jugar(int &maximoPuntaje, int &mayorPuntaje, string &nombreGanadorUltimaPartida, string &nombreGanadorHistorico);// fn en jugar.cpp

void encontrarMaximoPuntaje(int &maximoPuntaje, int &mayorPuntaje, string &nombreGanadorUltimaPartida, string &nombreGanadorHistorico);// fn en maximoPuntaje.cpp

void mejorJugador(int &puntosJ1, int &puntosJ2, string &jugador1, string &jugador2, string &nombreGanadorUltimaPartida, int &puntajeGanadorUltimaPartida) ;// fn en maximoPuntaje.cpp

 // determino el objetivo a alcanzar:

void tirarDados6Caras(int dados[], int cantidadDados) ; // Rellena el array con dados de 6 caras // fn en dado6caras.cpp

void mostrarDados(const int dados[], int cantidadDados) ; // fn en funcionesArrays.cpp

// laburo fn arrays

int agregarDadoAlArray(int arr[], int cantidad, int valor) ; //  fn en funcionesArrays.cpp

void mostrarVector(int v[], int tam) ; // muestra lo que contiene cada una de las posiciones del vector // fn en funcionesArrays.cpp

int posicionNumeroEnVector(int v[],int tam, int numero) ;/// devuelve la posicion que ocupa un numero que se envia como parmetro. Devuelve la primera posicion en que encuentra el numero. Si no lo encuentra devuelve -1 // fn en funcionesArrays.cpp

void copiarVector(int v[], int v2[],int tam ) ; // copia el vector v en v2 // fn en funcionesArrays.cpp

bool _eliminarPrimerOcurrencia(int arr[], int &cant, int valor) ; // copia el vector v en v2 // fn en funcionesArrays.cpp

// Nuevas declaraciones de funciones

string determinarPrimerJugador(string jugador1, string jugador2) ; // fn en tirada.cpp

int tirarDadosObjetivo(string jugadorActual) ; // fn en dado12caras.cpp

bool procesarTurnoJugador(int stockActual[], int &cantActual, int stockOponente[], int &cantOponente,
                          int sumaObjetivo, int &puntosJugador, int stockMaximo,
                          string nombreJugadorActual, string nombreOponente) ; // fn en tirada.cpp

int obtenerDadoAleatorioDeStock(int arr[], int cant) ; // fn en dado6caras.cpp

void mostrarCartelEnfrendados() ; // fn en menu.cpp

int seleccionarOpcion() ; //fn en menu.cpp

void ejecutarOpcion(int opcion, int &maximoPuntaje, int &mayorPuntaje, string &nombreGanadorUltimaPartida, string &nombreGanadorHistorico) ; // fn en menu.cpp

void mostrarCreditos() ; // fn en menu.cpp

void mostrarEstadoJuego(int ronda, string &jugador1, int puntosJ1, int cantDadosJ1, string &jugador2, int puntosJ2, int cantDadosJ2) ; // FN en  mostrarEstadoJuego.cpp

void mostrarInfoTurno(int ronda, string &jugadorActual, int sumaObjetivo) ; // FN en  mostrarEstadoJuego.cpp
