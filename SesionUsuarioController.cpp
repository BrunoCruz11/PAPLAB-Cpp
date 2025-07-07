#include "SesionUsuarioController.hpp"
#include <cstddef>
#include <stdexcept>

//Constructores y cosas singletonianas
SesionUsuarioController* SesionUsuarioController::instancia = NULL;

SesionUsuarioController::SesionUsuarioController(){
    this->usuarioActivo = NULL;
    this->UH = UsuarioHandler::getInstancia();
    this->urlRecordada = "";
}
SesionUsuarioController::~SesionUsuarioController(){}

SesionUsuarioController* SesionUsuarioController::getInstancia(){
    if(instancia== NULL){
        instancia = new SesionUsuarioController(); 
    }
    return instancia;
}

Usuario* SesionUsuarioController::getUsuarioActual(){
    if(this->usuarioActivo == NULL){
        throw std::invalid_argument("La sesion no esta iniciada.");
    }
    return this->usuarioActivo;
}

void SesionUsuarioController::setNicknameRecordado(std::string N){
    this->nicknameRecordado = N;
}
void SesionUsuarioController::setContraseniaRecordada(std::string C){
    this->contraseniaRecordada = C;
}
void SesionUsuarioController::ingresarNombreUsuario(std::string N){
    this->setNicknameRecordado(N);
}
void SesionUsuarioController::ingresarContraseniaUsuario(std::string C){
    this->setContraseniaRecordada(C);
}
void SesionUsuarioController::confirmarSesion(){
    if(UH->chequearCredencialesUsuario(nicknameRecordado, contraseniaRecordada)){
        this->usuarioActivo = this->UH->getUsuario(nicknameRecordado);
    }
    else{
        throw std::invalid_argument("Credenciales de usuario incorrectas.");
    }
}
void SesionUsuarioController::crearUsuario(std::string nickname , std::string contrasenia){
    this->setNicknameRecordado(nickname);
    this->setContraseniaRecordada(contrasenia); 
}
void SesionUsuarioController::agregarFoto(std::string urlFoto){
    this->UH->getUsuario(nicknameRecordado)->setFoto(urlFoto);
}
void SesionUsuarioController::confirmarAltaUsuario(){
    if(this->urlRecordada != ""){//Si se recordo una url se crea con foto.
        this->UH->agregarUsuario(nicknameRecordado, contraseniaRecordada, urlRecordada);
    }
    else{
         this->UH->agregarUsuario(nicknameRecordado, contraseniaRecordada);
    }
}
void SesionUsuarioController::cerrarSesion(){//Limpiar el controlador? Ta medio al pedo pero bueno. Se podria hacer todo de una en el confirmar.Pero pa respetar un poco los diagramas.
    if(this->usuarioActivo != NULL){
        this->nicknameRecordado = "";
        this->contraseniaRecordada = "";
        this->urlRecordada = "";
    }
    else{
        throw std::invalid_argument("No hay una sesion iniciada.");
    }
}
void SesionUsuarioController::confirmarCerrarSesion(){//Desvincular el usuario de la sesion.
    if(this->usuarioActivo != NULL){
        this->usuarioActivo = NULL;
    }
    else{
        throw std::invalid_argument("No hay una sesion iniciada.");
    }
}