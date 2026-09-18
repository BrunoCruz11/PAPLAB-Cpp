#ifndef DTCOMENTARIO_HPP
#define DTCOMENTARIO_HPP

#include <vector>
#include <string>

class Usuario; //evita las dependencias circulares que causaria hacer el include
class Pelicula;
//class Comentario;
#include "Comentario.hpp"
class DtComentario{
    private:
        std::string texto;
        std::string nicknameUsuario;
        std::string tituloP;
        DtComentario* respondeA;//Se necesita que sea un puntero para que pueda ser null, lo que es raro, pero bueno, evita problemas.
        std::vector <DtComentario> respuestas; 
    public:
        //Constructores
        DtComentario();
        DtComentario(std::string t, std::string nnu, std::string tituloP); //constructor por parametros
        DtComentario(std::string t, std::string nnu, DtComentario* respondeA); //Constructor para cuando es respuesta.
        DtComentario(const DtComentario &C); //Constructor de copia
        DtComentario(Comentario* C); //Construir DtComentario a partir de Comentario
        //getters
        std::string getTexto() const;
        std::string getNicknameUsuario() const;
        std::string getTituloP() const;
        std::vector<DtComentario> getRespuestas() const;
};

#endif