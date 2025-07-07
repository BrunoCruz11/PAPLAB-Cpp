#include "PeliculaController.hpp"
#include <vector>
#include <string>
#include "DtPelicula.hpp"
#include "Pelicula.hpp"
#include <stdexcept>

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
    PeliculaRecordada = PeliculaActual ;
    return PeliculaActual;
 }

 void PeliculaController::borrarPelicula(){
   if(!manejadorpeli->existePelicula(PeliculaRecordada.getTitulo())){ //verifica si existe la pelicula
      throw std::invalid_argument("No existe esa pelicula");
   }
   else{
      manejadorpeli->recordarPelicula(PeliculaRecordada.getTitulo()); //recuerda la pelicula que se va a eliminar
      this->PeliculaRecordada = manejadorpeli->getPelicula(PeliculaRecordada.getTitulo()); //guarda la pelicula recordada en el controller
      manejadorpeli->quitaryborrarPelicula(); // elimina la película
     /* it = peliculasRecordadas.erase(it); // erase devuelve el nuevo iterador 
      for (vector<DtPelicula>::iterator it = peliculasRecordadas.begin(); it != peliculasRecordadas.end(); ) {
         if (it->getTitulo() == PeliculaRecordada.getTitulo()) {

         } else {
            ++it; // solo avanzás si no eliminaste
         }
      }*/
   }



 }


 void PeliculaController::cancelarEliminarPelicula(){}
 
