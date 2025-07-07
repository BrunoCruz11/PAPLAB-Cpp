#include "ReservaController.hpp"
#include <vector>
#include <string>
#include "Descuentos.hpp"
#include <stdexcept>

using namespace std;


ReservaController::ReservaController(){
ManejadorCine = CineHandler::getInstancia();
ManejadorPelicula = PeliculaHandler::getInstancia();
}

ReservaController::~ReservaController(){

}

ReservaController* ReservaController::getInstancia(){
    if(instancia == nullptr){
        instancia = new ReservaController();
    }
    return instancia;
}

vector <DtCine> ReservaController::listarCinesdePelicula(string p){  
    return ManejadorCine->darCinesDePelicula(p); 
}
        
vector <DtFuncion> ReservaController::listarFuncionDeCine(int IdCine){
   return ManejadorCine->darFuncionesDeCine(IdCine);
} 

void ReservaController::seleccionaFuncion(int IdFuncion){ //selecciona una funcion con un IdFuncion dado
   funcionRecordada = IdFuncion;
}

bool ReservaController::ComprobarLugarDeAsientos(int asientos, int idFuncion){
    return ManejadorCine->hayAsientosDisponiblesEnFuncion(asientos, idFuncion);
}

void ReservaController::ingreseNomBanco(string banco){
    this->BanOFin = banco;
} //setea el nombanco en BanOFin

void ReservaController::ingreseNomFinanciera(string financiera){
    this->BanOFin = financiera;
} //setea el nomfinanciera en BanOFin

float ReservaController::descuentoDe(string nombreFinanciera){
    Descuentos aux;
    return aux.getDescuento(BanOFin);  
}

float ReservaController::precioFinal(float Descuento, int CantEntradas){
    return CantEntradas*200*(Descuento/100);
}

std::vector<DtPelicula> ReservaController::listarPeliculas(){
    return ManejadorPelicula->darPeliculas();
}


void ReservaController::eligeCine(int id){
    DtCine CineAPoner = ManejadorCine->getCine(id);
    cineRecordado = CineAPoner.getId();
}
DtPelicula ReservaController::eligePelicula(string titulo){
    this->peliculaRecordada = titulo;
    return ManejadorPelicula->getPelicula(titulo);
}
void ReservaController::confirmarCompra(Usuario* u , TipoReserva tipo , int costo , int cantAsientos ){
    Reserva* nuevaReserva = ManejadorCine->colocarReserva(funcionRecordada , tipo , BanOFin , costo , cantAsientos, u );
    ManejadorUsuario->asociarReservaAUsuario(nuevaReserva);

}



void ReservaController::cancelaCompra(){
    
}    