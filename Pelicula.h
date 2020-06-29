//
// Created by emiliano on 26/6/20.
//

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
    Lista<string> actores;
    int cantidadActores;

    //Metodos
public:
    Pelicula();
    ~Pelicula();

    void asignarNombre(string nombre);
    void asignarGenero(string genero);
    void asignarPuntaje(double puntaje);
    void asignarDirector(string director);
    void nuevoActor(string actor, int posicion);

    string obtenerNombre();
    string obtenerGenero();
    string obtenerDirector();
    double obtenerPuntaje();
    int obtenerCantidadActores(); // Este metodo y el atributo 'cantidad de Actores' pueden ser opcionales
                                  // dependiendo de como se maneje el archivo.



};



#endif //TP4_GRUPOH_PELICULA_H
