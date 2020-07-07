#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#include<stdlib.h>
#include<iostream>
#include "Pelicula.h"
const int ANCHO_PANTALLA = 65;
const char SOMBRA = 176;//[176, 177, 178, 219]
class Pantalla{
public:
    Pantalla();
    ~Pantalla();
    void limpiarPantalla();//
    void menuPrincipal();//
    void despedida();//
    void subrayar();//
    void pausa();//
    void cabecera();//
    void enmarcar(Pelicula*);
private:
    void marcoArriba();
    void marcoUnaLinea(string linea);
    void marcoMedio();
    void marcoVacio();
    void marcoAbajo();
};

#endif // PANTALLA_H_INCLUDED
