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
    DtPelicula(DtPelicula&);
    DtPelicula(string titulo,string sinopsis,string urlPoster);
    DtPelicula(std::string&, std::string&, float&, std::string&);
    DtPelicula(string titulo, string sinopsis, float puntajePromedio, std::vector<DtComentario> comentariosPelicula,string poster);
    DtPelicula(Pelicula& P);
    DtPelicula(Pelicula* P);
    DtPelicula(const DtPelicula& P); 
    DtPelicula();

    //Getters
    std::vector<DtComentario> getComentarios() const;
    string getMotivo()const;
    string getTitulo()const;
    string getSinopsis()const;
    string getPoster()const;
    float getPuntajePromedio()const;

};

#endif
