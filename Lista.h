//
// Created by emiliano on 26/6/20.
//

#ifndef UNTITLED2_LISTA_H
#define UNTITLED2_LISTA_H
#include "Nodo.h"

template<class T>
class Lista {
    //Atributos
    private:
        Nodo<T> * primero;
        int tam;

    //Metodos
    public:
        Lista();
        ~Lista();

        bool listaVacia();
        void insertar(T d, unsigned pos);
        void eliminarDato(unsigned pos);

        T obtenerDato(unsigned pos);
        unsigned obtenerTamanio();

    private:
        Nodo<T> * obtenerNodo (unsigned pos);
};


#endif //UNTITLED2_LISTA_H
