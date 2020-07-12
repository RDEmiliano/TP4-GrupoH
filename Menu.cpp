#include "Menu.h"
Menu::Menu(){

    if (MOSTRAR_MEMORIA) cout << "Constructor MENU (" << this << ")" << endl;
    pelisVistas = new Lista<Pelicula*>;
    pelisNoVistas = new Lista<Pelicula*>;
    pelisRecomendadas = new Lista<Pelicula*>;

}

void Menu::inicializar(string vistas, string noVistas){

    ifstream archivoNoVistas;
    ifstream archivoVistas;

    try {
        archivoNoVistas.open(noVistas);
        archivoVistas.open(vistas);
        if (!archivoNoVistas.fail())
            if (!archivoVistas.fail())
                throw 1;
            else
                throw 2;
        else
            throw 0;

    } catch (int bandera){

        switch (bandera) {
            case 0: //No existe peliculas no vistas
                definirArranque(false);
                archivoNoVistas.close();
                archivoVistas.close();
                cabecera();
                cout << "\n\n\n\n";
                enmarcar("ERROR!");
                enmarcar("No existe el archivo de peliculas no vistas");
                enmarcar("Nombre archivo: " + noVistas);
                cout << "\n\n\n\n\n\n";
                enmarcar("Pulse Enter para finalizar programa");
                cout << endl;
                //cout << "ERROR: No existe el archivo: " << noVistas << endl << endl;
                pausa();
                salir();
                break;

            case 1: //Existen ambos archivos
                definirArranque(true);
                llenarLista(pelisNoVistas, noVistas);
                llenarLista(pelisVistas, vistas);
                recomendar();
                break;

            case 2: //No existe peliculas vistas
                definirArranque(true);
                llenarLista(pelisNoVistas, noVistas);
                recomendarSoloPuntaje(); // Solo recomienda por puntaje
                break;

            default:
                break;
        }
    }
}

int Menu::comenzar() {

    if (obtenerArranque()) {
        unsigned char eleccion;
        string aux;
        do{
            limpiarPantalla();
            cabecera();         //en pantalla
            menuPrincipal();    //en pantalla
            cin >> aux;
            eleccion = aux[0];
        }while(eleccion < 48 || eleccion > 51);

        cin.get();

        switch (eleccion){
            case 48:
                salir();
                break;

            case 49:
                peliculasVistas();
                break;

            case 50:
                peliculasNoVistas();
                break;

            case 51:
                peliculasRecomendadas();
                break;

            default:
                break;
        }
        return eleccion;
    } else
        return 48;
}

void Menu::salir(){
    limpiarPantalla();
    cabecera();
    despedida();
    pausa();
}

void Menu::peliculasVistas(){
    limpiarPantalla();
    if(pelisVistas -> obtenerTamanio()){
        enmarcar("MOSTRAMOS LISTA PELICULAS VISTAS");
        mostrarListadoPeliculas(pelisVistas);
    }else{
        cabecera();
        cout << "\n\n\n\n\n\n";
        enmarcar("ATENCION!");
        enmarcar("NO HAY DATOS DE PELICULAS QUE HAYA VISTO");
        cout << "\n\n\n\n\n\n";
    }
    pausa();
}

void Menu::peliculasNoVistas(){
    limpiarPantalla();
    enmarcar("MOSTRAMOS LISTA PELICULAS NO VISTAS");
    mostrarListadoPeliculas(pelisNoVistas);
    pausa();
}

void Menu::peliculasRecomendadas(){
    limpiarPantalla();
    if(pelisRecomendadas->obtenerTamanio()){
        enmarcar("MOSTRAMOS LISTA PELICULAS RECOMENDADAS");
        mostrarListadoPeliculas(pelisRecomendadas);
    }else{
        cabecera();
        cout << "\n\n\n\n\n\n";
        enmarcar("ATENCION!");
        enmarcar("NO HAY PELICULAS PARA RECOMENDAR");
        cout << "\n\n\n\n\n\n";
    }
    pausa();
}

void Menu::recomendar(){

    Pelicula* vista;
    Pelicula* noVista;
    unsigned int cantPelisNoVistas = pelisNoVistas -> obtenerTamanio();
    unsigned int cantPelisVistas = pelisVistas -> obtenerTamanio();

    for (int i = 1; i < cantPelisNoVistas + 1; i++){
            noVista = pelisNoVistas -> obtenerDato (i);
            if (tienePuntajeAdecuado(noVista)){
                pelisRecomendadas->insertar(noVista, 1);
                //agregarRecomendada (pelisRecomendadas,noVista);
            } else {
                for (int j = 1; j < cantPelisVistas + 1; j++) {
                    vista = pelisVistas -> obtenerDato(j);
                    if ((coincideGenero(noVista, vista) && ((coincideDirector(noVista, vista)) || coincideAlMenosUnActor(noVista, vista)))) {
                        pelisRecomendadas -> insertar(noVista, 1);
                        //agregarRecomendada(pelisRecomendadas, noVista);
                    }
                }
            }
    }
}

void Menu::recomendarSoloPuntaje(){
    unsigned int cantPelisNoVistas = pelisNoVistas -> obtenerTamanio();
    for (int i = 1; i < cantPelisNoVistas + 1; i++){
        if (tienePuntajeAdecuado(pelisNoVistas -> obtenerDato(i))){  //noVistas -> obtenerDato(i) -> obtenerPuntaje() > PUNTAJE_MINIMO - 1
            pelisRecomendadas -> insertar(pelisNoVistas -> obtenerDato(i),1);
        }
    }
}

bool Menu::obtenerArranque() const {
    return arranque;
}

void Menu::definirArranque(bool estado){
    this -> arranque = estado;
}


Menu::~Menu(){
    for (unsigned i = 0; i < pelisVistas -> obtenerTamanio(); i++){
        delete pelisVistas -> obtenerDato(i + 1);
    }
    delete pelisVistas;

    for (unsigned i = 0; i < pelisNoVistas -> obtenerTamanio(); i++){
        delete pelisNoVistas -> obtenerDato(i + 1);
    }
    delete pelisNoVistas;

    delete pelisRecomendadas;

    if (MOSTRAR_MEMORIA) cout << "Destructor MENU (" << this << ")" <<endl;
}
