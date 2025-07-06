#include "ConsultaPeliculaController.hpp"

std::vector<DtFuncion> ConsultaPeliculaController::listarFuncionesConSusReservas(){
    return manejadorCine->listarFuncionesConSusReservas(); //hacer funcion en CineHandler
}

void ConsultaPeliculaController::finVerReservas(){
    this->recordarFunciones = DtFuncion(); // que reserva guardas de atributo??? es al pedo me parece
}

DtPelicula ConsultaPeliculaController::eligePelicula(string titulo){
    return this->manejadorPeliculas->eligePelicula(titulo);
}

std::vector<DtPelicula> ConsultaPeliculaController::listarPelicula(){
    
    return manejadorPeliculas.listarPeliculas();
}

void ConsultaPeliculaController::terminarInfoPelicula(){
     recordarFunciones = DtFuncion(); // me parece al pedo que se recuerden funciones
     peliculaRecordada = DtPelicula();// usas contructores por defecto para resetear los atributos

}
void ConsultaPeliculaController::mostrarPosterYSipnosis(string titulo){
    manejadorPeliculas.obtenerPosterYSinopsis(titulo);
}

std::vector<DtFuncion> ConsultaPeliculaController::listarFuncionesPosteriores(int nroCine, string titulo){
        manejadorPelicula.darFuncionesPosteriores(nroCine,titulo);

}

void ConsultaPeliculaController::confirmarVerPunYCom(){
    peliculaRecordada = DtPelicula();

}


