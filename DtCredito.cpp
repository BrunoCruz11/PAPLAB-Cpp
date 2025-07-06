#include "DtCredito.hpp"
#include "Credito.hpp"
#include <string>
using namespace std;

DtCredito::DtCredito(string financiera, float porcentajeDescuento, float costo, int cantEntradas, Funcion* f, Usuario* u) : DtReserva(costo, cantEntradas, f, u){
    this->financiera = financiera;
    this->porcentajeDescuento = porcentajeDescuento;
}
DtCredito::DtCredito(Credito* C) : DtReserva(C){
    this->porcentajeDescuento = C->getPorcentajeDescuento();
    this->financiera = C->getFinanciera();
}
string DtCredito::getFinanciera(){
    return this->financiera;
}

float DtCredito::getPorcentajeDescuento(){
    return this->porcentajeDescuento;
}

DtCredito::~DtCredito(){

}