#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//#include<iostream> YA LO DECLARE EN UTILIDADES.H IGUAL HABRIA QUE DEJARLO ACA?
#include "Lista.h"
#include "utilidades.h"
using namespace std;

class Menu : public Utilidades{
private:
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Lista<string>* pelisVistas;
    Lista<string>* pelisNoVistas;
    Lista<string>* pelisRecomendadas; // hay que ver como liberar memoria
public:
    Menu();
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Menu(Lista<string>* vistas, Lista<string>* noVistas);
    void inicializar(string vistas, string noVistas);
    ~Menu();
};


#endif // MENU_H_INCLUDED
