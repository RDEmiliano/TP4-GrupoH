#include "menu.h"
Menu::Menu(){
    if (MOSTRAR){
        mostrarExtra("Constructor MENU <sin parametros>", (int)this);
    }
}
Menu::Menu(Lista<string>* vistas, Lista<string>* noVistas){
    if (MOSTRAR){
        mostrarExtra("Constructor MENU <con parametros>", (int)this);
    }
    pelisVistas = vistas;
    pelisNoVistas = noVistas;
    pelisRecomendadas = new Lista<string>; // como liberar memoria??
}
void Menu::inicializar(string vistas, string noVistas){
    llenarLista(pelisVistas, vistas);
    llenarLista(pelisNoVistas, noVistas);
    recomendar(pelisRecomendadas, pelisVistas, pelisNoVistas);
}
Menu::~Menu(){
    delete pelisRecomendadas;
    if (MOSTRAR){
        mostrarExtra("Destructor MENU", (int)this);
    }
}
