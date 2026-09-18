#ifndef COMENTARIOPUNTAJECONTROLLER_HPP
#define COMENTARIOPUNTAJECONTROLLER_HPP
#include "IComentarioPuntajeController.hpp"
#include <string>
#include <vector>
#include "DtPelicula.hpp"

class ComentarioPuntajeController{
    private:
        DtPelicula peliculaRecordada
        std::vector <string> comentarios;
        float nuevoPuntaje;
        std::vector <string> respuestas;
    public:
        DtPelicula eligePelicula(string titulo);
        std::vector <DtPelicula> listarPeliculas();
        float mostrarPuntaje();
        void Puntuar (float puntuacion);
        void confirmarPuntuacion();
        //----------------------------------------------------------------------------------- separo caso de uso
        std::vector <string>ComentarPelicula(string texto);
        DtComentario recordarComentario(string texto);
        std::vector <DtComentario> mostrarComentarios();
        void seleccionarComentario(DtComentario comentario);
        std::vector <string> comentarComentario(string texto);
        DtComentario recordarRespuesta(string texto);
        void ConfirmarComentario();
        void ConfirmarRespuesta();
};


        