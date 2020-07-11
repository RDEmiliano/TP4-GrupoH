#include "Utilidades.h"

Utilidades::Utilidades(){
    if (MOSTRAR_MEMORIA) cout << "Constructor UTILIDADES (" << this << ")" << endl;
}

void Utilidades::llenarLista(Lista<Pelicula*>* listaAllenar, string nombreArchivo){
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
                   case 1: ptrPelicula -> asignarNombre(linea);
                        break;
                   case 2: ptrPelicula -> asignarGenero(linea);
                        break;
                   case 3: ptrPelicula -> asignarPuntaje(linea);
                        break;
                   case 4: ptrPelicula -> asignarDirector(linea);
                        break;
                   case 5: ptrPelicula -> asignarActores(linea);
                        break;
                   default:
                       break;
                }
            } while (( numLinea < 6 )&&(!archivo.eof()));
            listaAllenar -> insertar(ptrPelicula,1); // inserta en posicion 1.
        };

        archivo.close();

    } else {
        cout << "El archivo no se abrio correctamente" << endl;
    };
}

bool Utilidades::coincideGenero(Pelicula* noVista, Pelicula* vista){
    return (noVista -> obtenerGenero() == vista -> obtenerGenero());
}

bool Utilidades::coincideDirector(Pelicula* noVista, Pelicula* vista){
    return (noVista -> obtenerDirector() == vista -> obtenerDirector());
}

bool Utilidades::tienePuntajeAdecuado(Pelicula* pelicula){
     return (pelicula -> obtenerPuntaje() > PUNTAJE_MINIMO - 1);
}

bool Utilidades::coincideAlMenosUnActor(Pelicula* noVista, Pelicula* vista){

    int cantActoresEnNoVista = noVista -> obtenerCantActores();
    int cantActoresEnVista = vista -> obtenerCantActores();
    int i = 0;
    int j = 0;
\
    bool hayCoincidencia = false;

    while(i < cantActoresEnNoVista && !hayCoincidencia){
        while(j < cantActoresEnVista && !hayCoincidencia){
                if(noVista -> obtenerActorEn(i + 1) == vista -> obtenerActorEn(j + 1)){
                    hayCoincidencia = true;
                }
            j++;
        }
        j = 0;
        i++;
    }
    return hayCoincidencia;
}

void Utilidades::mostrarListadoPeliculas(Lista<Pelicula*>* aMostrar){
    ostringstream cantidad;

    for (int i = 0; i < aMostrar -> obtenerTamanio(); i++){
        enmarcar(aMostrar -> obtenerDato(i + 1));
        cout << endl;
    }

    cantidad << aMostrar -> obtenerTamanio();

    if(aMostrar -> obtenerTamanio() == 1){
        enmarcar(cantidad.str() + " pelicula en la lista");
    }else{
        enmarcar(cantidad.str() + " peliculas en la lista");
    }

    cout << endl;
}

Utilidades::~Utilidades(){
    if (MOSTRAR_MEMORIA) cout << "Destructor UTILIDADES (" << this << ")" << endl;
}
