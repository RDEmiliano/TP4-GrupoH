#include "menu.h"
Menu::Menu(){
}
Menu::Menu(Lista<std::string>* vistas, Lista<std::string>* noVistas){
    pelisVistas = vistas;
    pelisNoVistas = noVistas;
}
Menu::~Menu(){
}
