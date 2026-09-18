#ifndef DTSALA_HPP
#define DTSALA_HPP

#include <vector>

class Sala;
class DtFuncion;
class DtSala{
    private:
        int id;
        int capacidad;
        std::vector<DtFuncion> funciones;
        
    public:
        //constructores
        DtSala();
        DtSala(int id, int capacidad);//le falta los dthorarios
        DtSala(const DtSala& S);//le falta los dthorarios
        DtSala(Sala& S);//le falta los dthorarios
        DtSala(DtSala& S);
        DtSala(Sala*);
        ~DtSala();

        // getter
        int getId()const;
        int getCapacidad()const;
        std::vector<DtFuncion> getFunciones() const;
};

#endif
