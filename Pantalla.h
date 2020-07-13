#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Pelicula.h"

const int ANCHO_PANTALLA = 60;
const unsigned char SOMBRA = 219;//[176, 177, 178, 219]

class Pantalla{
    public:

        //PRE:  --
        //POST: Construye clase.
        Pantalla();

        //PRE:  --
        //POST: Destructor clase.
        ~Pantalla();

        //PRE:  --
        //POST: Borra lo impreso en pantalla. Cursor vuelve a posicion (1, 1).
        void limpiarPantalla();

        //PRE:  --
        //POST: Muestra opciones del programa.
        void menuPrincipal();

        //PRE:  --
        //POST: Muestra cartel de despedida.
        void despedida();

        //PRE:  --
        //POST: Pide al usuario pulsar tecla Enter para continuar.
        void pausa();

        //PRE:  --
        //POST: Cartel de presentacion.
        void cabecera();

        //PRE:  Enmarcar debe estar creada correctamente.
        //POST: Muestra los datos de la pelicula en un marco.
        void enmarcar(Pelicula* aEnmarcar);

        //PRE:  --
        //POST: Muestra texto en un marco.
        void enmarcar(string texto);

    private:

        //PRE:  --
        //POST: Parte superior del marco
        void marcoArriba();

        //PRE:  --
        //POST: Muestra linea centrada, y a los costados continuacion del marco.
        void marcoUnaLinea(string linea);

        //PRE:  --
        //POST: Crea una separacion en el marco.
        void marcoMedio();

        //PRE:  --
        //POST: Parte inferior del marco.
        void marcoAbajo();

        //PRE:  --
        //POST: Dentro del marco muestra texto1 y texto2, separados por una barra.
        //      Ambos textos centrados dentro de su recuadro.
        void marcoSeparacion(string texto1, string texto2);

        //PRE:  --
        //POST: Dentro del marco muestra texto1 y texto2, separados por espacios.
        void marcoSinSeparacion(string texto1, string texto2);

        //PRE:  --
        //POST: Devuelve el texto, si el texto tiene "_" reemplaza por " ".
        string quitarGuionBajo(string texto);
};

#endif // PANTALLA_H_INCLUDED
