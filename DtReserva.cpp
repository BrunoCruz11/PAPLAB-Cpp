#include "DtReserva.hpp"
#include "DtFuncion.hpp"
#include "Reserva.hpp"
#include "Usuario.hpp"

        DtReserva::DtReserva(){}
        DtReserva::~DtReserva(){}
        DtReserva::DtReserva(float costo, int cantEntradas, Funcion* f, Usuario* u){
            this->costo = costo;   
            this-> cantEntradas = cantEntradas;
            this->funcion = new DtFuncion(f);
            this-> nickUsuario = u->getNickname();    
        }
        DtReserva::DtReserva(Reserva* r){
            this->costo = r->getCosto();   
            this-> cantEntradas = r->getCantEntradas();
            this->funcion = new DtFuncion(r->getFuncion());
            this-> nickUsuario = r->getUsuario()->getNickname();    
        }
        int DtReserva::getCantEntradas(){
            return this->cantEntradas;
        }
        float DtReserva::getCosto(){
            return this->costo;
        }
        std::string DtReserva::getUsuario(){
            return this->nickUsuario;
        }
        DtFuncion* DtReserva::getFuncion(){
            return this->funcion;
        }