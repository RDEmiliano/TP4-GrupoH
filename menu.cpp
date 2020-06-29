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
Menu::~Menu(){
    delete pelisRecomendadas;
    if (MOSTRAR){
        mostrarExtra("Destructor MENU", (int)this);
    }
}
