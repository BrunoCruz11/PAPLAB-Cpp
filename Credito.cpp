#include "Credito.hpp"
#include "DtCredito.hpp"
#include <string>
using namespace std;

Credito::Credito(string financiera, float porcentajeDescuento, float costo, int cantEntradas, Funcion* f, Usuario* u) : Reserva(costo, cantEntradas, f, u){
    this->financiera = financiera;
    this->porcentajeDescuento = porcentajeDescuento;
}

string Credito::getFinanciera(){
    return this->financiera;
}

float Credito::calcularDescuento(std::string financiera){ //segun la financiera, calcular el descuento correspondiente
    //completar funcion luego, no encontre en la letra sobre en que se basa para hacer el descuento
}
DtReserva* Credito::getData(){
    DtReserva* ret = new DtCredito(this);
    return ret;
}


float Credito::getPorcentajeDescuento(){
    return this->porcentajeDescuento;
}

Credito::~Credito(){

}