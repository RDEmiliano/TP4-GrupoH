#include "utilidades.h"

Utilidades::Utilidades(){
    if (MOSTRAR) cout << "Constructor UTILIDADES (" << this << ")" << endl;
}

void Utilidades::llenarLista(Lista<Pelicula*>* listaAllenar, string nombreArchivo){
    subrayar();
    cout << "\nCarga una lista con datos del archivo\n\n";
    ifstream archivo(nombreArchivo);
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

bool Utilidades::coincideGenero(Pelicula* noVista, Pelicula* vista){
    return (noVista->obtenerGenero() == vista->obtenerGenero());
}

bool Utilidades::coincideDirector(Pelicula* noVista, Pelicula* vista){
    return (noVista->obtenerDirector() == vista->obtenerDirector());
}

bool Utilidades::tienePuntajeAdecuado(Pelicula* pelicula){
     return (pelicula->obtenerPuntaje() > PUNTAJE_MINIMO - 1);
}

bool Utilidades::coincideAlMenosUnActor(Pelicula* noVista, Pelicula* vista){
    int cantActoresEnNoVista = noVista->obtenerCantActores();
    int cantActoresEnVista = vista->obtenerCantActores();
    int i = 0;
    int j = 0;
    //int i = 1;
    bool hayCoincidencia = false;

    while(i < cantActoresEnNoVista && !hayCoincidencia){
        while(j < cantActoresEnVista && !hayCoincidencia){
                if(noVista->obtenerActorEn(i + 1) == vista->obtenerActorEn(j + 1)){
                    hayCoincidencia = true;
                }
            j++;
        }
        j = 0;
        i++;
    }

    /*
    if (cantActoresEnNoVista < cantActoresEnVista){ //ACA NO SE SI HACE BIEN
        while ((!hayCoincidencia) && (i < cantActoresEnNoVista)){
            if (noVista->obtenerListaActores()->obtenerDato(i) == noVista->obtenerListaActores()->obtenerDato(i)){
                hayCoincidencia = true;
            }
            i++;
        }
    } else {
            while ((!hayCoincidencia) && (i < cantActoresEnVista)){
               if (noVista->obtenerListaActores()->obtenerDato(i) == noVista->obtenerListaActores()->obtenerDato(i)){
                   hayCoincidencia = true;
                }
               i++;
            }
    }
    */
    return hayCoincidencia;
}

void Utilidades::agregarRecomendada(Lista<Pelicula*>* pelisRecomendadas, Pelicula * pelicula){
     pelisRecomendadas -> insertar (pelicula,1);
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
