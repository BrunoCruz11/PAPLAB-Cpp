#include "PeliculaController.hpp"
#include <vector>
#include <string>
#include "DtPelicula.hpp"
#include "Pelicula.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

PeliculaController::PeliculaController(){
   this->manejadorpeli = PeliculaHandler::getInstancia();
}

PeliculaController* PeliculaController::instancia = NULL;

 PeliculaController* PeliculaController::getInstancia(){
    if(instancia==NULL){
        instancia= new PeliculaController();
    }

PeliculaController* PeliculaController::getInstancia(){
   if(instancia==NULL){
      instancia= new PeliculaController();
   }
   return instancia;
}

void PeliculaController::agregarPelicula(string titulo, string sipnosis, string urlPoster){
   DtPelicula PeliculaRecordada = DtPelicula(titulo,sipnosis,urlPoster); //hay que llamar al constructor a traves del handler, no existe la funcion DtPelicula en el controller


void PeliculaController::confirmarAltaPelicula(){
    Pelicula *p = new Pelicula(this->PeliculaRecordada); //PeliculaRecordada es un Dt, no un tipo Pelicula, cambiar luego

}

std::vector<DtPelicula> PeliculaController::listarPeliculas(){
   return PeliculaHandler::getInstancia()->darPeliculas();
}

 DtPelicula PeliculaController::eligePelicula(string titulo){
    DtPelicula PeliculaActual = manejadorpeli->getPelicula(titulo);
    peliculasRecordadas.push_back(PeliculaActual);

    return PeliculaActual;
}

void PeliculaController::borrarPelicula(){
   vector <DtPelicula> Peliculas = PeliculaHandler::getInstancia()->darPeliculas(); //arregle a lo que queria hacer la funcion pero falta recorrer todas las peliculas, y una vez q se encuentre eliminarla, aunq necesita un identificador pasado por parametros tambien, capaz q es al pedo la funcion no c

}


void PeliculaController::cancelarEliminarPelicula(){

}
