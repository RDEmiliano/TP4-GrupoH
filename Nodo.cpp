//
// Created by emiliano on 26/6/20.
//

#include "Nodo.h"

template<class T>
Nodo<T>::Nodo(T datoNuevo) {
    siguiente = nullptr;
    dato = datoNuevo;

}

template<class T>
Nodo<T>::~Nodo() {
    delete dato;
    siguiente = nullptr;
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