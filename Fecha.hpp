#ifndef FECHA_HPP
#define FECHA_HPP

#include "DtFecha.hpp"

class Fecha{
    private:
        int anio;
        int mes;
        int dia;

    public:
        //constructores
        Fecha();
        Fecha(int anio, int mes, int dia);
        Fecha(Fecha& F);       
        Fecha(DtFecha F);


        // getter
        int getAnio()const;
        int getMes()const;
        int getDia()const;
        
        // Setters
        void setAnio(int);
        void setMes(int);
        void setDia(int);

        //Operadores sobrecargados(Emoji de calavera)
        bool operator==(const Fecha& f2)const;
        bool operator!=(const Fecha& f2)const;
        bool operator<(const Fecha& f2)const;
        bool operator<=(const Fecha& f2)const;
        bool operator>(const Fecha& f2)const;
        bool operator>=(const Fecha& f2)const;
};

#endif
