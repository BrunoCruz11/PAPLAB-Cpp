#ifndef HORARIO_HPP
#define HORARIO_HPP

#include <string>
#include "DtHorario.hpp"
class Horario{
    private:
        std::string horaComienzo;
        std::string horaFin;

    public:
        //constructores
        Horario();
        Horario(std::string horaComienzo, std::string horaFin);
        Horario(Horario& H);
        Horario(DtHorario DtH);

        // getter
        std::string getHoraComienzo()const;
        std::string getHoraFin()const;
        
        // Setter
        void setHoraComienzo(std::string H);
        void setHoraFin(std::string H);

        // Operadores sobrecargados, amen.
        bool operator==(const Horario& h2);
        bool operator!=(const Horario& h2);
        bool operator<(const Horario& h2);
        bool operator<=(const Horario& h2);
        bool operator>(const Horario& h2);
        bool operator>=(const Horario& h2);
};

#endif
