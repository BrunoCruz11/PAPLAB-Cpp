#ifndef DTCREDITO_HPP
#define DTCREDITO_HPP

#include "DtReserva.hpp"
#include <string>
class Credito;

class DtCredito : public DtReserva{
    private:
        std::string financiera;
        float porcentajeDescuento;
    public:
        DtCredito(std::string financiera, float porcentajeDescuento, float costo, int cantEntradas, Funcion* f, Usuario* u);
        DtCredito(Credito* C);
        std::string getFinanciera();
        float getPorcentajeDescuento();

        ~DtCredito();
};

#endif