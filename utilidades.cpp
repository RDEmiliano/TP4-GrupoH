#include "utilidades.h"
Utilidades::Utilidades(){
    if (MOSTRAR) cout << "Constructor UTILIDADES (" << this << ")" << endl;
}
void Utilidades::llenarLista(Lista<Pelicula*>* listaAllenar, string nombreArchivo){
    subrayar();
    cout << "\nCarga una lista con datos del archivo\n\n";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    int numLinea;

    if (!archivo.fail()){
        while(!archivo.eof()) {

            Pelicula* ptrPelicula = new Pelicula;

            numLinea = 0;

            do{
               getline(archivo,linea);
               numLinea++;
               switch (numLinea) {
                   case 1: ptrPelicula->asignarNombre(linea);
                        break;
                   case 2: ptrPelicula->asignarGenero(linea);
                        break;
                   case 3: ptrPelicula->asignarPuntaje(linea);
                        break;
                   case 4: ptrPelicula->asignarDirector(linea);
                        break;
                   case 5: ptrPelicula->asignarActores(linea);
                        break;
                }
            } while (( numLinea < 6 )&&(!archivo.eof()));
            listaAllenar->insertar(ptrPelicula,1); // inserta en posicion 1.
        };

        archivo.close();

    } else {
        cout << "El archivo no se abrio correctamente" << endl;
    };
    subrayar();
    pausa();
}
void Utilidades::recomendar(Lista<Pelicula*>* recomendadas, Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas){
    subrayar();
    cout << "\nCarga lista de recomendados...\n\n";
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
void Utilidades::menuPrincipal(){
    cout << "1- Lista peliculas vistas." << endl;
    cout << "2- Lista no peliculas vistas." << endl;
    cout << "3- Recomendaciones." << endl;
    cout << "0- Salir." << endl;
    cout << endl;
    cout << "Eleccion: ";
}
void Utilidades::despedida(){
    cout << "\nFin del programa.\n" << endl;
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
    if (MOSTRAR) cout << "Destructor UTILIDADES (" << this << ")" << endl;
}
