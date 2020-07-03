#include <iostream>
#include "menu.h"

using namespace std;

const string PELIS_VISTAS = "peliculas_vistas.txt";
const string PELIS_NO_VISTAS = "peliculas_no_vistas.txt";
int main()
{
    Lista<Pelicula*>* ptrPelisVistas;
    Lista<Pelicula*>* ptrPelisNoVistas;
    Lista<Pelicula*>* ptrPelisRecomendadas;
    ptrPelisVistas = new Lista<Pelicula*>;
    ptrPelisNoVistas = new Lista<Pelicula*>;
    ptrPelisRecomendadas = new Lista<Pelicula*>;

    Menu menu(ptrPelisVistas, ptrPelisNoVistas, ptrPelisRecomendadas);
    menu.inicializar(PELIS_VISTAS, PELIS_NO_VISTAS);    //Esto esta en menu

    int eleccion = 0;
    do{
        eleccion = menu.comenzar();
    }while(eleccion);

    return 0;
}
