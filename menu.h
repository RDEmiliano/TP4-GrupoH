#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Lista.h"
#include "Pelicula.h"
#include "utilidades.h"
using namespace std;

class Menu : public Utilidades{

private:
    bool arranque;
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Lista<Pelicula*>* pelisVistas;
    Lista<Pelicula*>* pelisNoVistas;
    Lista<Pelicula*>* pelisRecomendadas; // hay que ver como liberar memoria

public:

    Menu();
    //CAMBIAR STRING POR CLASE PELICULA!!!!!
    Menu(Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas, Lista<Pelicula*>* recomendadas);

    void inicializar(string vistas, string noVistas);
    int comenzar();

    void peliculasVistas();
    void peliculasNoVistas();
    void peliculasRecomendadas();
    void recomendar();
    void llenarListita(Lista<string>* listita, string comparado);
    //void recomendar(Lista<Pelicula*>* recomendadas, Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas);
    //void recomendar(Lista<Pelicula*>* recomendadas, Lista<Pelicula*>* noVistas);

    bool obtenerArranque() const;
    void definirArranque(bool estado);

    void salir();
    ~Menu();

};


#endif // MENU_H_INCLUDED
