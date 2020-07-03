#ifndef TP4_GRUPOH_PELICULA_H
#define TP4_GRUPOH_PELICULA_H

#include "Lista.h"
#include "iostream"

using namespace std;

class Pelicula {

    //Atributos
private:
    string nombre;
    string genero;
    string director;
    double puntaje;

    Lista<string> * actores;

    //Metodos
public:
    Pelicula();
    ~Pelicula();

    void asignarNombre(string nombre);
    void asignarGenero(string genero);
    void asignarPuntaje(string puntaje);
    void asignarActores (string actores);
    void asignarDirector(string director);


    string obtenerActorEn(int posicion);
    string obtenerNombre();
    string obtenerGenero();
    string obtenerDirector();
    double obtenerPuntaje();
    Lista<string> * obtenerListaActores();
    int obtenerCantActores();


    void mostrarActores();

};



#endif //TP4_GRUPOH_PELICULA_H
