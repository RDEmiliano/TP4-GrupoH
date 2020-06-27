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
}
void Menu::inicializar(string vistas, string noVistas){
    llenarLista(pelisVistas, vistas);
    llenarLista(pelisNoVistas, noVistas);
}
Menu::~Menu(){
    if (MOSTRAR){
        mostrarExtra("Destructor MENU", (int)this);
    }
}
