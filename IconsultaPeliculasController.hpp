#ifndef ICONSULTAPELICULASCONTROLLER_HPP
#define ICONSULTAPELICULASCONTROLLER_HPP



class IconsultaPeliculaController{
    private:



    public:
      virtual std::vector<DtFuncion> listarFuncionesConSusReservas()= 0;
      virtual void finVerReservas()= 0;
      virtual void eligePelicula(string tiulo)= 0;
      virtual std::vector<DtPelicula> listarPeliculas()= 0;
      virtual void terminarInfoPelicula()= 0;
      virtual void mostrarPosterYSipnosis()= 0;
      virtual std::vector<DtFuncion> listarFuncionesPosteriores(int nroCine, string titulo)= 0;
      virtual void confirmarVerPunYCom()= 0;
      virtual std::vector<> listarPuntajeYComentarios()= 0;

}