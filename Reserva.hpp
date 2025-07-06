#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "Usuario.hpp"
#include "DtReserva.hpp"
class Funcion;


class Reserva{
    private: 
        float costo;
        int cantEntradas;
        Funcion* funcion;
        Usuario* usuario;

    public:
        Reserva(float costo, int cantEntradas, Funcion* f, Usuario* u);
        int getCantEntradas(); 
        float getCosto();
        void setFuncion(Funcion* f);
        void setUsuario(Usuario* u);
        virtual DtReserva* getData() = 0; //getData deberia implementarse diferente para debito y credito.
        Usuario* getUsuario();
        Funcion* getFuncion();

        virtual ~Reserva();
};



#endif