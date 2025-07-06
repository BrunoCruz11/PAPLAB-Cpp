#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

class Pelicula;
class DtComentario;
#include "Usuario.hpp"
#include <string>
#include <vector>

class Comentario{
    private:
    std::string texto;
    Pelicula* pelicula;
    Comentario* respondeA;//Si es un comentario a una pelicula este atributo es NULL, sino refiere al comentario que responde.
    Usuario* usuario;
    std::vector <Comentario*> respuestas;

    public:
    Comentario(std::string T, Pelicula* P, Usuario* U); //No se le pasan respuestas pues el comentario esta recien hecho.
    Comentario(std::string T, Comentario* C, Usuario* U);
    Comentario(Comentario& c);
    ~Comentario();
    void agregarRespuesta(Comentario*);
    std::vector<DtComentario> getRespuestas();
    
    std::string getTexto();
    Pelicula* getPelicula();
    Comentario* getRespondeA();
    Usuario* getUsuario();
    std::string getNicknameUsuario();
    std::vector<Comentario*> getCopiaRespuestas();//Devuelve un vector copia del set de respuestas.

};






#endif