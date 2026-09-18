#ifndef ICONSULTAPELICULASCONTROLLER_HPP
#define ICONSULTAPELICULASCONTROLLER_HPP

#include <vector>
#include <string>
#include "DtFuncion.hpp"
#include "DtPelicula.hpp"
#include "DtComentario.hpp"

class IconsultaPeliculaController{
    private:



    public:
      virtual std::vector<DtFuncion> listarFuncionesConSusReservas()= 0;
      virtual void finVerReservas()= 0;
      virtual void eligePelicula(std::string tiulo)= 0;
      virtual std::vector<DtPelicula> listarPeliculas()= 0;
      virtual void terminarInfoPelicula()= 0;
      virtual void mostrarPosterYSipnosis()= 0;
      virtual std::vector<DtFuncion> listarFuncionesPosteriores(int nroCine, std::string titulo)= 0;
      virtual void confirmarVerPunYCom()= 0;
      virtual std::vector<DtComentario> listarPuntajeYComentarios()= 0;

};

#endif