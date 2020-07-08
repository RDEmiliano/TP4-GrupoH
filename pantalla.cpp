#include "pantalla.h"
using namespace std;
Pantalla::Pantalla(){
}
Pantalla::~Pantalla(){
}

void Pantalla::limpiarPantalla(){
    #ifdef _WIN32
        system ("cls");
    #else
        // Assume POSIX
        system ("clear");
    #endif
}
void Pantalla::menuPrincipal(){
    cout << "1- Lista peliculas vistas." << endl;
    cout << "2- Lista no peliculas vistas." << endl;
    cout << "3- Recomendaciones." << endl;
    cout << "0- Salir." << endl;
    cout << endl;
    cout << "Eleccion: ";
}
void Pantalla::despedida(){
    cout << "\nFin del programa.\n" << endl;
}
void Pantalla::subrayar(){
    for (int i = 0; i < 50; i++){
        cout << "-";
    }
    cout << endl;
}
void Pantalla::pausa(){
    cout << "<Enter>";
    cin.get();
}
void Pantalla::cabecera(){
    subrayar();
    subrayar();
    cout << "- TRABAJO PRACTICO Nro. 4 - GRUPO H -" << endl;
    subrayar();
    subrayar();
}
void Pantalla::enmarcar(Pelicula* aEnmarcar){
    marcoArriba();
    marcoUnaLinea(aEnmarcar->obtenerNombre());
    marcoMedio();
    marcoUnaLinea("Direccion: " + aEnmarcar->obtenerDirector());
    ostringstream puntaje;
    puntaje << aEnmarcar->obtenerPuntaje();
    marcoSeparacion("Genero: " + aEnmarcar->obtenerGenero(), "Puntuacion: " + puntaje.str());
    marcoUnaLinea("< Actuan >");
    marcoVacio();
    for(int i=0; i < aEnmarcar->obtenerCantActores(); i++){
        marcoUnaLinea(aEnmarcar->obtenerActorEn(i + 1));
    }
    marcoVacio();
    marcoAbajo();
}

void Pantalla::marcoSeparacion(string texto1, string texto2){
    int medio, margen1, margen2;
    medio = ANCHO_PANTALLA / 2;
    margen1 = (medio / 2) - (texto1.length() / 2);
    margen2 = medio + ((medio / 2) - (texto2.length() / 2));
    cout << " ";
    cout << (char)204;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        if(i == medio){
            cout << (char)203;
        }else{
            cout << (char)205;
        }
    }
    cout << (char)185 << SOMBRA << endl;

    cout << " ";
    cout << (char)186;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        if(i >= margen1 && (i - margen1) < texto1.length()){
            cout << texto1[i - margen1];
        }else if(i >= margen2 && (i - margen2) < texto2.length()){
            cout << texto2[i - margen2];
        }else if(i == medio){
            cout << (char)186;
        }else{
            cout << " ";
        }
    }
    cout << (char)186 << SOMBRA << endl;

    cout << " ";
    cout << (char)204;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        if(i == medio){
            cout << (char)202;
        }else{
            cout << (char)205;
        }
    }
    cout << (char)185 << SOMBRA << endl;
}
void Pantalla::marcoArriba(){
    cout << " ";
    cout << (char)201;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        cout << (char)205;
    }
    cout << (char)187 << endl;
}
void Pantalla::marcoVacio(){
    cout << " ";
    cout << (char)186;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        cout << " ";
    }
    cout << (char)186 << SOMBRA  << endl;
}
void Pantalla::marcoAbajo(){
    cout << " ";
    cout << (char)200;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        cout << (char)205;
    }
    cout << (char)188 << SOMBRA  << endl;
    cout << "  ";
    for(int i = 0; i < ANCHO_PANTALLA; i++){
        cout << SOMBRA;
    }
    cout << endl;
}
void Pantalla::marcoMedio(){
    cout << " ";
    cout << (char)204;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        cout << (char)205;
    }
    cout << (char)185 << SOMBRA  << endl;
}
void Pantalla::marcoUnaLinea(string linea){
    cout << " ";
    int centrado, margen;
    centrado = (ANCHO_PANTALLA / 2) - (linea.length() / 2);
    margen = centrado;
    cout << (char)186;
    for(int i = 0; i < ANCHO_PANTALLA - 2; i++){
        if(i >= margen && (i - margen) < linea.length()){
            cout << linea[i - margen];
        }else{
            cout << " ";
        }
    }
    cout << (char)186 << SOMBRA  << endl;
}
