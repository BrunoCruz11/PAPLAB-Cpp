#ifndef DTDEBITO_HPP
#define DTDEBITO_HPP
#include <string>
#include "DtReserva.hpp"
#include "Debito.hpp"
class DtDebito : public DtReserva{
    private:
        std::string banco; //banco que emitio la tarjeta
    public:
    //constructores y destructor
        DtDebito(std::string banco, float costo, int cantEntradas, Funcion* f, Usuario* u);
        DtDebito(Debito* D);
        ~DtDebito();

    //getters
        std::string getBanco();
};

#endif