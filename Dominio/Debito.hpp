#ifndef DEBITO_HPP
#define DEBITO_HPP
#include <string>
#include "Reserva.hpp"
class Debito : public Reserva{
    private:
        std::string banco; //banco que emitio la tarjeta
    public:
    //constructores y destructor
        Debito(std::string banco, float costo, int cantEntradas, Funcion* f, Usuario* u);
        ~Debito();

    //getters
        std::string getBanco();
        DtReserva* getData();
};

#endif