//
// Created by emiliano on 26/6/20.
//
#include <sstream>
#include "Pelicula.h"

//Constructor
Pelicula::Pelicula() {
    if (MOSTRAR_MEMORIA){
        std::cout << "Constructor PELICULA (" << (int)this << ")" << std::endl;
    }
    //cantidadActores = 0;

}

//Destructor
Pelicula::~Pelicula() {
    if (MOSTRAR_MEMORIA){
        std::cout << "Destructor PELICULA (" << (int)this << ")" << std::endl;
    }
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

void Pelicula::asignarPuntaje(string puntaje) {
    this-> puntaje = stof(puntaje);
}

void Pelicula::asignarActores (string cadenaDeActores){
    istringstream isstream(cadenaDeActores);
    string tempStr;
    while(!isstream.eof()){
       
        isstream >> tempStr;
       // this->actores.insertar(tempStr,1); // ACA TENDRIA QUE CARGAR LA LISTA DE ACTORES, PERO DA ERROR.
       
    }
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
    return genero;
}
