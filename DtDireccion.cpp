#include "DtDireccion.hpp"
#include <string>

using namespace std;

 DtDireccion::DtDireccion(){

 }
            
 DtDireccion::DtDireccion(int numero, string calle){
    this->numero = numero;
    this->calle = calle;
 }
 
 DtDireccion::~DtDireccion(){

 }
 
 //getters
 
 int DtDireccion::getNumero(){
    return this->numero;
 }
 
 std::string DtDireccion::getCalle(){
    return this->calle;
 }