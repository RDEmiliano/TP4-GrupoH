#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//#include<iostream> YA LO DECLARE EN UTILIDADES.H IGUAL HABRIA QUE DEJARLO ACA?
#include "Lista.h"
#include "Pelicula.h"
#include "utilidades.h"
using namespace std;

class Menu : public Utilidades{
private:
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Lista<Pelicula>* pelisVistas;
    Lista<Pelicula>* pelisNoVistas;
    Lista<Pelicula>* pelisRecomendadas; // hay que ver como liberar memoria
public:
    Menu();
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Menu(Lista<Pelicula>* vistas, Lista<Pelicula>* noVistas);
    void inicializar(string vistas, string noVistas);
    int comenzar();
    ~Menu();
};


#endif // MENU_H_INCLUDED
