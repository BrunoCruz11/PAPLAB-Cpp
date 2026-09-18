#ifndef DTHORARIO_HPP
#define DTHORARIO_HPP

#include <string>
class Horario;

class DtHorario{
    private:
        std::string horaComienzo;
        std::string horaFin;

    public:
        //constructores
        DtHorario();
        ~DtHorario();
        DtHorario(std::string horaComienzo, std::string horaFin);
        DtHorario(const DtHorario& H);
        DtHorario(Horario H);

        // getter
        std::string getHoraComienzo()const;
        std::string getHoraFin()const;
        // Operadores sobrecargados, tremendo
        bool operator==(const DtHorario& h2);
        bool operator!=(const DtHorario& h2);
        bool operator<(const DtHorario& h2);
        bool operator<=(const DtHorario& h2);
        bool operator>(const DtHorario& h2);
        bool operator>=(const DtHorario& h2);
};

#endif
