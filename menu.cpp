#include "menu.h"
Menu::Menu(){
    if (MOSTRAR){
        mostrarExtra("Constructor MENU <sin parametros>", (int)this);
    }
}
Menu::Menu(Lista<Pelicula>* vistas, Lista<Pelicula>* noVistas){
    if (MOSTRAR){
        mostrarExtra("Constructor MENU <con parametros>", (int)this);
    }
    pelisVistas = vistas;
    pelisNoVistas = noVistas;
    pelisRecomendadas = new Lista<Pelicula>; // como liberar memoria??
}
void Menu::inicializar(string vistas, string noVistas){
    llenarLista(pelisVistas, vistas);                           //metodo en utilidades
    llenarLista(pelisNoVistas, noVistas);                       //metodo en utilidades
    recomendar(pelisRecomendadas, pelisVistas, pelisNoVistas);  //metodo en utilidades
}
int Menu::comenzar(){
    int eleccion;
    do{
        //limpiarPantalla();
        cabecera();
        cout << "1- Lista peliculas vistas." << endl;
        cout << "2- Lista no peliculas vistas." << endl;
        cout << "3- Recomendaciones." << endl;
        cout << "0- Salir." << endl;
        cout << endl;
        cout << "Eleccion: ";
        cin >> eleccion;
    }while(eleccion < 0 || eleccion > 3);
    cin.get();
    switch (eleccion){
        case 0:
            cout << "Sale" << endl;
            pausa();
            break;
        case 1:
            cout << "Peliculas vistas" << endl;
            pausa();
            break;
        case 2:
            cout << "Peliculas no vistas" << endl;
            pausa();
            break;
        case 3:
            cout << "Recomendaciones" << endl;
            pausa();
            break;
        break;
    }
    return eleccion;
}
Menu::~Menu(){
    delete pelisRecomendadas;
    if (MOSTRAR){
        mostrarExtra("Destructor MENU", (int)this);
    }
}
