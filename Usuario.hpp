#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>

#include "Puntaje.hpp"
class Reserva;
class Comentario;

class Usuario{
    private:
        std::string nickname;
        std::string contrasenia;
        std::string urlFoto;
        bool admin;
        std::vector<Comentario*> comentarios;
        std::vector<Puntaje*> puntuaciones;
        std::vector<Reserva*> reservas;

    public:
        Usuario(std::string nickname , std::string contrasenia);
        Usuario(std::string nickname , std::string contrasenia , bool esAdmin);
        ~Usuario();
        bool verificarCredenciales(std::string contrasenia);//Devuelve true si la contrasenia pasada es igual a la del usuario.
        bool esAdmin();
        void agregarComentario(Comentario* C);
        void agregarReserva(Reserva*);
        void setFoto(std::string url);
        std::string getNickname();

        void eliminarReservasDePelicula(std::string titulo);
        

};




#endif