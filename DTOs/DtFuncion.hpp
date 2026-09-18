#ifndef DTFUNCION_HPP
#define DTFUNCION_HPP
#include "DtHorario.hpp"
#include "DtPelicula.hpp"
#include "DtSala.hpp"
#include "DtReserva.hpp"
#include <vector>

class DtFuncion{
    private:
        int id;
        DtHorario horario;
        vector<DtReserva*> reservas; 
        DtSala sala;
        DtPelicula pelicula;

    public:
        //constructores
        DtFuncion();
        DtFuncion(int id, DtHorario horario, vector <DtReserva*> reservas , DtSala sala, DtPelicula pelicula);
        DtFuncion(const DtFuncion& F) ;
        DtFuncion(Funcion* F);

        // getter
        int getId() const;
        DtHorario getHorario() const;
        vector <DtReserva*> getReservas() const;
        DtSala getSala() const;
        DtPelicula getPelicula() const;

};

#endif
