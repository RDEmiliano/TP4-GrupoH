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
/*void Utilidades::recomendar(Lista<Pelicula*>* recomendadas, Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas){
    for(int i = 0; i < noVistas->obtenerTamanio(); i++){
        if(noVistas->obtenerDato(i + 1)->obtenerPuntaje() > 6){
            recomendadas->insertar(noVistas->obtenerDato(i + 1), 1);
            cout << "\nPuntaje 7 o mayor...\n\n";
        }else{
            cout << "\nPuntaje 6 o menor hay que ver por otros motivos de recomendaciones...\n\n";
        }
    }
    subrayar();
    cout << "\nCarga lista de recomendados...\n\n";
    subrayar();
    pausa();
}*/

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
    int i = 1;
    bool hayCoincidencia = false;

    if (cantActoresEnNoVista < cantActoresEnVista){
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
