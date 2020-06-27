#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include<iostream>
#include "Lista.h"

const bool MOSTRAR = true;
using namespace std;

class Utilidades{
public:
    Utilidades();
    void mostrarExtra(string texto, int numero);
    void llenarLista(Lista<string>* listaAllenar, string nombreArchivo);
    ~Utilidades();
};


#endif // UTILIDADES_H_INCLUDED
