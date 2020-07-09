#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#include<stdlib.h>
#include<iostream>

#include <sstream>
#include <iomanip>

#include "Pelicula.h"

const int ANCHO_PANTALLA = 50;
const char SOMBRA = 219;//[176, 177, 178, 219]

class Pantalla{
    public:

        Pantalla();
        ~Pantalla();
        void limpiarPantalla();
        void menuPrincipal();
        void despedida();
        void subrayar();
        void pausa();
        void cabecera();
        void enmarcar(Pelicula*);
        void enmarcar(string);

    private:

        void marcoArriba();
        void marcoUnaLinea(string linea);
        void marcoMedio();
        void marcoVacio();
        void marcoAbajo();
        void marcoSeparacion(string texto1, string texto2);
        void marcoSinSeparacion(string texto1, string texto2);
        string quitarGuionBajo(string texto);
};

#endif // PANTALLA_H_INCLUDED
