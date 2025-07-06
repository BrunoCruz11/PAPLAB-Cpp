#include <string>
#include <vector>

#include "DtComentario.hpp"
#include "Pelicula.hpp"
DtComentario::DtComentario(std::string t, std::string nnu, std::string tituloP){
    this->texto = t;
    this->nicknameUsuario = nnu;
    this->tituloP = tituloP;
}
DtComentario::DtComentario(std::string t, std::string nnu, DtComentario* respondeA){
    this->texto = t;
    this->nicknameUsuario = nnu;
    this->respondeA = respondeA;
}
DtComentario::DtComentario(const DtComentario& C){
    this->tituloP = C.getTituloP();
    this->texto = C.getTexto();
    this->nicknameUsuario = C.getNicknameUsuario();
    this->respuestas = C.getRespuestas();
}

DtComentario::DtComentario(Comentario* C){
    this->tituloP = C->getPelicula()->getTitulo();
    this->texto = C->getTexto();
    this->nicknameUsuario = C->getNicknameUsuario();
    this->respuestas = C->getRespuestas();
}

std::string DtComentario::getTexto() const{
    return this->texto;
}

std::string DtComentario::getNicknameUsuario() const{
    return this->nicknameUsuario;
}

std::string DtComentario::getTituloP() const{
    return this->tituloP;
}

std::vector<DtComentario> DtComentario::getRespuestas() const{
    return this->respuestas;
}