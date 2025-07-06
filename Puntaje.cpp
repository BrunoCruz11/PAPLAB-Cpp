#include "Puntaje.hpp"
#include "Usuario.hpp"
#include "Pelicula.hpp"

Puntaje::Puntaje(int P , Usuario* U , Pelicula* peli){
    this->usuario = U;
    this->pelicula = peli;
    this->puntos = P;
}
Puntaje::Puntaje(Puntaje& P){
    this->puntos = P.getPuntaje();
}
Puntaje::~Puntaje(){}
std::string Puntaje::getNickUsuario()const{
    return this->usuario->getNickname();
}
std::string Puntaje::getTituloPelicula()const{
    return this->pelicula->getTitulo();
}
int Puntaje::getPuntaje()const{
    return this->puntos;
}