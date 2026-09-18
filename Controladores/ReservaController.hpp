#ifndef RESERVACONTROLLER_HPP
#define RESERVACONTROLLER_HPP

#include "IReservaController.hpp"
#include "ReservaHandler.hpp"
#include <vector>
#include <string>
#include "UsuarioHandler.hpp"
class ReservaController : public IReservaController{
    private:
        static ReservaController* instancia; //solo necesitamos un unico ReservaController, por eso el static
        ReservaController();
        std::string BanOFin; //probablemente haya que cambiar esto pero de mientras lo dejo asi (banco o financiera)
        std::vector <DtCine> CinesRecordados;
        std::vector <DtFuncion> FuncionesRecordadas;
        int funcionRecordada; //recuerda una funcion (usada en seleccionfuncion)
        float Precio; //seria preciofinal pero es para evitar usar el mismo nombre que el metodo
        //ReservaHandler* ManejadorReserva; //handler
        CineHandler* ManejadorCine;
        DtCine cinesRecordados;
        int cineRecordado;
        string peliculaRecordada;
        PeliculaHandler* ManejadorPelicula;
        UsuarioHandler* ManejadorUsuario;
    public:
        static ReservaController* getInstancia();

        std::vector <DtCine> listarCinesdePelicula(string p); //lista cines en base a una pelicula
        std::vector <DtFuncion> listarFuncionDeCine(int IdCine); //lista funciones en base a un cine
        void seleccionaFuncion(int IdFuncion); //selecciona una funcion con un IdFuncion dado
        bool ComprobarLugarDeAsientos(int asientos, int idFuncion);
        void ingreseNomBanco(std::string banco);
        void eligeCine(int id);
        void ingreseNomFinanciera(std::string financiera);
        float descuentoDe(string nombreFinanciera); //devuelve el porcentaje de descuento que tiene segun la tarjeta de credito
        float precioFinal(float Descuento, int CantEntradas);
        std::vector<DtPelicula> listarPeliculas();
        void confirmarCompra(Usuario* u , TipoReserva tipo , int costo , int cantAsientos );
        void cancelaCompra();
        ~ReservaController();
        DtPelicula eligePelicula(string titulo);
};

#endif