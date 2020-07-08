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
    return hayCoincidencia;
}

void Utilidades::agregarRecomendada(Lista<Pelicula*>* pelisRecomendadas, Pelicula * pelicula){
     pelisRecomendadas -> insertar (pelicula,1);
}

void Utilidades::mostrarListadoPeliculas(Lista<Pelicula*>* aMostrar){
    for (int i= 0; i < aMostrar->obtenerTamanio(); i++){
        enmarcar(aMostrar->obtenerDato(i + 1));
        cout << endl;
        cout << endl;
    }
}

Utilidades::~Utilidades(){
    if (MOSTRAR) cout << "Destructor UTILIDADES (" << this << ")" << endl;
}

/*
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
*/
/*
void Utilidades::enmarcar(Pelicula* aEnmarcar){
    //cuadrito arriba
    int ancho = 60;
    cout << (char)201;
    for(int i = 0; i < ancho - 2; i++){
        cout << (char)205;
    }
    cout << (char)187 << endl;

    //texto de una linea
    char sombra = 219;
    string muestra;
    int centrado, margen;
    muestra = aEnmarcar->obtenerNombre();
    centrado = (ancho / 2) - (muestra.length() / 2);
    margen = centrado;
    cout << (char)186;
    for(int i = 0; i < ancho - 2; i++){
        if(i >= margen && (i - margen) < muestra.length()){
            cout << muestra[i - margen];
        }else{
            cout << " ";
        }
    }
    cout << (char)186 << sombra << endl;

    //cuadrito enmedio de algo
    cout << (char)204;
    for(int i = 0; i < ancho - 2; i++){
        cout << (char)205;
    }
    cout << (char)185 << sombra  << endl;


    //texto de una linea
    muestra = "Direccion: " + aEnmarcar->obtenerDirector();
    centrado = (ancho / 2) - (muestra.length() / 2);
    margen = centrado;
    cout << (char)186;
    for(int i = 0; i < ancho - 2; i++){
        if(i >= margen && (i - margen) < muestra.length()){
            cout << muestra[i - margen];
        }else{
            cout << " ";
        }
    }
    cout << (char)186 << sombra  << endl;

    //cuadrito vacio
    cout << (char)186;
    for(int i = 0; i < ancho - 2; i++){
        cout << " ";
    }
    cout << (char)186 << sombra  << endl;



    //cuadrito abajo
    cout << (char)200;
    for(int i = 0; i < ancho - 2; i++){
        cout << (char)205;
    }
    cout << (char)188 << sombra  << endl;
    cout << " ";
    for(int i = 0; i < ancho; i++){
        cout << sombra;
    }
    cout << endl;

}
*/
/*
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
*/
