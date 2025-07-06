#ifndef RESERVAHANDLER_HPP
#define RESERVAHANDLER_HPP

#include <vector>
#include <string>
#include "Pelicula.hpp"
#include "Funcion.hpp"
#include "DtPelicula.hpp"
#include "DtCine.hpp"
#include "DtCredito.hpp"
#include "PeliculaHandler.hpp"
#include "CineHandler.hpp"
#include "Reserva.hpp"
#include "Sala.hpp"

class ReservaHandler{
    private:
        static ReservaHandler *instancia;
        Reserva *ReservaRecordada; //hacer getter
        ReservaHandler();
    public:
        static ReservaHandler* getInstancia();

        Reserva *getReservaRecordada();
        std::vector <DtCine> darCinesDePelicula(vector <DtCine> coleccioncines, DtPelicula P);
        //std::vector <DtReserva> obtenerReservas(); //lista las reservas realizadas por el usuario
        void agregarReserva(int cantentradas, float costo, Usuario* u, Funcion* f);
        void eliminarReserva();
        bool HayAsientos(Funcion* f);
        Reserva* crearReserva(float costo, int cantEntradas, Funcion* f, Usuario* u); //llama constructor de Reserva
};

#endif