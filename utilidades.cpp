#include "utilidades.h"
Utilidades::Utilidades(){
    if (MOSTRAR){
        mostrarExtra("Constructor UTILIDADES", (int)this);
    }
}
void Utilidades::mostrarExtra(string texto, int numero){
    cout << texto << " (" << numero << ")"<< endl;
}
void Utilidades::llenarLista(Lista<string>* listaAllenar, string nombreArchivo){
    cout << "Carga una lista con datos del archivo\n";
}
Utilidades::~Utilidades(){
    if (MOSTRAR){
        mostrarExtra("Destructor UTILIDADES", (int)this);
    }
}
