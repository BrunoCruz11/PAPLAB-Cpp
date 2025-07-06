#ifndef USUARIOHANDLER_HPP
#define USUARIOHANDLER_HPP
#include<map>
#include<string>
#include "Usuario.hpp"
#include "Reserva.hpp"
class UsuarioHandler{
    private:
        std::map<std::string , Usuario*> usuarios;
        static UsuarioHandler* instancia;
        UsuarioHandler();
        ~UsuarioHandler();
    public:
        static UsuarioHandler* getInstancia();
        Usuario* getUsuario(std::string nicknameUsuario);//No se si se precisa.
        void agregarUsuario(std::string nickname , std::string contrasenia);
        void agregarUsuario(std::string nickname , std::string contrasenia , std::string urlFoto);

        void setReservaDeUsuario(Reserva* R);
        void agregarComentarioDeUsuario(Comentario* C);
        void asociarReservaAUsuario(Reserva* R);

        bool chequearCredencialesUsuario(std::string nickname , std::string contrasenia); //Devuelve true si el usuario del nickname dado tiene esa contrasenia.
    };

#endif