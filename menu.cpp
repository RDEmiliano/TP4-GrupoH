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
                recomendar();
                //recomienda de manera normal
                break;
            case 2: //No existe peliculas vistas

                definirArranque(true);
                llenarLista(pelisNoVistas, noVistas);
                recomendar();
                //recomienda solo por puntaje
                break;

        }
    }
    //recomendar();

                          //metodo en utilidades


    /*
    if (pelisVistas->obtenerTamanio()) {
       recomendar(pelisRecomendadas, pelisVistas, pelisNoVistas);  //metodo en Menu
    } else {
        recomendar(pelisRecomendadas,pelisNoVistas);
      }
    */
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

void Menu::recomendar(){

    bool vioPeliculas = (pelisVistas->obtenerTamanio() > 0);
    bool agregar = true;
    Lista<string>* ptrGeneros = 0;
    Lista<string>* ptrDirectores = 0;
    Lista<string>* ptrActores = 0;
    string comparando;
    string enLista;

    if(vioPeliculas){
        subrayar();
        cout << "Haciendo listas de generos, directores y actores vistos \n(solo si vio peliculas)\n";
        subrayar();
        ptrGeneros = new Lista<string>;
        ptrDirectores = new Lista<string>;
        ptrActores = new Lista<string>;

        for(int i = 0; i < pelisVistas->obtenerTamanio(); i++){
            comparando = pelisVistas->obtenerDato(i + 1)->obtenerGenero();
            for(int j = 0; j < ptrGeneros->obtenerTamanio(); j++){
                enLista = ptrGeneros->obtenerDato(j + 1);
                if(comparando == enLista){
                    agregar = false;
                }
            }
            if (agregar){
                ptrGeneros->insertar(comparando, 1);
            }
            agregar = true;
            comparando = pelisVistas->obtenerDato(i + 1)->obtenerDirector();
            for(int j = 0; j < ptrDirectores->obtenerTamanio(); j++){
                enLista = ptrDirectores->obtenerDato(j + 1);
                if(comparando == enLista){
                    agregar = false;
                }
            }
            if (agregar){
                ptrDirectores->insertar(comparando, 1);
            }
            for(int j = 0; j < pelisVistas->obtenerDato(i + 1)->obtenerCantActores(); j++){
                agregar = true;
                comparando = pelisVistas->obtenerDato(i + 1)->obtenerActorEn(j + 1);
                for(int h = 0; h < ptrActores->obtenerTamanio(); h++){
                    enLista = ptrActores->obtenerDato(h + 1);
                    if(comparando == enLista){
                        agregar = false;
                    }
                }
                if (agregar){
                    ptrActores->insertar(comparando, 1);
                }
            }
        }
        subrayar();
        cout<<"Listas para comparar: " << endl;
        pausa();
        cout<<"GENEROS VISTOS:" << endl;
        for(int i = 0; i < ptrGeneros->obtenerTamanio(); i++){
            cout << ptrGeneros->obtenerDato(i + 1) << endl;;
        }
        cout<<"DIRECTORES VISTOS:" << endl;
        for(int i = 0; i < ptrDirectores->obtenerTamanio(); i++){
            cout << ptrDirectores->obtenerDato(i + 1) << endl;
        }
        cout<<"ACTORES VISTOS:" << endl;
        for(int i = 0; i < ptrActores->obtenerTamanio(); i++){
            cout << ptrActores->obtenerDato(i + 1) << endl;
        }
        cout << endl;
    }

    pausa();

    for (unsigned i = 0; i < pelisNoVistas->obtenerTamanio(); i++){
        if (pelisNoVistas->obtenerDato(i + 1)->obtenerPuntaje() >= PUNTAJE_MINIMO){
            pelisRecomendadas->insertar(pelisNoVistas->obtenerDato(i + 1), 1);
        }else{
            if(vioPeliculas){
                string enLista;
                string comparando;
                bool agregado = false;
                for (int i = 0; i < ptrGeneros->obtenerTamanio(); i++){
                    enLista = ptrGeneros->obtenerDato(i + 1);
                    comparando = pelisNoVistas->obtenerDato(i + 1)->obtenerGenero();
                    if(comparando == enLista){
                        int j = 0;
                        int h = 0;
                        string actorEnLista, actorComparado, direEnLista, direComparado;
                        do{
                            direEnLista = ptrDirectores->obtenerDato(j + 1);
                            direComparado = pelisNoVistas->obtenerDato(i + 1)->obtenerDirector();
                            do{
                                actorEnLista = ptrActores->obtenerDato(h + 1);
                                for(int k = 0; k < pelisNoVistas->obtenerDato(i + 1)->obtenerCantActores(); k++){
                                    actorComparado = pelisNoVistas->obtenerDato(i + 1)->obtenerActorEn(k + 1);
                                    if((direComparado == direEnLista) || (actorComparado == actorEnLista)){
                                        pelisRecomendadas->insertar(pelisNoVistas->obtenerDato(i + 1), 1);
                                        agregado = true;
                                    }
                                }
                                h++;
                            }while(h < ptrActores->obtenerTamanio() && agregado == false);
                            j++;
                        }while(j < ptrDirectores->obtenerTamanio() && agregado == false);
                    }
                }
                //ACA TENDRIA QUE VERIFICAR LO DEMAS
                delete ptrGeneros;
                delete ptrDirectores;
                delete ptrActores;
            }
        }
    }
}


bool Menu::obtenerArranque() const {
    return arranque;
}

void Menu::definirArranque(bool estado){
    this -> arranque = estado;
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
