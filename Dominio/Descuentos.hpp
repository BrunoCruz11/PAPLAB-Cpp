#ifndef DESCUENTOS_HPP
#define DESCUENTOS_HPP
#include <string>
#include <map>
class Descuentos{
    private:
    std::map<std::string , int> descuentos;
    public:
    Descuentos();
    int getDescuento(std::string dataFinanciera);
};
#endif