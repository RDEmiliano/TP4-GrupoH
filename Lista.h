//
// Created by emiliano on 26/6/20.
//

#ifndef UNTITLED2_LISTA_H
#define UNTITLED2_LISTA_H
#include "Nodo.h"

template<class T>
class Lista{
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



Lista<T>::Lista() {
    if (MOSTRAR_MEMORIA){
        std::cout << "Constructor LISTA (" << (int)this << ")" << std::endl;
    }
    primero = 0;
    tam = 0;
}

Lista<T>::~Lista<T>() {
    while (!(listaVacia()))
        eliminarDato(1);
    if (MOSTRAR_MEMORIA){
        std::cout << "Destructor LISTA (" << (int)this << ")" << std::endl;
    }
}


bool Lista<T>::listaVacia() {
    return ( primero == 0);
}

void Lista<T>::insertar(T d, unsigned int pos) {
    Nodo<T> * nuevo = new Nodo<T>(d);
    if (pos == 1){
        nuevo -> asignarSiguiente(primero);
        primero = nuevo;
    } else {
        Nodo<T> * anterior = obtenerNodo(pos - 1);
        nuevo -> asignarSiguiente(anterior -> obtenerSiguiente());
        anterior -> asignarSiguiente(nuevo);
    }
}

T Lista<T>::obtenerDato(unsigned int pos) {
    Nodo<T> * paux = obtenerNodo(pos);
    return paux -> obtenerDato();
}


void Lista<T>::eliminarDato(unsigned pos) {
    Nodo<T> * borrar = primero;
    if (pos == 1){
        primero = borrar -> obtenerSiguiente();
    } else {
        Nodo<T> * anterior = obtenerNodo( pos - 1);
        borrar = anterior -> obtenerSiguiente();
        anterior -> asignarSiguiente(borrar -> obtenerSiguiente());
    }
    delete borrar;
    tam--;
}


unsigned Lista<T>::obtenerTamanio() {
    return tam;
}

Nodo<T> * Lista<T>::obtenerNodo(unsigned int pos) {
    Nodo<T> * aux = primero;
    unsigned i = 1;
    while (i < pos){
        aux = aux -> obtenerSiguiente();
        i++;
    }
    return aux;
}



#endif //UNTITLED2_LISTA_H
