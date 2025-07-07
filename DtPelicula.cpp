#include "DtPelicula.hpp"
#include <string>

using namespace std;

//Constructores
DtPelicula::DtPelicula(DtPelicula& P){
    this->titulo = P.getTitulo();
    this->sinopsis = P.getSinopsis();
    this->puntajePromedio = P.getPuntajePromedio();
    this->comentariosPelicula = P.getComentarios();
    this->poster = P.getPoster();
}
DtPelicula::DtPelicula(std::string& titulo, std::string& sinopsis, float& puntajePromedio, std::string& poster){
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->puntajePromedio = puntajePromedio;
    this->poster = poster;
}
DtPelicula::DtPelicula(string titulo,string sinopsis,string urlPoster){
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->poster = urlPoster;
}
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
    this->comentariosPelicula = P.getComentarios();
    this->poster = P.getPoster();
}
DtPelicula::DtPelicula(Pelicula* P){
    this->titulo = P->getTitulo();
    this->sinopsis = P->getSinopsis();
    this->puntajePromedio = P->getPuntajePromedio();
    this->comentariosPelicula = P->getComentarios();
    this->poster = P->getPoster();
}
DtPelicula::DtPelicula(const DtPelicula& P){
    this->titulo = P.getTitulo();
    this->sinopsis = P.getSinopsis();
    this->puntajePromedio = P.getPuntajePromedio();
    this->comentariosPelicula = P.getComentarios();
    this->poster = P.getPoster();
}
DtPelicula::DtPelicula(){}
//Getters
vector<DtComentario> DtPelicula::getComentarios()const {
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