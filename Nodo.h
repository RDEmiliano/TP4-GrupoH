#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include<iostream>

const bool MOSTRAR_MEMORIA = false;

template<class T>

class Nodo{
    private:
        T dato;
        Nodo<T> * siguiente;
    public:
        //Constructor con parametro
        // PRE : Ninguna
        // POST : Crea un nodo con el dato d y el puntero a NULL
        Nodo(T datoNuevo);

        // Destructor
        // PRE : Nodo creado
        // POST : No hace nada
        ~Nodo();

        // PRE : nodo creado
        // POST : devuelve el dato que contiene el nodo
        T obtenerDato();

        // PRE : nodo creado
        // POST : el puntero al siguiente nodo apuntará a ps
        void asignarSiguiente(Nodo<T> * ps);

        // PRE : nodo creado
        // POST : Devuelve el puntero al siguiente nodo
        // Si es el último devuelve NULL
        Nodo<T> * obtenerSiguiente();
};

template<class T>
Nodo<T>::Nodo(T datoNuevo) {
    siguiente = 0;
    dato = datoNuevo;
}

template<class T>
Nodo<T>::~Nodo() {
    siguiente = 0;
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

#endif //TP4_GRUPOH__NODO_H
