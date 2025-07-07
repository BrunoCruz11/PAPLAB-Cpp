#include "PeliculaController.hpp"
#include <vector>
#include <string>
#include "DtPelicula.hpp"
#include "Pelicula.hpp"
#include <stdexcept>
#include <iostream>

PeliculaController::PeliculaController(){
   this->manejadorpeli = PeliculaHandler::getInstancia();
}

PeliculaController* PeliculaController::instancia = NULL;

 PeliculaController* PeliculaController::getInstancia(){
    if(instancia==NULL){
        instancia= new PeliculaController();
    }

    return instancia;

 }


 void PeliculaController::agregarPelicula(string titulo, string sipnosis, string urlPoster){
   if(manejadorpeli->existePelicula(titulo)){
      throw std::invalid_argument("Ya existe una pelicula con ese titulo.:(");
   }
   std::cout << "pre pushback" << std::endl; 
   peliculasRecordadas.push_back(DtPelicula(titulo,sipnosis,urlPoster));
 }


 void PeliculaController::confirmarAltaPelicula(){
   for(DtPelicula P : peliculasRecordadas){
      manejadorpeli->agregarPelicula(P);
   }
 }

 std::vector<DtPelicula> PeliculaController::listarPeliculas(){
   return manejadorpeli->darPeliculas();
 }

 DtPelicula PeliculaController::eligePelicula(string titulo){
    DtPelicula PeliculaActual = manejadorpeli->getPelicula(titulo);
    peliculasRecordadas.push_back(PeliculaActual);

    return PeliculaActual;
 }

 void PeliculaController::borrarPelicula(){

        //manejadorpeli->(Pelicula(darPeliculas())) //?????? JAJAJAJAJJA


 }


 void PeliculaController::cancelarEliminarPelicula(){}
 
