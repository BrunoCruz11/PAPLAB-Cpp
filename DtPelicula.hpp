#ifndef DTPELICULA_HPP
#define DTPELICULA_HPP

#include <string>
#include "Pelicula.hpp"
using namespace std;

class DtPelicula{
private:
    string titulo;
    string sinopsis;
    float puntajePromedio;
    std::vector<DtComentario> comentariosPelicula;
    string poster;
public:
    //Constructores
    DtPelicula(string titulo, string sinopsis, float puntajePromedio, std::vector<DtComentario> comentariosPelicula,string poster);
    DtPelicula(Pelicula& P);
    DtPelicula(Pelicula* P);
    DtPelicula(DtPelicula& P); 
    DtPelicula();

    //Getters
    std::vector<DtComentario> getComentarios();
    string getMotivo()const;
    string getTitulo()const;
    string getSinopsis()const;
    string getPoster()const;
    float getPuntajePromedio()const;

};

#endif
