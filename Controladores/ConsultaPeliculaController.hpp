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
      void mostrarPosterYSipnosis(string titulo);
      std::vector<DtFuncion> listarFuncionesPosteriores(int nroCine, string titulo);
      //----------------------------------------------------------------------------------- separo caso de uso
      void confirmarVerPunYCom();
      std::vector<DtComentario> listarPuntajeYComentarios();
      //----------------------------------------------------------------------------------- separo caso de uso
      //--------------------------------------------------------------------------------- separo caso de uso
      std::vector<DtFuncion> listarFuncionesConSusReservas(string titulo);

};


#endif