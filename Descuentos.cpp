#include "Descuentos.hpp"

Descuentos::Descuentos(){
    std::string descuento1 = "LaFinanciera" ;
    std::string descuento2 = "FinancieraCarlitos" ;
    std::string descuento3 = "FinancieraPatasLocas" ;
    std::string descuento4 = "a" ;

    this->descuentos.insert({descuento1, 10});
    this->descuentos.insert({descuento2, 50});
    this->descuentos.insert({descuento3, 25});
    this->descuentos.insert({descuento4, 15});

}
int Descuentos::getDescuento(std::string dataFinanciera){
    int des = descuentos.find(dataFinanciera)->second;
    return des;
}