#include "menu.h"
Menu::Menu(){
    if (MOSTRAR) cout << "Constructor MENU (" << this << ")" << endl;
}
Menu::Menu(Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas,Lista<Pelicula*>* recomendadas){
    if (MOSTRAR) cout << "Constructor MENU <con parametros> (" << this << ")" << endl;
    pelisVistas = vistas;
    pelisNoVistas = noVistas;
    pelisRecomendadas = recomendadas;
}

void Menu::inicializar(string vistas, string noVistas){
    llenarLista(pelisNoVistas, noVistas);                       //metodo en utilidades
    llenarLista(pelisVistas, vistas);
    recomendar();
    /*
    if (pelisVistas->obtenerTamanio()) {
       recomendar(pelisRecomendadas, pelisVistas, pelisNoVistas);  //metodo en Menu
    } else {
        recomendar(pelisRecomendadas,pelisNoVistas);
      }
    */
}

int Menu::comenzar(){
    int eleccion;
    do{
        //limpiarPantalla();
        cabecera();         //en utilidades
        menuPrincipal();    //en utilidades
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
}
void Menu::salir(){
    //limpiarPantalla();
    cabecera();
    despedida();    //en utilidades
    pausa();
}
void Menu::peliculasVistas(){
    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS VISTAS\n" << endl;
    for (int i=1 ; i<this->pelisVistas->obtenerTamanio()+1; i++){
        cout<<endl;
        cout<< " Titulo: "<<this->pelisVistas->obtenerDato(i)->obtenerNombre()<<endl;
        cout<< " Genero: "<<this->pelisVistas->obtenerDato(i)->obtenerGenero()<<endl;
        cout<< " Puntaje: "<<this->pelisVistas->obtenerDato(i)->obtenerPuntaje()<<endl;
        cout<< " Director: "<<this->pelisVistas->obtenerDato(i)->obtenerDirector()<<endl;
        cout<< " Actores: ";
        this->pelisVistas->obtenerDato(i)->obtenerActores();
    }
    cout <<endl;
    pausa();
}
void Menu::peliculasNoVistas(){
    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS NO VISTAS\n" << endl;
    for (int i=1 ; i<this->pelisNoVistas->obtenerTamanio()+1; i++){
        cout<<endl;
        cout<< " Titulo: "<<this->pelisNoVistas->obtenerDato(i)->obtenerNombre()<<endl;
        cout<< " Genero: "<<this->pelisNoVistas->obtenerDato(i)->obtenerGenero()<<endl;
        cout<< " Puntaje: "<<this->pelisNoVistas->obtenerDato(i)->obtenerPuntaje()<<endl;
        cout<< " Director: "<<this->pelisNoVistas->obtenerDato(i)->obtenerDirector()<<endl;
        cout<< " Actores: ";
        this->pelisNoVistas->obtenerDato(i)->obtenerActores();
    }
    cout <<endl;
    pausa();
}
void Menu::peliculasRecomendadas(){
    //limpiarPantalla();
    cabecera();
    cout << "\nMOSTRAMOS LISTA PELICULAS RECOMENDADAS\n" << endl;
    for (int i=1 ; i<this->pelisRecomendadas->obtenerTamanio()+1; i++){
        cout<<endl;
        cout<< " Titulo: "<<this->pelisRecomendadas->obtenerDato(i)->obtenerNombre()<<endl;
        cout<< " Genero: "<<this->pelisRecomendadas->obtenerDato(i)->obtenerGenero()<<endl;
        cout<< " Puntaje: "<<this->pelisRecomendadas->obtenerDato(i)->obtenerPuntaje()<<endl;
        cout<< " Director: "<<this->pelisRecomendadas->obtenerDato(i)->obtenerDirector()<<endl;
        cout<< " Actores: ";
        this->pelisRecomendadas->obtenerDato(i)->obtenerActores();
    }
    cout <<endl;
    cout << "LA LISTA TIENE TAMANIO "<< pelisRecomendadas-> obtenerTamanio()<<endl;
    pausa();
}

void Menu::recomendar(){
    bool vioPeliculas = (pelisVistas->obtenerTamanio() > 0);
    bool agregar = true;
    Lista<string>* ptrGeneros = 0;
    Lista<string>* ptrDirectores = 0;
    Lista<string>* ptrActores = 0;
    string aux;

    if(vioPeliculas){
        ptrGeneros = new Lista<string>;
        ptrDirectores = new Lista<string>;
        ptrActores = new Lista<string>;
        for(int i = 0; i < pelisVistas->obtenerTamanio(); i++){
            aux = pelisVistas->obtenerDato(i + 1)->obtenerGenero();
            for(int j = 0; j < ptrGeneros->obtenerTamanio(); j++){
                if(aux == ptrGeneros->obtenerDato(j + 1)){
                    agregar = false;
                }
            }
            if (agregar){
                ptrGeneros->insertar(aux, 1);
            }
            agregar = true;
            aux = pelisVistas->obtenerDato(i + 1)->obtenerDirector();
            for(int j = 0; j < ptrDirectores->obtenerTamanio(); j++){
                if(aux == ptrDirectores->obtenerDato(j + 1)){
                    agregar = false;
                }
            }
            if (agregar){
                ptrDirectores->insertar(aux, 1);
            }
            //actores//
            agregar = true;

        }
    }
    for (unsigned i = 0; i < pelisNoVistas->obtenerTamanio(); i++){
        if (pelisNoVistas->obtenerDato(i + 1)->obtenerPuntaje() >= PUNTAJE_MINIMO){
            pelisRecomendadas->insertar(pelisNoVistas->obtenerDato(i + 1), 1);
        }else{
            if(vioPeliculas){
                //ACA TENDRIA QUE VERIFICAR LO DEMAS
                delete ptrGeneros;
                delete ptrDirectores;
                delete ptrActores;
            }
        }
    }
}

/*



    Pelicula* vista;
    Pelicula* noVista;
    int cantPelisNoVistas = noVistas -> obtenerTamanio();
    int cantPelisVistas = vistas -> obtenerTamanio();

    for (int i = 1; i < cantPelisNoVistas + 1; i++){
        for (int j = 1; j < cantPelisVistas; j++){
            noVista = noVistas -> obtenerDato (i);
            vista = vistas -> obtenerDato (j);

            if ( ( coincideGenero(noVista,vista) && (coincideDirector(noVista,vista) || coincideAlMenosUnActor(noVista,vista)) )
                || tienePuntajeAdecuado(noVista) ){

                agregarRecomendada (pelisRecomendadas,noVista);
            }
        }
    }
    subrayar();
    cout << "\nCarga lista de recomendados...\n\n";
    subrayar();
    pausa();
}

void Menu::recomendar(Lista<Pelicula*>* recomendadas, Lista<Pelicula*>* noVistas){
    int cantPelisNoVistas = noVistas -> obtenerTamanio();
    for (int i = 1; i < cantPelisNoVistas + 1; i++){
        if (noVistas -> obtenerDato(i) -> obtenerPuntaje() > PUNTAJE_MINIMO - 1){
            recomendadas -> insertar(noVistas -> obtenerDato(i),1);
        }
    }
}
*/
/*
void Menu::recomendar(Lista<Pelicula*>* recomendadas, Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas){

    Pelicula* vista;
    Pelicula* noVista;
    int cantPelisNoVistas = noVistas -> obtenerTamanio();
    int cantPelisVistas = vistas -> obtenerTamanio();

    for (int i = 1; i < cantPelisNoVistas + 1; i++){
        for (int j = 1; j < cantPelisVistas; j++){
            noVista = noVistas -> obtenerDato (i);
            vista = vistas -> obtenerDato (j);

            if ( ( coincideGenero(noVista,vista) && (coincideDirector(noVista,vista) || coincideAlMenosUnActor(noVista,vista)) )
                || tienePuntajeAdecuado(noVista) ){

                agregarRecomendada (pelisRecomendadas,noVista);
            }
        }
    }
    subrayar();
    cout << "\nCarga lista de recomendados...\n\n";
    subrayar();
    pausa();
}

void Menu::recomendar(Lista<Pelicula*>* recomendadas, Lista<Pelicula*>* noVistas){
    int cantPelisNoVistas = noVistas -> obtenerTamanio();
    for (int i = 1; i < cantPelisNoVistas + 1; i++){
        if (noVistas -> obtenerDato(i) -> obtenerPuntaje() > PUNTAJE_MINIMO - 1){
            recomendadas -> insertar(noVistas -> obtenerDato(i),1);
        }
    }
}
*/
Menu::~Menu(){

    for (int i = 0; i < pelisVistas->obtenerTamanio(); i++){
        cout << "borro ptrPeli dentro de PelisVistas: " << pelisVistas->obtenerDato(i+1)->obtenerNombre() << endl;
        delete pelisVistas->obtenerDato(i+1);
    }
    delete pelisVistas;

    for (int i = 0; i < pelisNoVistas->obtenerTamanio(); i++){
        cout << "borro ptrPeli dentro de PelisNoVistas: " << pelisNoVistas->obtenerDato(i+1)->obtenerNombre() << endl;
        delete pelisNoVistas->obtenerDato(i+1);
    }
    delete pelisNoVistas;

    delete pelisRecomendadas;

    if (MOSTRAR) cout << "Destructor MENU (" << this << ")" <<endl;

}
