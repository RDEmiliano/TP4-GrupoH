#include "utilidades.h"
Utilidades::Utilidades(){
    if (MOSTRAR){
        mostrarExtra("Constructor UTILIDADES", (int)this);
    }
}
void Utilidades::mostrarExtra(string texto, int numero){
    cout << texto << " (" << numero << ")"<< endl;
}
void Utilidades::llenarLista(Lista<Pelicula>* listaAllenar, string nombreArchivo){
    subrayar();
    cout << "Carga una lista con datos del archivo\n";
    subrayar();
    pausa();
}
void Utilidades::recomendar(Lista<Pelicula>* recomendadas, Lista<Pelicula>* vistas, Lista<Pelicula>* noVistas){
    subrayar();
    cout << "Carga lista de recomendados...\n";
    subrayar();
    pausa();
}
void Utilidades::subrayar(){
    for (int i = 0; i < 50; i++){
        cout << "-";
    }
    cout << endl;
}
void Utilidades::limpiarPantalla(){
    #ifdef _WIN32
        system ("cls");
    #else
        // Assume POSIX
        system ("clear");
    #endif
}
void Utilidades::cabecera(){
    subrayar();
    subrayar();
    cout << "- TRABAJO PRACTICO Nro. 4 - GRUPO H -" << endl;
    subrayar();
    subrayar();
}
void Utilidades::pausa(){
    cout << "<Enter>";
    cin.get();
}
Utilidades::~Utilidades(){
    if (MOSTRAR){
        mostrarExtra("Destructor UTILIDADES", (int)this);
    }
}
