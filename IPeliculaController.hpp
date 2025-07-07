#ifndef IPELICULACONTROLLER_HPP
#define IPELICULACONTROLLER_HPP
#include "DtPelicula.hpp"
class IPeliculaController{
    private:
    

    public:
        virtual void agregarPelicula(std::string titulo, std::string sipnosis, std::string urlPoster)= 0;
        virtual void confirmarAltaPelicula()= 0;
        virtual std::vector <DtPelicula> listarPeliculas()= 0;
        virtual DtPelicula eligePelicula(std::string titulo)= 0;
        virtual void borrarPelicula()= 0;
        virtual void cancelarEliminarPelicula()= 0;
        //virtual void DtPelicula obtenerPosterSipnosisDeLaPelicula(std::string titulo)= 0;

};



#endif