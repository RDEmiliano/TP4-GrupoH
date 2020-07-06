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
        Utilidades(); //Constructor
        ~Utilidades(); //Destructor
        void limpiarPantalla();
        void menuPrincipal();
        void despedida();
        void subrayar();
        void pausa();
        void cabecera();

        void llenarLista(Lista<Pelicula*>* listaAllenar, string nombreArchivo);
        bool coincideGenero(Pelicula* noVista, Pelicula* vista);
        bool coincideDirector(Pelicula* noVista, Pelicula* vista);
        bool tienePuntajeAdecuado(Pelicula* pelicula);
        bool coincideAlMenosUnActor(Pelicula* noVista, Pelicula* vista);
        void agregarRecomendada(Lista<Pelicula*>* pelisRecomendadas, Pelicula * pelicula);

};


#endif // UTILIDADES_H_INCLUDED
