#ifndef DIRECCION_HPP
#define DIRECCION_HPP
#include <string>
class DtDireccion{
    private:
        int numero;
        std::string calle; 
    public:
        //constructores y destructor
        DtDireccion();
        DtDireccion(int numero, std::string calle);
        ~DtDireccion();
        //getters
        int getNumero();
        std::string getCalle();
};

#endif