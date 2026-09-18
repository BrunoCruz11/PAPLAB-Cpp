#include "DtHorario.hpp"
#include "Horario.hpp"
//Constructores
    DtHorario::DtHorario(){}
    DtHorario::~DtHorario(){}
    DtHorario::DtHorario(std::string horaComienzo, std::string horaFin){
        this->horaComienzo = horaComienzo ;
        this->horaFin = horaFin;
    }
    DtHorario::DtHorario(const DtHorario& H){
        this->horaComienzo = H.getHoraComienzo();
        this->horaFin = H.getHoraFin();
    }
    DtHorario::DtHorario(Horario H){
        this->horaComienzo = H.getHoraComienzo();
        this->horaFin = H.getHoraFin();
    }



//Getters
    std::string DtHorario::getHoraComienzo()const{
        return this->horaComienzo;
    }

    std::string DtHorario::getHoraFin()const{
        return this->horaFin;
    }

bool DtHorario::operator==(const DtHorario& h2){
    return(this->getHoraComienzo() == h2.getHoraComienzo() && this->getHoraFin() == h2.getHoraFin());

}
bool DtHorario::operator!=(const DtHorario& h2){
    return !(*this == h2);
}

bool DtHorario::operator<(const DtHorario& h2){
    if (this->getHoraComienzo() < h2.getHoraComienzo()){
        return true;
    }
    if (this->getHoraComienzo() == h2.getHoraComienzo()){
        return this->getHoraFin() < h2.getHoraFin();
    }
    return false;
}

bool DtHorario::operator<=(const DtHorario& h2){
    return (*this<h2 || *this == h2);
}
bool DtHorario::operator>(const DtHorario& h2){
    return !(*this<=h2);
}
bool DtHorario::operator>=(const DtHorario& h2){
    return !(*this<h2);
}