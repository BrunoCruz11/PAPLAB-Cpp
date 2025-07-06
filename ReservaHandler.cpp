#include "ReservaHandler.hpp"
#include "CineHandler.hpp"
#include "PeliculaHandler.hpp"
#include <vector>
#include <string>

using namespace std;

// Inicialización de la instancia
ReservaHandler* ReservaHandler::instancia = nullptr; //inicializo la instancia en NULL

ReservaHandler::ReservaHandler() { //consturctor privado
    
}

ReservaHandler* ReservaHandler::getInstancia() { //si instancia = null la creo con new, sino la devuelvo directamente
    if (instancia == nullptr) {
        instancia = new ReservaHandler();
    }
    return instancia;
}

Reserva ReservaHandler::getReservaRecordada(){
    return this->ReservaRecordada;
}

vector <DtCine> ReservaHandler::darCinesDePelicula(vector <DtCine> coleccioncines, DtPelicula P){
    vector <DtCine> cinesadevolver;
    for(vector <DtCine>::iterator it = coleccioncines.begin(); it!= coleccioncines.end(); it++){
        map<string, Pelicula*> pelis = it->getPeliculas(); //funcion getpeliculas en cine, no esta hecha
        for(map<string,Pelicula*>::iterator iter2 = pelis.begin(); iter2!= pelis.end(); iter2++){
            //agarro de un cine las peliculas que tiene y las recorro todas
            if(iter2->first == P.getTitulo())
            {
                cinesadevolver.push_back(DtCine(it)); //agrega el cine al encontrar la pelicula
            }
        }   
    }
    return cinesadevolver;
} //devuelve cines en base a una pelicula dada
        

/*std::vector <DtReserva> obtenerReservas(){
    
} //lista las reservas realizadas por el usuario*/


void ReservaHandler::agregarReserva(int cantentradas, float costo, Usuario* u, Funcion* f) {
    Reserva* R = new Reserva(costo, cantentradas, f, u); //creo la reserva R con los parametros recibidos
    f->getReservas().push_back(R); //agrego la reserva en el vector reservas de funcion
}//agrego la reserva realizada al usuario, y tambien la agrego al vector reservas de funcion

void ReservaHandler::eliminarReserva() {
    this->ReservaRecordada = nullptr;
}

bool ReservaHandler::HayAsientos(Funcion* f){
    int entradascompradas = 0;
    vector<DtReserva> Reservas = f->listarReservas(); //tomo todas las reservas realizadas en la funcion f
    for(DtReserva r : Reservas){ //se recorre el vector de Reservas por rango a traves de un puntero r
        entradascompradas += r.getCantEntradas(); //acumulo las entradas compradas de esa funcion
    }
    if(f->getSala()->getCapacidad() > entradascompradas){ //si capacidad de sala donde se transmite f > entradascompradas, hay asientos libres
        return true; //devuelvo true ya que la capacidad es mas grande que las entradas compradas, hay espacio
    }
    else{
        return false; //devuelvo false porque no hay asientos libres
    }
}