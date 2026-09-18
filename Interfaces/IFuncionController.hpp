#ifndef IFUNCIONCONTROLLER_HPP
#define IFUNCIONCONTROLLER_HPP
#include <vector>
#include "DtSala.hpp"
#include "DtPelicula.hpp"
#include "DtHorario.hpp"
#include "DtCine.hpp"
class IFuncionController{
    private:



    public: 
    virtual std::vector<DtPelicula> listarPeliculas()= 0;
    virtual void eligePelicula(string titulo)= 0;
    virtual std::vector<DtCine> listarCines()= 0;
    virtual void eligeCine(int id)= 0;
    virtual std::vector<DtSala> listarSalas()= 0;
    virtual void eligeSala(int id)= 0;
    //virtual DtHorario asignarHorario(DtFecha fecha, DtHorario horario)= 0;
    virtual void confirmarAltaFuncion()= 0;
    //virtual void recordarFuncion(DtFuncion func)= 0;
    //virtual void recordarPelicula(DtPelicula peli)= 0;
    //virtual void RecordarCine(DtCine cine)= 0;
    virtual void recordarHorario(DtFecha fecha,DtHorario horario)= 0;



};

#endif