#ifndef CINE_HPP
#define CINE_HPP

#include <vector>
#include <string>
#include <map>

#include "DtSala.hpp"
#include "Pelicula.hpp"
#include "DtFuncion.hpp"
#include "Sala.hpp"
#include "TipoReserva.hpp"
#include "DtFecha.hpp"

class Cine{
    private:
        int id; 
        std::string direccion;
        std::vector<DtSala> salasRecordadas;
        DtSala salaRecordada;
        std::map<std::string , Pelicula*> peliculas;
        std::map<int , Sala*> salas;
    public:
        Cine(int id , std::string direccion);
        ~Cine();
        int getId();
        std::string getDireccion();
        DtFuncion getFuncion(int id);
        DtSala getSala(int id);
        Sala* darSala(int id);
        Sala* getSalaConFuncion(int idFuncion);
        Pelicula* getPelicula(std::string titulo);
        std::map<std::string,Pelicula*>& getTodasLasPelis();
        std::map<int, Sala*>& getTodasLasSalas();


        std::vector<DtSala> listarSalas();
        std::vector<DtFuncion> listarFunciones();
        std::vector<DtFuncion> listarFuncionesConSusReservas(); // Realmente se precisa? DtFuncion siempre tiene las reservas. Deberiamos hacer Dts sin reservas en listarFunciones()?
        std::vector<DtFuncion> buscarFuncionesPosteriores(std::string titulo , DtFecha fechaActual , DtHorario horaActual);
        

        void agregarSala(Sala* S);
        void agregarFuncion(Pelicula* P, DtSala S , DtFecha F,DtHorario H , int idFuncion);
        Reserva* agregarReserva(int idFuncion, TipoReserva metodoPago ,std::string dataTarjeta, float costo , int cantEntradas , Usuario* U);

        void removerPelicula(std::string titulo);
        void removerPeliculaDeFuncion(std::string titulo);

        bool tieneSala(int id);
        bool tieneFuncion(int id);
        bool estaDisponibleHorarioEnSala(DtFecha f , DtHorario horario); //inclui DtFecha asi deja de decir que no esta definido
        bool tienePelicula(std::string titulo);
        bool tieneFuncionAsientosDisponibles(int asientos, int id);

        void agregarPelicula(Pelicula* P);
    };


#endif