//
// Created by emiliano on 26/6/20.
//

#ifndef UNTITLED2_NODO_H
#define UNTITLED2_NODO_H

#include<iostream>

const bool MOSTRAR_MEMORIA = true;

template<class T>

class Nodo{
    private:
        T* dato; // PUSE * XQ ME DABA ERROR EL DESTRUCTOR
        Nodo<T> * siguiente;
    public:
        Nodo(T datoNuevo);
        ~Nodo();
        T obtenerDato();
        void asignarSiguiente(Nodo<T> * ps);
        Nodo<T> * obtenerSiguiente();
};

template<class T>
Nodo<T>::Nodo(T datoNuevo) {
    if (MOSTRAR_MEMORIA){
        std::cout << "Destructor NODO (" << (int)this << std::endl;
    }
    siguiente = 0; //CAMBIE NULLPTR PORQUE ME DABA ERROR
    dato = datoNuevo;

}

template<class T>
Nodo<T>::~Nodo() {
    delete dato;
    siguiente = 0;//CAMBIE NULLPTR PORQUE ME DABA ERROR
    if (MOSTRAR_MEMORIA){
        std::cout << "Destructor NODO (" << (int)this << std::endl;
    }
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

#endif //UNTITLED2_NODO_H
