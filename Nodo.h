//
// Created by emiliano on 26/6/20.
//

#ifndef UNTITLED2_NODO_H
#define UNTITLED2_NODO_H

template<class T>

class Nodo {
    private:
        T dato;
        Nodo<T> * siguiente;
    public:
        Nodo(T datoNuevo);
        ~Nodo();
        T obtenerDato();
        void asignarSiguiente(Nodo<T> * ps);
        Nodo<T> * obtenerSiguiente();
};


#endif //UNTITLED2_NODO_H
