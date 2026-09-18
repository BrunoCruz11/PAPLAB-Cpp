#include "DtPuntaje.hpp"

DtPuntaje::DtPuntaje(int P , std::string U , std::string peli){
    this->puntos = P;
    this->nicknameUsuario = U;
    this->tituloPelicula = peli;
}
DtPuntaje::DtPuntaje(const DtPuntaje& P){
    this->puntos = P.getPuntaje();
    this->nicknameUsuario = P.getNicknameUsuario();
    this->tituloPelicula = P.getTituloPelicula();
}
DtPuntaje::DtPuntaje(Puntaje* P){
    this->puntos = P->getPuntaje();
    this->nicknameUsuario = P->getNickUsuario();
    this->tituloPelicula = P->getTituloPelicula();
}
DtPuntaje::~DtPuntaje(){
    
}

std::string DtPuntaje::getNicknameUsuario()const{
    return this->nicknameUsuario;
}
std::string DtPuntaje::getTituloPelicula()const{
    return this->tituloPelicula;
}
int DtPuntaje::getPuntaje()const{
    return this->puntos;
}