#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include<iostream>
#include<cstdlib>
#include<fstream>
#include "Lista.h"

const bool MOSTRAR = true;
using namespace std;

class Utilidades{
public:
    Utilidades();
    void mostrarExtra(string texto, int numero);
    void limpiarPantalla();
    void subrayar();
    void pausa();
    void llenarLista(Lista<string>* listaAllenar, string nombreArchivo);
    void recomendar(Lista<string>* recomendadas, Lista<string>* vistas, Lista<string>* noVistas);
    ~Utilidades();
};


#endif // UTILIDADES_H_INCLUDED
