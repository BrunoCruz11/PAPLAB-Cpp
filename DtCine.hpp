#ifndef DTCINE_HPP
#define DTCINE_HPP
#include <string>

using namespace std;
#include "Cine.hpp"

class DtCine{
    private:
        int id;
        string direccion;
    
    public:
        //constructores
        DtCine();
        DtCine(int id, string direccion);
        DtCine(Cine& C);
        DtCine(Cine* C);

        // getter
        int getId();
        string getDireccion();

};

#endif
