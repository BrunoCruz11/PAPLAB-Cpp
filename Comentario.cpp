#include "Comentario.hpp"
#include "DtComentario.hpp"
Comentario::Comentario(std::string T, Pelicula* P, Usuario* U){
    this->texto = T;
    this->pelicula = P;
    this->usuario = U;
    this->respondeA = NULL;
}
Comentario::Comentario(std::string T, Comentario* C, Usuario* U){
    this->texto = T;
    this->usuario = U;
    this->respondeA = C;
    this->pelicula = NULL;
}
Comentario::Comentario(Comentario& c){
    this->texto = c.getTexto();
    this->pelicula = c.getPelicula();
    this->respondeA = c.getRespondeA();
    this->usuario = c.getUsuario();
    this->respuestas = c.getCopiaRespuestas();//Ya verifique que la copia duplique el contenido del vector para que no dependa del copiado. 


}
Comentario::~Comentario(){}
std::string Comentario::getTexto(){
    return this->texto;
}
Pelicula* Comentario::getPelicula(){
    return this->pelicula;
}
Comentario* Comentario::getRespondeA(){
    return this->respondeA;
}
Usuario* Comentario::getUsuario(){
    return this->usuario;
}
std::string Comentario::getNicknameUsuario(){
    return this->usuario->getNickname();
}
std::vector<Comentario*> Comentario::getCopiaRespuestas(){
    return this->respuestas;
}
void Comentario::Comentario::agregarRespuesta(Comentario* C){
    this->respuestas.push_back(C);
}
std::vector<DtComentario> Comentario::getRespuestas(){
    std::vector<DtComentario> dataRespuestas;
    for(std::vector<Comentario*>::iterator it = this->respuestas.begin(); it != this->respuestas.end() ; it++){
        Comentario* respuesta = *it;
        DtComentario CActual(respuesta); //Terminar cuando este DtComentario pronto
        dataRespuestas.push_back(CActual);
    }
    return dataRespuestas;
}