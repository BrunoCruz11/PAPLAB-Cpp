#ifndef ICOMENTARIOPUNTAJECONTROLLER_HPP
#define ICOMENTARIOPUNTAJECONTROLLER_HPP


class IComentarioPuntajeController{
    Private:
    
    public:
        Virtual DtPelicula eligePelicula(string titulo)= 0:
        Virtual std::vector <DtPelicula> listarPeliculas()= 0:
        Virtual float mostrarPuntaje()= 0:
        Virtual void Puntuar (float puntuacion)= 0:
        Virtual void confirmarPuntuacion()= 0:
        //----------------------------------------------------------------------------------- separo caso de uso
        Virtual std::vector <string>ComentarPelicula(string texto)= 0:
        Virtual DtComentario recordarComentario(string texto)= 0:
        Virtual std::vector <DtComentario> mostrarComentarios()= 0:
        Virtual void seleccionarComentario(DtComentario comentario)= 0:
        Virtual std::vector <string> comentarComentario(string texto)= 0:
        Virtual DtComentario recordarRespuesta(string texto)= 0:
        Virtual ConfirmarComentario()= 0:
        Virtual ConfirmarRespuesta()= 0:
}

#endif
