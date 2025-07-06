#include "Horario.hpp"

Horario::Horario(){
    this->horaComienzo = "00:00";
    this->horaFin = "00:00";
}
Horario::Horario(std::string horaComienzo, std::string horaFin){
    this->horaComienzo = horaComienzo;
    this->horaFin = horaFin;
}
Horario::Horario(Horario& H){
    this->horaComienzo = H.getHoraComienzo();
    this->horaFin = H.getHoraFin();
}
Horario::Horario(DtHorario DtH){
    this->horaComienzo = DtH.getHoraComienzo();
    this->horaFin = DtH.getHoraFin();
}

// getter
std::string Horario::getHoraComienzo()const{
    return this->horaComienzo;
}
std::string Horario::getHoraFin()const{
    return this->horaFin;
}
        
// Setter
void Horario::setHoraComienzo(std::string H){
    this->horaComienzo = H;
}
void Horario::setHoraFin(std::string H){
    this->horaFin = H;
}

bool Horario::operator==(Horario const& h2){
    return(this->getHoraComienzo() == h2.getHoraComienzo() && this->getHoraFin() == h2.getHoraFin());

}
bool Horario::operator!=(const Horario& h2){
    return !(*this == h2);
}

bool Horario::operator<(const Horario& h2){
    if (this->getHoraComienzo() < h2.getHoraComienzo()){
        return true;
    }
    if (this->getHoraComienzo() == h2.getHoraComienzo()){
        return this->getHoraFin() < h2.getHoraFin();
    }
    return false;
}

bool Horario::operator<=(const Horario& h2){
    return (*this<h2 || *this == h2);
}
bool Horario::operator>(const Horario& h2){
    return !(*this<=h2);
}
bool Horario::operator>=(const Horario& h2){
    return !(*this<h2);
}