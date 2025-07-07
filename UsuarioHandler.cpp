#include "UsuarioHandler.hpp"
#include "Comentario.hpp"
#include <stdexcept>

UsuarioHandler* UsuarioHandler::instancia = NULL;

UsuarioHandler::UsuarioHandler(){
    Usuario* usuarioAdmin = new Usuario("admin" , "admin" , true);
    Usuario* usuarioPato = new Usuario("pato" , "123" , false);
    usuarios.insert({usuarioAdmin->getNickname() , usuarioAdmin});
    usuarios.insert({usuarioPato->getNickname() , usuarioPato});

}
UsuarioHandler::~UsuarioHandler(){}

UsuarioHandler* UsuarioHandler::getInstancia(){
    if (instancia == NULL){
        instancia = new UsuarioHandler();
    }
    return instancia;
}

Usuario* UsuarioHandler::getUsuario(std::string nicknameUsuario){
    return usuarios.find(nicknameUsuario)->second;
}
void UsuarioHandler::agregarUsuario(std::string nickname , std::string contrasenia){
    Usuario* nuevoUsuario = new Usuario(nickname , contrasenia);
    if(usuarios.find(nickname) == usuarios.end()){
        usuarios.insert({nickname , nuevoUsuario});
    }
    else{
        throw std::invalid_argument("Ya hay un usuario con ese nickname");
    }
}
void UsuarioHandler::agregarUsuario(std::string nickname , std::string contrasenia , std::string urlFoto){
        Usuario* nuevoUsuario = new Usuario(nickname , contrasenia);
    if(usuarios.find(nickname) == usuarios.end()){
        nuevoUsuario->setFoto(urlFoto);
        usuarios.insert({nickname , nuevoUsuario});
    }
    else{
        throw std::invalid_argument("Ya hay un usuario con ese nickname");
    }
}
void UsuarioHandler::setReservaDeUsuario(Reserva* R){//Como la reserva se conecta al usuario primero, cuando hay que agregarlo al usuario ya tiene la data dentro de si misma. Amen.
    R->getUsuario()->agregarReserva(R);
}
void UsuarioHandler::agregarComentarioDeUsuario(Comentario* C){
    C->getUsuario()->agregarComentario(C);
}
bool UsuarioHandler::chequearCredencialesUsuario(std::string nickname , std::string contrasenia){
    Usuario* usuario = usuarios.find(nickname)->second;
    if(usuarios.find(nickname) != usuarios.end()){
        return usuario->verificarCredenciales(contrasenia);
    }
    else{
        throw std::invalid_argument("No existe el usuario, cancele la operacion.");
    }
}
//void UsuarioHandler::asociarReservaAUsuario(Reserva* R , std::string nickname){

//}