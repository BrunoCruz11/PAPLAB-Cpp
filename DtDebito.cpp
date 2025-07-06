#include "DtDebito.hpp"
#include <string>

using namespace std;

DtDebito::DtDebito(string banco, float costo, int cantEntradas, Funcion* f, Usuario* u) : DtReserva(costo, cantEntradas, f, u){
    this->banco = banco;
}
DtDebito::DtDebito(Debito* D) : DtReserva(D){//No se si funcionara esto, le rezo a todos los dioses peruanos.
    this->banco = D->getBanco();
}

        
string DtDebito::getBanco(){
    return this->banco;
}

DtDebito::~DtDebito(){

}