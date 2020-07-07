#include "menu.h"
Menu::Menu(){
    if (MOSTRAR) cout << "Constructor MENU (" << this << ")" << endl;
    pelisVistas = new Lista<Pelicula*>;
    pelisNoVistas = new Lista<Pelicula*>;
    pelisRecomendadas = new Lista<Pelicula*>;
}

Menu::Menu(Lista<Pelicula*>* vistas, Lista<Pelicula*>* noVistas,Lista<Pelicula*>* recomendadas){
    if (MOSTRAR) cout << "Constructor MENU <con parametros> (" << this << ")" << endl;
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
    } else
        return 0;
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
        this->pelisVistas->obtenerDato(i)->mostrarActores();
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
        this->pelisNoVistas->obtenerDato(i)->mostrarActores();
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
        this->pelisRecomendadas->obtenerDato(i)->mostrarActores();
    }
    cout <<endl;
    cout << "LA LISTA TIENE TAMANIO "<< pelisRecomendadas-> obtenerTamanio()<<endl;
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

/*void Menu::llenarListita(Lista<string>* listita, string comparado){
    cout << "LLENANDO LISTITA" << endl;
    int lugar = 0;
    bool agregar = true;
    string enLista;
    while(lugar < listita->obtenerTamanio() && agregar){
        enLista = listita->obtenerDato(lugar + 1);
        if(comparado == enLista){
            agregar = false;
        }
        lugar++;
    }
    if (agregar){
        listita->insertar(comparado, 1);
    }
}*/

/* //ORIGINAL 1RA VERSION////
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
/*
void Menu::recomendar_version_con_listas_auxiliares(){
    subrayar();
    cout << "\nCarga lista de recomendados...\n\n";
    subrayar();
    pausa();

    bool vioPeliculas = (pelisVistas->obtenerTamanio() > 0);
    string comparando;
    Lista<string>* ptrGeneros = 0;
    Lista<string>* ptrDirectores = 0;
    Lista<string>* ptrActores = 0;

    if(vioPeliculas){
        subrayar();
        cout << "Haciendo listas de generos, directores y actores vistos \n(solo si vio peliculas)\n";
        subrayar();
        pausa();

        ptrGeneros = new Lista<string>;
        ptrDirectores = new Lista<string>;
        ptrActores = new Lista<string>;

        armarListitas(ptrGeneros, ptrDirectores, ptrActores);   // y las muestra pero es solo para control
        // luego eliminar

    }

    subrayar();
    pausa();

    for (unsigned i = 0; i < pelisNoVistas->obtenerTamanio(); i++){
        if (pelisNoVistas->obtenerDato(i + 1)->obtenerPuntaje() >= PUNTAJE_MINIMO){
            pelisRecomendadas->insertar(pelisNoVistas->obtenerDato(i + 1), 1);
        }else{
            if(vioPeliculas){
                string enLista;
                bool agregado = false;
                for (int m = 0; m < ptrGeneros->obtenerTamanio(); m++){
                    enLista = ptrGeneros->obtenerDato(m + 1);
                    comparando = pelisNoVistas->obtenerDato(i + 1)->obtenerGenero();

                    if(comparando == enLista){
                        int j = 0;//ptr directores
                        int h = 0;//ptr actor
                        int k = 0;//actor en peli no vista
                        string actorEnLista, actorComparado, direEnLista, direComparado;
                        do{
                            direEnLista = ptrDirectores->obtenerDato(j + 1);
                            direComparado = pelisNoVistas->obtenerDato(i + 1)->obtenerDirector();
                            do{
                                actorEnLista = ptrActores->obtenerDato(h + 1);
                                do{
                                    actorComparado = pelisNoVistas->obtenerDato(i + 1)->obtenerActorEn(k + 1);
                                    if((direComparado == direEnLista) || (actorComparado == actorEnLista)){
                                        pelisRecomendadas->insertar(pelisNoVistas->obtenerDato(i + 1), 1);
                                        agregado = true;
                                    }
                                    k++;
                                }while(k < pelisNoVistas->obtenerDato(i + 1)->obtenerCantActores() && agregado == false);
                                k = 0;
                                h++;
                            }while(h < ptrActores->obtenerTamanio() && agregado == false);
                            h = 0;
                            j++;
                        }while(j < ptrDirectores->obtenerTamanio() && agregado == false);
                    }
                }
            }
        }
    }
    if(vioPeliculas){
        delete ptrGeneros;
        delete ptrDirectores;
        delete ptrActores;
    }
}

void Menu::armarListitas(Lista<string>* ptrGeneros, Lista<string>* ptrDirectores, Lista<string>* ptrActores){
    string comparando;
    for(int i = 0; i < pelisVistas->obtenerTamanio(); i++){
        comparando = pelisVistas->obtenerDato(i + 1)->obtenerGenero();
        llenarListita(ptrGeneros, comparando);
        comparando = pelisVistas->obtenerDato(i + 1)->obtenerDirector();
        llenarListita(ptrDirectores, comparando);
        for(int j = 0; j < pelisVistas->obtenerDato(i + 1)->obtenerCantActores(); j++){
            comparando = pelisVistas->obtenerDato(i + 1)->obtenerActorEn(j + 1);
            llenarListita(ptrActores, comparando);
        }
    }
    subrayar();
    cout<<"Listas para comparar: " << endl;
    subrayar();
    pausa();
    cout<<"GENEROS VISTOS:" << endl;
    for(int i = 0; i < ptrGeneros->obtenerTamanio(); i++){
        cout << "\t\t" << ptrGeneros->obtenerDato(i + 1) << endl;;
    }
    cout<<"DIRECTORES VISTOS:" << endl;
    for(int i = 0; i < ptrDirectores->obtenerTamanio(); i++){
        cout << "\t\t" << ptrDirectores->obtenerDato(i + 1) << endl;
    }
    cout<<"ACTORES VISTOS:" << endl;
    for(int i = 0; i < ptrActores->obtenerTamanio(); i++){
        cout << "\t\t" << ptrActores->obtenerDato(i + 1) << endl;
    }
}*/