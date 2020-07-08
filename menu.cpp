#include "menu.h"
Menu::Menu(){

    if (MOSTRAR_MEMORIA) cout << "Constructor MENU (" << this << ")" << endl;
    pelisVistas = new Lista<Pelicula*>;
    pelisNoVistas = new Lista<Pelicula*>;
    pelisRecomendadas = new Lista<Pelicula*>;

}

Menu::Menu(Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas,Lista<Pelicula*>* recomendadas){

    if (MOSTRAR_MEMORIA) cout << "Constructor MENU <con parametros> (" << this << ")" << endl;
    pelisVistas = vistas;
    pelisNoVistas = noVistas;
    pelisRecomendadas = recomendadas;

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
                cout << "ERROR: No existe el archivo: " << noVistas << endl << endl;
                salir();
                break;
            case 1: //Existen ambos archivos

                definirArranque(true);
                llenarLista(pelisNoVistas, noVistas);
                llenarLista(pelisVistas, vistas);
                recomendar(pelisVistas, pelisNoVistas);
                break;
            case 2: //No existe peliculas vistas

                definirArranque(true);
                llenarLista(pelisNoVistas, noVistas);
                recomendar(pelisNoVistas); // Solo recomienda por puntaje
                break;
        }
    }
}

int Menu::comenzar() {
    if (obtenerArranque()) {
        int eleccion;

        do{
            //limpiarPantalla();
            cabecera();         //en pantalla
            menuPrincipal();    //en pantalla
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
    } else
        return 0;
}

void Menu::salir(){
    //limpiarPantalla();
    cabecera();
    despedida();    //en pantalla
    pausa();
}

void Menu::peliculasVistas(){
    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS VISTAS\n" << endl;

    mostrarListadoPeliculas(pelisVistas);

    for (int i=1 ; i<this->pelisVistas->obtenerTamanio()+1; i++){
        cout<<endl;
        cout<< " Titulo: "<<this->pelisVistas->obtenerDato(i)->obtenerNombre()<<endl;
        cout<< " Genero: "<<this->pelisVistas->obtenerDato(i)->obtenerGenero()<<endl;
        cout<< " Puntaje: "<<this->pelisVistas->obtenerDato(i)->obtenerPuntaje()<<endl;
        cout<< " Director: "<<this->pelisVistas->obtenerDato(i)->obtenerDirector()<<endl;
        cout<< " Actores: ";
        this->pelisVistas->obtenerDato(i)->mostrarActores();
    }
    cout <<endl;
    pausa();
}

void Menu::peliculasNoVistas(){

    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS NO VISTAS\n" << endl;

    mostrarListadoPeliculas(pelisNoVistas);

    for (int i=1 ; i<this->pelisNoVistas->obtenerTamanio()+1; i++){
        cout<<endl;
        cout<< " Titulo: "<<this->pelisNoVistas->obtenerDato(i)->obtenerNombre()<<endl;
        cout<< " Genero: "<<this->pelisNoVistas->obtenerDato(i)->obtenerGenero()<<endl;
        cout<< " Puntaje: "<<this->pelisNoVistas->obtenerDato(i)->obtenerPuntaje()<<endl;
        cout<< " Director: "<<this->pelisNoVistas->obtenerDato(i)->obtenerDirector()<<endl;
        cout<< " Actores: ";
        this->pelisNoVistas->obtenerDato(i)->mostrarActores();
    }
    cout <<endl;
    pausa();
}

void Menu::peliculasRecomendadas(){

    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS RECOMENDADAS\n" << endl;
    mostrarListadoPeliculas(pelisRecomendadas);
    pausa();

}

void Menu::recomendar(Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas){

    subrayar();
    cout << "\nCarga lista de recomendados...\n\n";
    subrayar();
    pausa();
    Pelicula* vista;
    Pelicula* noVista;
    int cantPelisNoVistas = noVistas -> obtenerTamanio();
    int cantPelisVistas = vistas -> obtenerTamanio();

    for (int i = 1; i < cantPelisNoVistas + 1; i++){
            noVista = noVistas -> obtenerDato (i);
            if (tienePuntajeAdecuado(noVista)){
                cout << "Agrego peli nueva." << endl;
                cout << noVista->obtenerNombre() << endl;
                cout << "Puntaje adecuado: " << tienePuntajeAdecuado(noVista) << endl;
                pausa();
                agregarRecomendada (pelisRecomendadas,noVista);
            } else {
                for (int j = 1; j < cantPelisVistas + 1; j++) {
                    vista = vistas -> obtenerDato(j);
                    if ((coincideGenero(noVista, vista) && ((coincideDirector(noVista, vista)) || coincideAlMenosUnActor(noVista, vista)))) {
                        cout << "Agrego peli nueva." << endl;
                        cout << noVista->obtenerNombre() << endl;
                        cout << "Coincide genero: " << coincideGenero(noVista, vista) << endl;
                        cout << "Coincide Director: " << coincideDirector(noVista, vista) << endl;
                        cout << "Coincide algun actor: " << coincideAlMenosUnActor(noVista, vista) << endl;
                        agregarRecomendada(pelisRecomendadas, noVista);
                    }
                }
            }
    }
}

void Menu::recomendar(Lista<Pelicula*>* noVistas){

    int cantPelisNoVistas = noVistas -> obtenerTamanio();
    for (int i = 1; i < cantPelisNoVistas + 1; i++){
        if (noVistas -> obtenerDato(i) -> obtenerPuntaje() > PUNTAJE_MINIMO - 1){
            pelisRecomendadas -> insertar(noVistas -> obtenerDato(i),1);
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

    for (int i = 0; i < pelisVistas->obtenerTamanio(); i++){
        delete pelisVistas->obtenerDato(i+1);
    }
    delete pelisVistas;

    for (int i = 0; i < pelisNoVistas->obtenerTamanio(); i++){
        delete pelisNoVistas->obtenerDato(i+1);
    }

    delete pelisNoVistas;
    delete pelisRecomendadas;

    if (MOSTRAR_MEMORIA) cout << "Destructor MENU (" << this << ")" <<endl;

}
