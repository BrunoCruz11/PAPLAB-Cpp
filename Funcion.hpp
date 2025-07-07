#ifndef FUNCION_HPP
#define FUNCION_HPP

#include <string>
#include <vector>

class Sala;
#include "Pelicula.hpp"
#include "DtFuncion.hpp"
#include "Reserva.hpp"
#include "DtFecha.hpp"
#include "Fecha.hpp"
#include "Horario.hpp"
#include "DtHorario.hpp"

class Funcion{
    private:
        int id;
        Fecha dia;
        Horario horario;
        std::vector <Reserva*> reservas;
        Sala* sala;
        Pelicula* pelicula;        
        
    public:
        ~Funcion();
        Funcion(int id, DtFecha dia, DtHorario horario);
        Funcion(int id, DtFecha dia, DtHorario horario, Pelicula* P , Sala* S);

        int getId();
        Horario getHorario();
        Sala* getSala();
        Pelicula* getPelicula();
        vector <Reserva*> getReservas();

        bool seSuperpone(DtFecha f, DtHorario horario);
        void setSala(Sala* s);
        void setPelicula(Pelicula* p);
        DtFuncion getData();
        bool hayAsientosDisponibles(int asientos);
        Reserva* CrearReservaDebito(std::string dataTarjeta,  float costo, int cantEntradas, Usuario* u);//Debito
        Reserva* CrearReservaCredito(std::string dataTarjeta,  float costo, int cantEntradas, Usuario* u);//Credito(Tiene en cuenta descuentos)
        bool chekPelicula(std::string titulo);
        std::vector<DtReserva*> listarReservas();
        std::string getTituloPeli();
        void olvidarPeli();
        bool esPosterior(DtFecha , DtHorario);
        

};

#endif