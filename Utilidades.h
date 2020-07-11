#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <fstream>
#include "Pantalla.h"
#include "Lista.h"
#include "Pelicula.h"

const int PUNTAJE_MINIMO = 7;
using namespace std;

class Utilidades : public Pantalla{
    //Metodos
    public:
        //PRE: Ninguna
        //POST: Constructor de la clase.
        Utilidades();

        //PRE:  --
        //POST: Destructor de la clase
        ~Utilidades();

        //PRE: --
        //POST: Si hay peliculas dentro de la lista, las muestra con formato, indicando nombre de la pelicula,
        //      director, genero, puntuacion y actores.
        //      Si la lista esta vacia, muestra un cartel dando aviso del suceso.
        void mostrarListadoPeliculas(Lista<Pelicula*>* aMostrar);

        //PRE:  El archivo txt debe finalizar con el ultimo caracter del ultimo nombre de actor, sin una linea vac�a a continuaci�n.
        //POST: Se carga la lista apuntada por el puntero listAllenar en base al archivo txt cuyo nombre o direccion ingresa por
        //      el par�metro nombreArchivo, en el caso de que este sea v�lido.
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
        //POST: Devuelve TRUE en caso de que el atributo puntaje del objeto clase Pelicula apuntado por el par�metro ingresado sea
        //      mayor o igual a la constante PUNTAJE_MINIMO. Devuelve FALSE en caso contrario.
        bool tienePuntajeAdecuado(Pelicula* pelicula);

        //PRE: Deben existir dos listas de punteros a clase Pelicula.
        //POST: Devuelve TRUE si por lo menos un actor perteneciente al atributo actores del objeto Pelicula apuntado por noVista,
        //      tambien se encuentra en el atributo actores del objeto Pelicula apuntado por vista. Devuelve FALSE en caso contrario.
        bool coincideAlMenosUnActor(Pelicula* noVista, Pelicula* vista);

};


#endif // UTILIDADES_H_INCLUDED
