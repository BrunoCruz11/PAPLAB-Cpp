#ifndef SALA_HPP
#define SALA_HPP

#include <map>
#include "Funcion.hpp"
#include "DtFuncion.hpp"
#include "TipoReserva.hpp"

class Sala{
    private:
    int id;
    int capacidad;
    std::map<int,Funcion*> funciones;
    public:
    Sala(int id , int capacidad);
    Sala(const Sala& S);
    ~Sala();
//getters
    int getId() const;
    int getCapacidad() const;
    std::vector<DtFuncion> getDataFunciones();
    std::map<int , Funcion*> getFunciones() const;
//Funciones de DCD
    bool checkDisponibilidad(DtFecha fecha,  DtHorario horario);
    void asociarPeliYFuncion(Pelicula* p , int idFuncion);
    void crearFuncion(int id, DtFecha fecha , DtHorario horario, Pelicula* P);
    DtFuncion getFuncion(int idFuncion);
    bool comprobarEspacioEnFuncion(int asientos, int funcionRecordada);
    bool tieneFuncion(int idFuncion);
    Reserva* agregarReserva(int idFuncion,TipoReserva metodoDePago, std::string dataTarjeta ,float costo,int cantEntradas,Usuario* u , float descuento);
    std::vector<DtFuncion> listarFunciones();
    void removerPeliDeFunciones(std::string tituloP);
};

#endif