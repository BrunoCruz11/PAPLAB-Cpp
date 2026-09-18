#ifndef IRESERVA_HPP
#define IRESERVA_HPP
#include "PeliculaHandler.hpp"
#include <string>
#include "DtCine.hpp"
#include "DtCredito.hpp"
class IReservaController{
    private:

    public:
        //metodos que aparecian en la parte de los controladores
        
        virtual std::vector <DtCine> listarCinesdePelicula(string p) = 0; //lista cines en base a una pelicula
        virtual std::vector <DtFuncion> listarFuncionDeCine(int IdCine) = 0; //lista funciones en base a un cine
        virtual void seleccionaFuncion(int IdFuncion) = 0; //selecciona una funcion con un titulo de pelicula dado
        virtual void ingreseNomBanco(std::string nombre) = 0;
        virtual void ingreseNomFinanciera(std::string financiera) = 0;
        virtual float descuentoDe(string nombreFinanciera) = 0;
        virtual float precioFinal(float Descuento, int CantEntradas) = 0;
        virtual void confirmarCompra(Usuario* u , TipoReserva tipo , int costo , int cantAsientos ) = 0;
        virtual void cancelaCompra() = 0;

        virtual vector<DtPelicula>listarPeliculas() = 0;
        virtual bool ComprobarLugarDeAsientos(int cantAsientos,int idFuncion)=0;

        virtual ~IReservaController() = default;
        virtual DtPelicula eligePelicula(string titulo) = 0;
        virtual void eligeCine(int id) = 0;
    };
#endif