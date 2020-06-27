#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<iostream>
#include "lista.h"
#include "utilidades.h"

class Menu : Utilidades{
private:
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Lista<std::string>* pelisVistas;
    Lista<std::string>* pelisNoVistas;
public:
    Menu();
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Menu(Lista<std::string>* vistas, Lista<std::string>* noVistas);
    ~Menu();
};


#endif // MENU_H_INCLUDED
