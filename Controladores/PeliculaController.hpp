#ifndef PELICULACONTROLLER_HPP
#define PELICULACONTROLLER_HPP
#include "IPeliculaController.hpp"
#include "PeliculaHandler.hpp"
#include "IPeliculaController.hpp"
#include <vector>
#include <string>

class PeliculaController : public IPeliculaController{
    private:
        static PeliculaController* instancia;
        PeliculaController();
        DtPelicula PeliculaRecordada;
        std::vector <DtPelicula> peliculasRecordadas;
        PeliculaHandler* manejadorpeli;
    public:
        static PeliculaController* getInstancia();
        void agregarPelicula(std::string titulo, std::string sipnosis, std::string urlPoster);
        void confirmarAltaPelicula();
        std::vector <DtPelicula> listarPeliculas();
        DtPelicula eligePelicula(std::string titulo);
        void borrarPelicula();
        void cancelarEliminarPelicula();
        DtPelicula obtenerPosterSipnosisDeLaPelicula(std::string titulo);
        ~PeliculaController();

};


#endif
