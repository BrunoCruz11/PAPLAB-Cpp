#ifndef DTRESERVA_HPP
#define DTRESERVA_HPP

#include "Usuario.hpp"

class Funcion;
class DtFuncion;
class Reserva;


class DtReserva{
    private: 
        float costo;
        int cantEntradas;
        DtFuncion* funcion; //Me pidio que sea puntero, y le hice caso. jiji. Es por tema del forward declaration
        std::string nickUsuario;

    public:
        DtReserva();
        DtReserva(float costo, int cantEntradas, Funcion* f, Usuario* u);
        DtReserva(Reserva* r);
        int getCantEntradas();
        float getCosto();
        std::string getUsuario();
        DtFuncion* getFuncion();

        virtual ~DtReserva(); 
};



#endif