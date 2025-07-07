#ifndef PELICULA_HPP
#define PELICULA_HPP
#include <string>
#include <vector>

#include "Puntaje.hpp"
#include "DtPuntaje.hpp"
#include "Comentario.hpp"
#include "DtComentario.hpp"
class DtPelicula;

class Pelicula{
    private:
        std::string titulo;
        std::string sinopsis;
        std::string poster;
        std::vector <Puntaje*> puntajes;
        std::vector <Comentario*> comentarios;
    public:
        Pelicula(std::string titulo, std::string sinopsis, std::string poster);
        Pelicula(Pelicula& p);
        Pelicula(DtPelicula p);
        ~Pelicula();
        bool esTitulo( std::string titulo);
        std::string getTitulo();
        float getPuntajePromedio();
        Puntaje* setPuntaje (float puntaje, Usuario* s); //Crea un puntaje nuevo, lo guarda en puntajes y devuelve el puntero al puntaje recien creado
        std::vector <DtComentario> getComentarios();
        Comentario* agregarComentario(std::string texto , Usuario* U);
        std::vector<DtPuntaje> getPuntajes();
        std::string getPoster();
        std::string getSinopsis();
        DtPelicula getPunYCom();
        //DtFuncion listrarFuncionesPosteriores(string titulo); 
        //DtPunYCom getPunYCom();

};




#endif