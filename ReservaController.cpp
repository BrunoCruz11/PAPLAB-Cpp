#include "ReservaController.hpp"
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;


ReservaController::ReservaController(){

}

ReservaController::~ReservaController(){

}

ReservaController* ReservaController::getInstancia(){
    if(instancia == nullptr){
        instancia = new ReservaController();
    }
    return instancia;
}

vector <DtCine> ReservaController::listarCinesdePelicula(DtPelicula P){  
    return ManejadorCine->darCinesDePelicula(p); 
}
        
vector <DtFuncion> ReservaController::listarFuncionDeCine(int IdCine){
   return ManejadorCine->darFuncionesCine(IdCine);
} 

DtFuncion ReservaController::seleccionaFuncion(int IdFuncion){ //selecciona una funcion con un IdFuncion dado
   return ManejadorCine->darDataFuncion(idFuncion);
}

bool ComprobarLugarDeAsientos(int asientos, int idFuncion){
    return ManejadorCine->hayAsientosDisponiblesEnFuncion(asientos);
}

void ReservaController::ingreseNomBanco(string banco){
    this->BanOFin = banco;
} //setea el nombanco en BanOFin

void ReservaController::ingreseNomFinanciera(string financiera){
    this->BanOFin = financiera;
} //setea el nomfinanciera en BanOFin

float ReservaController::descuentoDe(DtCredito c){
    Descuentos aux;
    return aux.getDescuento(BanOFin);  
}

float ReservaController::precioFinal(float Descuento, int CantEntradas){
    return cantEntradas*200*(Descuento/100);
}

std::vector<DtPelicula> listarPeliculas(){
    manejadorPelicula->darPeliculas();
}


void eligeCine(int id){
    DtCine CineAPoner = manejadorCine->getCine(id);
    cinesRecordados.push_back(CineAPoner);
}

void ReservaController::confirmarCompra(){
    Reserva* r = this->ManejadorReserva->getReservaRecordada(); //encuentro la reserva recordada dentro del manejador
    ReservaController::getInstancia()->ManejadorReserva->agregarReserva(r->getCantEntradas(), r->getCosto(), r->getUsuario(), r->getFuncion()); //llamo a agregar reserva que hace el new (llama constructor) y hace el push_back
}


//la funcion de arriba no tiene sentido la hice cansado

void ReservaController::cancelaCompra(){
    Reserva* r = this->ManejadorReserva->getReservaRecordada();
    if (r != nullptr) {
        delete r; // libera la memoria
        this->ManejadorReserva->eliminarReserva(); // borramos tambien del handler
    }
}    