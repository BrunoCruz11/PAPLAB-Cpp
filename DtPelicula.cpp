#include "DtPelicula.hpp"
#include <string>

using namespace std;

//Constructores
DtPelicula::DtPelicula(string titulo, string sinopsis, float puntajePromedio, std::vector<DtComentario> comentariosPelicula, string poster){
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->puntajePromedio = puntajePromedio;
    this->comentariosPelicula = comentariosPelicula;
    this->poster = poster;
}
DtPelicula::DtPelicula(Pelicula& P){
    this->titulo = P.getTitulo();
    this->sinopsis = P.getSinopsis();
    this->puntajePromedio = P.getPuntajePromedio();
    this->comentariosPelicula = comentariosPelicula;
    this->poster = P.getPoster();
}
DtPelicula::DtPelicula(Pelicula* P){
    this->titulo = P->getTitulo();
    this->sinopsis = P->getSinopsis();
    this->puntajePromedio = P->getPuntajePromedio();
    this->comentariosPelicula = comentariosPelicula;
    this->poster = P->getPoster();
}
DtPelicula::DtPelicula(DtPelicula& P){
    this->titulo = P.getTitulo();
    this->sinopsis = P.getSinopsis();
    this->puntajePromedio = P.getPuntajePromedio();
    this->comentariosPelicula = comentariosPelicula;
    this->poster = P.getPoster();
}
DtPelicula::DtPelicula(){}
//Getters
vector<DtComentario> DtPelicula::getComentarios(){
   return this->comentariosPelicula; 
}

string DtPelicula::getTitulo()const{
    return this->titulo;
}

string DtPelicula::getSinopsis()const{
    return this->sinopsis;
}

string DtPelicula::getPoster()const{
    return this->poster;
}

float DtPelicula::getPuntajePromedio()const{
    return this->puntajePromedio;
}