//
// Created by emiliano on 26/6/20.
//

#include "Pelicula.h"

//Constructor
Pelicula::Pelicula() {

    //cantidadActores = 0;

}

//Destructor
Pelicula::~Pelicula() {
}

void Pelicula::asignarNombre(string nombre) {
    this -> nombre = nombre;
}

void Pelicula::asignarDirector(string director) {
    this -> director = director;
}

void Pelicula::asignarGenero(string genero) {
    this -> genero = genero;
}

void Pelicula::asignarPuntaje(double puntaje) {
    this -> puntaje = puntaje;
}

void Pelicula::nuevoActor(string actor, int posicion) {
    actores.insertar(actor, posicion);
    cantidadActores++;
}


int Pelicula::obtenerCantidadActores() {
    return cantidadActores;
}

string Pelicula::obtenerDirector() {
    return director;
}

string Pelicula::obtenerNombre() {
    return nombre;
}

double Pelicula::obtenerPuntaje() {
    return puntaje;
}

string Pelicula::obtenerGenero() {
    return genero
}