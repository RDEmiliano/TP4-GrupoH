
#include <sstream>
#include "Pelicula.h"

//Constructor
Pelicula::Pelicula() {

    if (MOSTRAR_MEMORIA) cout << "Constructor PELICULA (" << this << ")" << endl;
    nombre = "";
    genero = "";
    director = "";
    puntaje = 0.0;
    actores = new Lista<string>; //recibe puntero

}

//Destructor
Pelicula::~Pelicula() {
    delete actores; //AGREGUE
    if (MOSTRAR_MEMORIA) cout << "Destructor PELICULA (" << this << ")" << endl;
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
        actores -> insertar(tempStr,1);
    }
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

string Pelicula::obtenerActorEn(int posicion) {
    return actores -> obtenerDato(posicion);
}

Lista<string> * Pelicula::obtenerListaActores(){
    return actores;
}

int Pelicula::obtenerCantActores(){
    return (actores->obtenerTamanio());
}


void Pelicula::mostrarActores() {
    for (int i = 1; i < actores->obtenerTamanio()+1; i++){
        cout << actores -> obtenerDato(i) <<" - ";
    }
    cout << endl;
}


