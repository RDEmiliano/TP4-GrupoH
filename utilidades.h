#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include<iostream>
#include<cstdlib>
#include<fstream>
#include "Lista.h"
#include "Pelicula.h"

const bool MOSTRAR = true;
using namespace std;

class Utilidades{
public:
    Utilidades();
    void mostrarExtra(string texto, int numero);
    void limpiarPantalla();
    void subrayar();
    void pausa();
    void cabecera();
    void llenarLista(Lista<Pelicula>* listaAllenar, string nombreArchivo);
    void recomendar(Lista<Pelicula>* recomendadas, Lista<Pelicula>* vistas, Lista<Pelicula>* noVistas);
    ~Utilidades();
};


#endif // UTILIDADES_H_INCLUDED
