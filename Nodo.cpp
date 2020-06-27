//
// Created by emiliano on 26/6/20.
//

#include "Nodo.h"

template<class T>
Nodo<T>::Nodo(T datoNuevo) {
    siguiente = 0; //CAMBIE NULLPTR PORQUE ME DABA ERROR
    dato = datoNuevo;

}

template<class T>
Nodo<T>::~Nodo() {
    delete dato;
    siguiente = 0;//CAMBIE NULLPTR PORQUE ME DABA ERROR
}

template<class T>
T Nodo<T>::obtenerDato() {
    return dato;
}

template<class T>
void Nodo<T>::asignarSiguiente(Nodo<T> *ps) {
    siguiente = ps;
}

template<class T>
Nodo<T> * Nodo<T>::obtenerSiguiente() {
    return siguiente;
}
