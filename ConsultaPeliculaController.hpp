#ifndef CONSULTAPELICULACONTROLLER_HPP
#define CONSULTAPELICULACONTROLLER_HPP
#include "IConsultaPeliculasController.hpp"
#include <string>
#include <vector>
#include "PeliculaController.hpp"
#include "CineController.hpp"
class ConsultaPeliculaController{
    private:
        DtFuncion recordarFunciones; // creo que es alpedo
        DtPelicula peliculaRecordada;
        PeliculaController* manejadorPeliculas;
        CineController* manejadorCine; 
    public: 
      std::vector<DtFuncion> listarFuncionesConSusReservas();
      void finVerReservas();
       //----------------------------------------------------------------------------------- separo caso de uso
      DtPelicula eligePelicula(string tiulo);
      std::vector<DtPelicula> listarPeliculas();
      void terminarInfoPelicula();
      void mostrarPosterYSipnosis();
      std::vector<DtFuncion> listarFuncionesPosteriores(int nroCine, string titulo);
      //----------------------------------------------------------------------------------- separo caso de uso
      void confirmarVerPunYCom();
      std::vector<> listarPuntajeYComentarios();
}


#endif