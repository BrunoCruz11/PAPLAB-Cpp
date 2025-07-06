#include "Debito.hpp"
#include "DtDebito.hpp"
#include <string>

using namespace std;

Debito::Debito(string banco, float costo, int cantEntradas, Funcion* f, Usuario* u) : Reserva(costo, cantEntradas, f, u){
    this->banco = banco;
}

        
string Debito::getBanco(){
    return this->banco;
}
DtReserva* Debito::getData(){
    DtReserva* ret = new DtDebito(this);
    return ret;
}

Debito::~Debito(){

}