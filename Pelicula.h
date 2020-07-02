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

    Lista<string> * actores;

    int cantidadActores;    // <- CREO QUE ESTO LO PODEMOS SACAR, Y USAMOS EL METODO DE LA
                            // LISTA ACTORES, EJEMPLO PARA SABER LA CANTIDAD DE ACTORES
                            // HACEMOS actores.obtenerTamanio()

    //Metodos
public:
    Pelicula();
    ~Pelicula();

    void asignarNombre(string nombre);
    void asignarGenero(string genero);
    void asignarPuntaje(string puntaje);
    void asignarActores (string actores);
    void asignarDirector(string director);


    string obtenerNombre();
    string obtenerGenero();
    string obtenerDirector();
    double obtenerPuntaje();
    void obtenerActores(); // Este metodo y el atributo 'cantidad de Actores' pueden ser opcionales
                                  // dependiendo de como se maneje el archivo.
                                  // Si ahi podemos poner que devuelva actores.obtenertamanio()
};



#endif //TP4_GRUPOH_PELICULA_H
