#include <iostream>
#include "menu.h"

using namespace std;

const string PELIS_VISTAS = "peliculas_vistas.txt";
const string PELIS_NO_VISTAS = "peliculas_no_vistas.txt";
int main()
{
    //-------aca seria con tipo de dato pelicula en vez de string------
    Lista<string>* ptrPelisVistas;
    Lista<string>* ptrPelisNoVistas;
    ptrPelisVistas = new Lista<string>;
    ptrPelisNoVistas = new Lista<string>;
    Menu menu(ptrPelisVistas, ptrPelisNoVistas);
    //-----------------------------------------------------------------

    menu.inicializar(PELIS_VISTAS, PELIS_NO_VISTAS);

    cout << "Hello world!" << endl;

    delete ptrPelisVistas;
    delete ptrPelisNoVistas;
    return 0;
}
