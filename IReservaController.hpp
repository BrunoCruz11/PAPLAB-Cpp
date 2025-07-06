#ifndef IRESERVA_HPP
#define IRESERVA_HPP
#include "PeliculaHandler.hpp"
#include <string>
class IReservaController{
    private:

    public:
        //metodos que aparecian en la parte de los controladores
        
        virtual std::vector <DtCine> listarCinesdePelicula(DtPelicula d) = 0; //lista cines en base a una pelicula
        virtual std::vector <DtFuncion> listarFuncionDeCine(int IdCine) = 0; //lista funciones en base a un cine
        virtual DtFuncion seleccionFuncion(int IdFuncion) = 0; //selecciona una funcion con un titulo de pelicula dado
        virtual void ingreseNomBanco(std::string nombre) = 0;
        virtual void ingreseNomFinanciera(std::string financiera) = 0;
        virtual float descuentoDe(DtCredito c) = 0;
        virtual float precioFinal(float Descuento, int CantEntradas) = 0;
        virtual void confirmarCompra() = 0;
        virtual void cancelaCompra() = 0;
};
#endif