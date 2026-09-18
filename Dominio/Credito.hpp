#ifndef CREDITO_HPP
#define CREDITO_HPP
#include <string>
#include "Reserva.hpp"
class Credito : public Reserva{
    private:
        std::string financiera;
        float porcentajeDescuento;
    public:
        Credito(std::string financiera, float costo, int cantEntradas, Funcion* f, Usuario* u);

        float calcularDescuento(std::string financiera); //segun la financiera, calcular el descuento correspondiente
        DtReserva* getData();
        std::string getFinanciera();
        float getPorcentajeDescuento();

        ~Credito();
};

#endif