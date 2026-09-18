#ifndef DTFECHA_HPP
#define DTFECHA_HPP

class Fecha;

class DtFecha{
    private:
        int anio;
        int mes;
        int dia;

    public:
        //constructores
        DtFecha();
        DtFecha(int anio, int mes, int dia);
        DtFecha(DtFecha& F);

        // getter
        int getAnio()const;
        int getMes()const;
        int getDia()const;

        bool operator==(const DtFecha& f2)const;
        bool operator!=(const DtFecha& f2)const;
        bool operator<(const DtFecha& f2)const;
        bool operator<=(const DtFecha& f2)const;
        bool operator>(const DtFecha& f2)const;
        bool operator>=(const DtFecha& f2)const;

        bool operator==(const Fecha& f2)const;
        bool operator!=(const Fecha& f2)const;
        bool operator<(const Fecha& f2)const;
        bool operator<=(const Fecha& f2)const;
        bool operator>(const Fecha& f2)const;
        bool operator>=(const Fecha& f2)const;
    };

#endif
