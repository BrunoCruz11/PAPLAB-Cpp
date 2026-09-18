#include "ConsultaPeliculaController.hpp"

std::vector<DtFuncion> ConsultaPeliculaController::listarFuncionesConSusReservas(){
    return std::vector<DtFuncion>(); //TODO: falta exponer un metodo en CineController que llegue a CineHandler::listarFuncionesConSusReservasCineHandler
}

void ConsultaPeliculaController::finVerReservas(){
    this->recordarFunciones = DtFuncion(); // que reserva guardas de atributo??? es al pedo me parece
}

DtPelicula ConsultaPeliculaController::eligePelicula(string titulo){
    return this->manejadorPeliculas->eligePelicula(titulo);
}

std::vector<DtPelicula> ConsultaPeliculaController::listarPeliculas(){

    return manejadorPeliculas->listarPeliculas();
}

void ConsultaPeliculaController::terminarInfoPelicula(){
     recordarFunciones = DtFuncion(); // me parece al pedo que se recuerden funciones
     peliculaRecordada = DtPelicula();// usas contructores por defecto para resetear los atributos

}
void ConsultaPeliculaController::mostrarPosterYSipnosis(string titulo){
    manejadorPeliculas->obtenerPosterSipnosisDeLaPelicula(titulo);
}

std::vector<DtFuncion> ConsultaPeliculaController::listarFuncionesPosteriores(int nroCine, string titulo){
        return std::vector<DtFuncion>(); //TODO: falta exponer este caso de uso (manejadorPelicula/darFuncionesPosteriores no existen en esta clase)
}

void ConsultaPeliculaController::confirmarVerPunYCom(){
    peliculaRecordada = DtPelicula();

}

std::vector<DtComentario> ConsultaPeliculaController::listarPuntajeYComentarios(){
    return std::vector<DtComentario>(); //TODO: falta implementar
}

std::vector<DtFuncion> ConsultaPeliculaController::listarFuncionesConSusReservas(string titulo){
    return std::vector<DtFuncion>(); //TODO: falta exponer un metodo en CineController que llegue a CineHandler::listarFuncionesConSusReservasCineHandler
}

