#include "DtFecha.hpp"
#include "Fecha.hpp"
//Constructores
    DtFecha::DtFecha(){}
    DtFecha::DtFecha(int anio, int mes, int dia){
        this->anio = anio;
        this->mes = mes;
        this->dia = dia;
    }
    DtFecha::DtFecha(DtFecha& F){
        this->anio = F.getAnio();
        this->mes = F.getMes();
        this->dia = F.getDia();
    }

//Getters
    int DtFecha::getAnio()const{
        return this->anio;
    }
    int DtFecha::getMes()const{
        return this->mes;
    }
    int DtFecha::getDia()const{
        return this->dia;
    }

bool DtFecha::operator==(const DtFecha& f2)const{
    return (dia == f2.getDia() && mes == f2.getMes() && anio == f2.getAnio());
}
bool DtFecha::operator!=(const DtFecha& f2)const{
    return !(*this ==f2);
}
bool DtFecha::operator<(const DtFecha& f2) const {
    if (anio != f2.anio){
        return anio < f2.anio;
    }
    if (mes != f2.mes){
        return mes < f2.mes;
    }
    return dia < f2.dia;
}

bool DtFecha::operator<=(const DtFecha& f2) const {
    return *this < f2 || *this == f2;
}

bool DtFecha::operator>(const DtFecha& f2) const {
    return !(*this <= f2);
}

bool DtFecha::operator>=(const DtFecha& f2) const {
    return !(*this < f2);
}



bool DtFecha::operator==(const Fecha& f2)const{
    return (dia == f2.getDia() && mes == f2.getMes() && anio == f2.getAnio());
}
bool DtFecha::operator!=(const Fecha& f2)const{
    return !(*this ==f2);
}
bool DtFecha::operator<(const Fecha& f2) const {
    if (anio != f2.getAnio()){
        return anio < f2.getAnio();
    }
    if (mes != f2.getMes()){
        return mes < f2.getMes();
    }
    return dia < f2.getDia();
}

bool DtFecha::operator<=(const Fecha& f2) const {
    return *this < f2 || *this == f2;
}

bool DtFecha::operator>(const Fecha& f2) const {
    return !(*this <= f2);
}

bool DtFecha::operator>=(const Fecha& f2) const {
    return !(*this < f2);
}