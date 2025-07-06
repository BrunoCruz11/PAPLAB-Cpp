#ifndef PELICULAHANDLER_HPP
#define PELICULAHANDLER_HPP
#include <vector>
#include <map>
#include "Comentario.hpp"
#include "Puntaje.hpp"
#include "DtPelicula.hpp"
#include <string>
#include <map>


class PeliculaHandler{
    private:
        static PeliculaHandler* instancia;
        PeliculaHandler();
        ~PeliculaHandler();
        std::map<std::string,Pelicula*> peliculas;
        vector <DtPelicula> recordarPeliculas;
        DtPelicula pelicularecordada;

    public:
        void agregarPelicula(DtPelicula P);
        bool existePelicula(std::string titulo);

        static PeliculaHandler* getInstancia();
        std::vector <DtPelicula> darPeliculas(); // esto puede ir al manejador
        void recordarPelicula(std::string titulo);  // esto puede ir al manejador re
        DtPelicula getPelicula(std::string titulo); // Me gustaria llamarla getPelicularecodada pero no lo quiero cambiar porque tengo miedo de cagarla
        float getPuntajePromedioPelicula(std::string titulo);
        Puntaje* crearPuntaje(float puntuacion);
        void ponerPuntaje(Puntaje puntaje,Usuario* u);
        std::vector <DtComentario> darComentariosPelicula(std::string titulo);
        Comentario* agregarComentarioAPeli(DtComentario comentario, Usuario* u);
        Comentario* agregarRespuestaAComentario(DtComentario comentario, Usuario* u);
        DtPelicula obtenerPosterYSinopsis(std::string titulo);
        std::vector <DtPelicula> listarPuntajeYComentarios();

        Pelicula* darPelicula(std::string titulo);

};

#endif