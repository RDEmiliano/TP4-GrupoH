#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Lista.h"
#include "Pelicula.h"
#include "utilidades.h"
using namespace std;

class Menu : public Utilidades{

private:
    bool arranque;
    Lista<Pelicula*>* pelisVistas;
    Lista<Pelicula*>* pelisNoVistas;
    Lista<Pelicula*>* pelisRecomendadas;

public:
    // Constructor sin parámetros de la clase Menu.
    //PRE: Ninguna
    //POST: Se crea un objeto de Clase Menu. Se solicita memoria dinámica para los tres atributos de la clase.
    Menu();

    //PRE:  vistas y noVistas son los nombres (y ruta de acceso) de los archivos que contienen los datos
    //      con los cuales se llenaran las listas con que se trabajara en la clase.
    //POST: Si existen ambos archivos se cargan a las listas, ademas carga lista de recomendados.
    //      Si solo existe archivo de peliculas no vistas, solo carga esa lista, ademas carga
    //      lista de recomendados.
    //      Si no existe archivo de peliculas no vistas, avisa por pantalla de que el archivo no existe.
    //      Y al no haber peliculas para poder recomendar termina la ejecucion de programa.
    void inicializar(string vistas, string noVistas);

    //PRE:  Listas correctamente cargadas.
    //      Opcion elegida debe ser mayor que 0.
    //POST: Inicio de interfaz con usuario.
    //      Se muestra una lista de opciones disponibles y se le pide que ingrese una.
    int comenzar();

    //PRE: Debe estar creado e inicializado el objeto de clase Menu.
    //POST: Muestra por pantalla el contenido de la lista peliculasVistas, detallando título, género, puntaje, director y actores.
    //      Si la lista está vacía no muestra nada.
    void peliculasVistas();

    //PRE: Debe estar creado e inicializado el objeto de clase Menu.
    //POST: Muestra por pantalla el contenido de la lista peliculasNoVistas, detallando título, género, puntaje, director y actores.
    //      Si la lista está vacía no muestra nada.
    void peliculasNoVistas();

    //PRE: Debe estar creado e inicializado el objeto de clase Menu.
    //POST: Muestra por pantalla el contenido de la lista peliculasRecomendadas, detallando título, género, puntaje, director y actores.
    //      Si la lista está vacía no muestra nada.
    void peliculasRecomendadas();

    //PRE: Deben existir los archivo de texto "peliculas_vistas.txt" y "peliculas_no_vistas.txt".
    //POST: Se carga la lista pelisRecomendadas en base al archivo de peliculas vistas, tomando en cuenta las condiciones solicitadas.
    void recomendar(Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas);

    //PRE: Debe existir el archivo de texto "peliculas_no_vistas.txt".
    //POST: Se carga la lista pelisRecomendadas en base al archivo de peliculas no vistas, tomando en cuenta solamente el puntaje mayor
    //      al mínimo aceptado (constante: PUNTAJE_MINIMO, heredada de la clase Utilidades).
    void recomendar(Lista<Pelicula*>* noVistas);

    //void recomendar_version_con_listas_auxiliares();
    //void armarListitas(Lista<string>* ptrGeneros, Lista<string>* ptrDirectores, Lista<string>* ptrActores);
    //void llenarListita(Lista<string>* listita, string comparado);


    //PRE: -
    //POST: Retorna verdadero o falso si la apertura de archivos fue correcta
    bool obtenerArranque() const;

    //PRE: -
    //POST: Define un atributo booleano que se encarga del inicio del programa
    void definirArranque(bool estado);

    void salir();
    ~Menu();

};


#endif // MENU_H_INCLUDED
