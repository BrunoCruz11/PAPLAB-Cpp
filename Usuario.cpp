#include "Usuario.hpp"
#include "Comentario.hpp"

        Usuario::Usuario(std::string nickname , std::string contrasenia , bool esAdmin){
            this->nickname = nickname;
            this->contrasenia = contrasenia;
            this->admin = esAdmin;
        }
        Usuario::Usuario(std::string nickname , std::string contrasenia){
            this->nickname = nickname;
            this->contrasenia = contrasenia;
        }
        bool Usuario::esAdmin(){
            return this->admin;
        }
        Usuario::~Usuario(){}
        bool Usuario::verificarCredenciales(std::string contrasenia){
            return this->contrasenia == contrasenia;
        }
        void Usuario::agregarComentario(Comentario* C){
            comentarios.push_back(C);
        }
        void Usuario::setFoto(std::string url){
            this->urlFoto = url;
        }
        std::string Usuario::getNickname(){
            return this->nickname;
        }
        void Usuario::agregarReserva(Reserva* R){
            this->reservas.push_back(R);
        }