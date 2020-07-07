#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include "Lista.h"
#include "Pelicula.h"

const bool MOSTRAR = true;
const int PUNTAJE_MINIMO = 7;
using namespace std;

class Utilidades{
    //Metodos
    public:
        //PRE: Ninguna
        //POST: Constructor de la clase.
        Utilidades(); //Constructor
        ~Utilidades(); //Destructor
        void limpiarPantalla();
        void menuPrincipal();
        void despedida();
        void subrayar();
        void pausa();
        void cabecera();
        void mostrarListadoPeliculas(Lista<Pelicula*>* aMostrar);
        void enmarcar(Pelicula*);
        //PRE: Ninguna
        //POST: Se carga la lista apuntada por el puntero listAllenar en base al archivo txt cuyo nombre o direccion ingresa por
        //      el parámetro nombreArchivo, en el caso de que este sea válido.
        void llenarLista(Lista<Pelicula*>* listaAllenar, string nombreArchivo);

        //PRE: Ninguna
        //POST: Verifica si los atributos genero de los objetos de clase Pelicula apuntados por los parametros ingresados son iguales
        //      en cuyo caso devuelve true, sino false en caso contrario.
        bool coincideGenero(Pelicula* noVista, Pelicula* vista);

        //PRE: Ninguna
        //POST: Verifica si los atributos director de los objetos de clase Pelicula apuntados por los parametros ingresados son iguales
        //      en cuyo caso devuelve true, sino false en caso contrario.
        bool coincideDirector(Pelicula* noVista, Pelicula* vista);

        //PRE: Ninguna
        //POST: Devuelve TRUE en caso de que el atributo puntaje del objeto clase Pelicula apuntado por el parámetro ingresado sea
        //      mayor o igual a la constante PUNTAJE_MINIMO. Devuelve FALSE en caso contrario.
        bool tienePuntajeAdecuado(Pelicula* pelicula);

        //PRE: Deben existir dos listas de punteros a clase Pelicula.
        //POST: Devuelve TRUE si por lo menos un actor perteneciente al atributo actores del objeto Pelicula apuntado por noVista,
        //      tambien se encuentra en el atributo actores del objeto Pelicula apuntado por vista. Devuelve FALSE en caso contrario.
        bool coincideAlMenosUnActor(Pelicula* noVista, Pelicula* vista);

        //PRE: Debe existir la lista apuntada por el parámetro pelisRecomendadas.
        //POST: Inserta el parámetro pelicula a la lista apuntada por pelisRecomendadas.
        void agregarRecomendada(Lista<Pelicula*>* pelisRecomendadas, Pelicula * pelicula);

};


#endif // UTILIDADES_H_INCLUDED
