#include "menu.h"
Menu::Menu(){
    if (MOSTRAR) cout << "Constructor MENU (" << this << ")" << endl;
}
Menu::Menu(Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas){
    if (MOSTRAR) cout << "Constructor MENU <con parametros> (" << this << ")" << endl;
    pelisVistas = vistas;
    pelisNoVistas = noVistas;
    pelisRecomendadas = new Lista<Pelicula*>; // como liberar memoria??
}
void Menu::inicializar(string vistas, string noVistas){
    llenarLista(pelisVistas, vistas);                           //metodo en utilidades
    llenarLista(pelisNoVistas, noVistas);                       //metodo en utilidades
    recomendar(pelisRecomendadas, pelisVistas, pelisNoVistas);  //metodo en utilidades
}
int Menu::comenzar(){
    int eleccion;
    do{
        //limpiarPantalla();
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
    //limpiarPantalla();
    cabecera();
    despedida();    //en utilidades
    pausa();
}
void Menu::peliculasVistas(){
    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS VISTAS\n" << endl;
    for (int i=1 ; i<this->pelisVistas->obtenerTamanio()+1; i++){
        cout<<endl;
        cout<< " Titulo: "<<this->pelisVistas->obtenerDato(i)->obtenerNombre()<<endl;
        cout<< " Genero: "<<this->pelisVistas->obtenerDato(i)->obtenerGenero()<<endl;
        cout<< " Puntaje: "<<this->pelisVistas->obtenerDato(i)->obtenerPuntaje()<<endl;
        cout<< " Director: "<<this->pelisVistas->obtenerDato(i)->obtenerDirector()<<endl;
        cout<< " Actores: "<<endl;
        this->pelisVistas->obtenerDato(i)->obtenerActores();
    }
    cout <<endl;
    pausa();
}
void Menu::peliculasNoVistas(){
    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS NO VISTAS\n" << endl;
    for (int i=1 ; i<this->pelisNoVistas->obtenerTamanio()+1; i++){
        cout<<endl;
        cout<< " Titulo: "<<this->pelisNoVistas->obtenerDato(i)->obtenerNombre()<<endl;
        cout<< " Genero: "<<this->pelisNoVistas->obtenerDato(i)->obtenerGenero()<<endl;
        cout<< " Puntaje: "<<this->pelisNoVistas->obtenerDato(i)->obtenerPuntaje()<<endl;
        cout<< " Director: "<<this->pelisNoVistas->obtenerDato(i)->obtenerDirector()<<endl;
        cout<< " Actores: "<<endl;
        this->pelisNoVistas->obtenerDato(i)->obtenerActores();
    }
    cout <<endl;
    pausa();
}
void Menu::peliculasRecomendadas(){
    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS RECOMENDADAS\n" << endl;
    pausa();
}
Menu::~Menu(){
    for (int i = 0; i < pelisVistas->obtenerTamanio(); i++){
        cout << "borro ptrPeli dentro de PelisVistas: " << pelisVistas->obtenerDato(i+1)->obtenerNombre() << endl;
        delete pelisVistas->obtenerDato(i+1);
    }

    delete pelisVistas;

    for (int i = 0; i < pelisNoVistas->obtenerTamanio(); i++){
        cout << "borro ptrPeli dentro de PelisNoVistas: " << pelisNoVistas->obtenerDato(i+1)->obtenerNombre() << endl;
        delete pelisNoVistas->obtenerDato(i+1);
    }
    delete pelisNoVistas;

    delete pelisRecomendadas;

    if (MOSTRAR) cout << "Destructor MENU (" << this << ")" <<endl;

}
