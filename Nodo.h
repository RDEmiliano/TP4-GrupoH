//
// Created by emiliano on 26/6/20.
//

#ifndef TP4_GRUPOH__NODO_H
#define TP4_GRUPOH__NODO_H

#include<iostream>

const bool MOSTRAR_MEMORIA = true;

template<class T>

class Nodo{
    private:
        T dato; // PUSE * XQ ME DABA ERROR EL DESTRUCTOR... AHORA LE SAQUE EL *..
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
    if (MOSTRAR_MEMORIA) std::cout << "Constructor NODO (" << this << ")" << std::endl;
    siguiente = 0; //CAMBIE NULLPTR PORQUE ME DABA ERROR
    //AHORA ME TIRABA ERROR ESTO DE ABAJO, LO QUE HICE FUE QUITAR EL * DEL DATO DEL NODO, Y
    //COMENTAR EL "DELETE DATO" DEL DESTRUCTOR
    dato = datoNuevo;

}

template<class T>
Nodo<T>::~Nodo() {
    //delete dato;
    siguiente = 0;//CAMBIE NULLPTR PORQUE ME DABA ERROR
    if (MOSTRAR_MEMORIA) std::cout << "Destructor NODO (" << this << ")" << std::endl;
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
