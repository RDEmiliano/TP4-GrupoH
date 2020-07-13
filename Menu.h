#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Lista.h"
#include "Pelicula.h"
#include "Utilidades.h"

using namespace std;

class Menu : public Utilidades{

private:
    bool arranque;
    Lista<Pelicula*>* pelisVistas;
    Lista<Pelicula*>* pelisNoVistas;
    Lista<Pelicula*>* pelisRecomendadas;

public:
    // Constructor sin par�metros de la clase Menu.
    //PRE: Ninguna
    //POST: Se crea un objeto de Clase Menu. Se solicita memoria din�mica para los tres atributos de la clase.
    Menu();

    //PRE: --
    //POST: Si existen ambos archivos se cargan a las listas, ademas carga lista de recomendados.
    //      Si solo existe archivo de peliculas no vistas, solo carga esa lista, ademas carga
    //      lista de recomendados.
    //      Si no existe archivo de peliculas no vistas, avisa por pantalla de que el archivo no existe.
    //      Y al no haber peliculas para poder recomendar termina la ejecucion de programa.
    void inicializar(string vistas, string noVistas);

    //PRE:  Listas correctamente cargadas.
    //POST: Inicio de interfaz con usuario.
    //      Se muestra una lista de opciones disponibles y se le pide que ingrese una.
    char comenzar();

    //PRE: Debe estar creado e inicializado el objeto de clase Menu.
    //POST: Muestra por pantalla el contenido de la lista peliculasVistas, detallando t�tulo, g�nero, puntaje, director y actores.
    //      Si la lista est� vac�a muestra un cartel comunicando que no hay nada que mostrar.
    void peliculasVistas();

    //PRE: Debe estar creado e inicializado el objeto de clase Menu.
    //POST: Muestra por pantalla el contenido de la lista peliculasNoVistas, detallando t�tulo, g�nero, puntaje, director y actores.
    //      Si la lista est� vac�a muestra un cartel comunicando que no hay nada que mostrar.
    void peliculasNoVistas();

    //PRE: Debe estar creado e inicializado el objeto de clase Menu.
    //POST: Muestra por pantalla el contenido de la lista peliculasRecomendadas, detallando t�tulo, g�nero, puntaje, director y actores.
    //      Si la lista est� vac�a muestra un cartel comunicando que no hay nada que mostrar.
    void peliculasRecomendadas();

    //PRE: Deben existir los archivo de texto "peliculas_vistas.txt" y "peliculas_no_vistas.txt".
    //POST: Se carga la lista pelisRecomendadas en base al archivo de peliculas vistas, tomando en cuenta las condiciones solicitadas.
    void recomendar();

    //PRE: Debe existir el archivo de texto "peliculas_no_vistas.txt".
    //POST: Se carga la lista pelisRecomendadas en base al archivo de peliculas no vistas, tomando en cuenta solamente el puntaje mayor
    //      al m�nimo aceptado (constante: PUNTAJE_MINIMO, heredada de la clase Utilidades).
    void recomendarSoloPuntaje();

    //PRE: -
    //POST: Retorna verdadero o falso si la apertura de archivos fue correcta
    bool obtenerArranque() const;

    //PRE: -
    //POST: Define un atributo booleano que se encarga del inicio del programa
    void definirArranque(bool estado);

    //PRE:  --
    //POST: Secuencia a seguir antes de finalizar el programa.
    void salir();

    //Destructor
    //PRE:  --
    //POST: Libera memoria pedida.
    //      Si se cargo la lista de peliculas vistas, primero libera memoria asignada a cada pelicula,
    //      luego libera memoria asignada la lista.
    //      Si se cargo la lista de peliculas NO vistas, primero libera memoria asignada a cada pelicula,
    //      luego libera memoria asignada la lista.
    //      Libera memoria asignada a la lista peliculas recomendadas.
    ~Menu();

};


#endif // MENU_H_INCLUDED
