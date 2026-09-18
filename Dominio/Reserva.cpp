#include "Reserva.hpp"


        Reserva::Reserva(float costo, int cantEntradas, Funcion* f, Usuario* u){
            this->costo= costo;
            this->cantEntradas= cantEntradas;
            this->funcion= f;
            this->usuario= u;
        }
        Reserva::~Reserva(){}

        int Reserva::getCantEntradas(){
            return this->cantEntradas;
        }  // en realdiad es cantAsientos pero no me parece el nobmre


        float Reserva::getCosto(){
            return this->costo;
        }
        
        void Reserva::setFuncion(Funcion* F){
            this->funcion = F;
        }


        void Reserva::setUsuario(Usuario* U){
            this->usuario = U;
        }



        DtReserva* Reserva::getData(){
            return new DtReserva(this->getCosto(),this->getCantEntradas(), this->getFuncion(), this->getUsuario());
        }

        Usuario* Reserva::getUsuario(){
            return this->usuario;
        }


        Funcion* Reserva::getFuncion(){
            return this->funcion;
        }

