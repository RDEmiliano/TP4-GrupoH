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
    // Constructor de la clase Pelicula.
    //PRE: Ninguna
    //POST: Se crea un objeto de Clase Pelicula con los atributos incializados. Los atributos nombre,género y director se incializan como
    //      string vacío (""). El atributo puntaje en 0.0 y se solicita memoria dinámica para la lista del atributo actores.
    Pelicula();
    ~Pelicula();
    
    //PRE: Ninguna
    //POST: Se asigna el valor ingresado por parámetro, nombre, al atributo nombre de la clase.
    void asignarNombre(string nombre);

    //PRE: Ninguna
    //POST: Se asigna el valor ingresado por parámetro, genero, al atributo genero de la clase.
    void asignarGenero(string genero);

    //PRE: Ninguna
    //POST: Se asigna el valor ingresado por parámetro, puntaje, al atributo puntaje de la clase.
    void asignarPuntaje(string puntaje);

    //PRE: Ninguna
    //POST: Se carga la lista del atributo actores en base a la cadena actores recibida por parámetro.
    void asignarActores (string actores);

    //PRE: Ninguna
    //POST: Se asigna el valor ingresado por parámetro, director, al atributo director de la clase.
    void asignarDirector(string director);

    //PRE: Tiene que existir la lista de actores.
    //POST: Se devueve el contenido de la lista actores en la posicion de tipo entero ingresada por parámetro.
    string obtenerActorEn(int posicion);

    //PRE: Debe estar creado el objeto Pelicula
    //POST: Se devueve el valor del atributo nombre de la clase.
    string obtenerNombre();

    //PRE: Debe estar creado el objeto Pelicula
    //POST: Se devueve el valor del atributo genero de la clase.
    string obtenerGenero();

    //PRE: Debe estar creado el objeto Pelicula
    //POST: Se devueve el valor del atributo director de la clase.
    string obtenerDirector();

    //PRE: Debe estar creado el objeto Pelicula
    //POST: Se devueve el valor double del atributo puntaje de la clase.
    double obtenerPuntaje();

    //PRE: Debe estar creado el objeto Pelicula
    //POST: Se devueve el puntero a la lista de actores del atributo actores de la clase.
    Lista<string> * obtenerListaActores();

    //PRE: Debe estar creado el objeto Pelicula
    //POST: Se devueve el tamaño de la lista de actores del atributo actores de la clase.
    int obtenerCantActores();

    //PRE: Debe existir la lista de actores.
    //POST: Muestra por pantalla el listado de actores contenido en el atributo actores de la clase.
    void mostrarActores();

};



#endif //TP4_GRUPOH_PELICULA_H
