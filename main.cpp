#include <iostream>
#include "menu.h"

using namespace std;

const string PELIS_VISTAS = "peliculas_vistas.txt";
const string PELIS_NO_VISTAS = "peliculas_no_vistas.txt";

int main()
{
    Menu menu;
    menu.inicializar(PELIS_VISTAS, PELIS_NO_VISTAS);

    int eleccion = 0;
    do{
        eleccion = menu.comenzar();
    }while(eleccion);

    return 0;
}
