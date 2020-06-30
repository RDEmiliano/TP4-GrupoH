#include "menu.h"
Menu::Menu(){
    if (MOSTRAR){
        mostrarExtra("Constructor MENU <sin parametros>", (int)this);
    }
}
Menu::Menu(Lista<Pelicula>* vistas, Lista<Pelicula>* noVistas){
    if (MOSTRAR){
        mostrarExtra("Constructor MENU <con parametros>", (int)this);
    }
    pelisVistas = vistas;
    pelisNoVistas = noVistas;
    pelisRecomendadas = new Lista<Pelicula>; // como liberar memoria??
}
void Menu::inicializar(string vistas, string noVistas){
    llenarLista(pelisVistas, vistas);                           //metodo en utilidades
    llenarLista(pelisNoVistas, noVistas);                       //metodo en utilidades
    recomendar(pelisRecomendadas, pelisVistas, pelisNoVistas);  //metodo en utilidades
}
int Menu::comenzar(){
    int eleccion;
    do{
        limpiarPantalla();
        cabecera();         //en utilidades
        menuPrincipal();    //en utilidades
        cin >> eleccion;
    }while(eleccion < 0 || eleccion > 3);
    cin.get();
    switch (eleccion){
        case 0:
            salir();
            break;
        case 1:
            peliculasVistas();
            break;
        case 2:
            peliculasNoVistas();
            break;
        case 3:
            peliculasRecomendadas();
            break;
    }
    return eleccion;
}
void Menu::salir(){
    limpiarPantalla();
    cabecera();
    despedida();    //en utilidades
    pausa();
}
void Menu::peliculasVistas(){
    limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS VISTAS\n" << endl;
    pausa();
}
void Menu::peliculasNoVistas(){
    limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS NO VISTAS\n" << endl;
    pausa();
}
void Menu::peliculasRecomendadas(){
    limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS RECOMENDADAS\n" << endl;
    pausa();
}
Menu::~Menu(){
    delete pelisRecomendadas;
    if (MOSTRAR){
        mostrarExtra("Destructor MENU", (int)this);
    }
}
