#include "Fecha.hpp"

Fecha::Fecha(){
    this->anio = 2002; 
    this->mes = 06;      
    this->dia = 20;
}
Fecha::Fecha(int anio, int mes, int dia){
    this->anio = anio; 
    this->mes = mes;      
    this->dia = dia;
}
Fecha::Fecha(Fecha& F){
    this->anio = F.getAnio(); 
    this->mes = F.getMes();      
    this->dia = F.getDia();
}
Fecha::Fecha(DtFecha F){
    this->anio = F.getAnio(); 
    this->mes = F.getMes();      
    this->dia = F.getDia();
}

int Fecha::getAnio()const{
    return this->anio;
}
int Fecha::getMes()const{
    return this->mes;
}
int Fecha::getDia()const{
    return this->dia;
}

void Fecha::setAnio(int a){
    this->anio = a;
}
void Fecha::setMes(int m){
    this->mes = m;
}
void Fecha::setDia(int d){
    this->dia = d;
}

bool Fecha::operator==(const Fecha& f2)const{
    return (dia == f2.getDia() && mes == f2.getMes() && anio == f2.getAnio());
}
bool Fecha::operator!=(const Fecha& f2)const{
    return !(*this ==f2);
}
bool Fecha::operator<(const Fecha& f2) const {
    if (anio != f2.anio){
        return anio < f2.anio;
    }
    if (mes != f2.mes){
        return mes < f2.mes;
    }
    return dia < f2.dia;
}

bool Fecha::operator<=(const Fecha& f2) const {
    return *this < f2 || *this == f2;
}

bool Fecha::operator>(const Fecha& f2) const {
    return !(*this <= f2);
}

bool Fecha::operator>=(const Fecha& f2) const {
    return !(*this < f2);
}