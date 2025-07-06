#include "DtFuncion.hpp"
#include "Funcion.hpp"

DtFuncion::DtFuncion(){}

DtFuncion::DtFuncion(int id, DtHorario horario, vector <DtReserva*> reservas , DtSala sala, DtPelicula pelicula){
    this->id = id;
    this->horario = horario;
    this->reservas = reservas;
    this->sala = sala;
    this->pelicula = pelicula;
}

DtFuncion::DtFuncion(const DtFuncion& F){
    this->id = F.getId();
    this->horario = F.getHorario();
    this->reservas = F.getReservas();
    this->sala = F.getSala();
    this->pelicula = F.getPelicula();
}
DtFuncion::DtFuncion(Funcion* F){
    this->id = F->getId();
    this->horario = DtHorario(F->getHorario());
    this->reservas = F->listarReservas();
    this->sala = F->getSala();
    this->pelicula = F->getPelicula();
}
        
// getter
        
int DtFuncion::getId()const{
    return this->id;
}

DtHorario DtFuncion::getHorario()const{
    string aux1 = horario.getHoraComienzo();
    string aux2 = horario.getHoraFin();
    DtHorario ret(aux1, aux2);
    return ret;
}

vector <DtReserva*> DtFuncion::getReservas() const{
    return this->reservas;
}

DtSala DtFuncion::getSala()const{
    return this->sala;
}

DtPelicula DtFuncion::getPelicula()const{
    string titulo = pelicula.getTitulo();
    string sinopsis = pelicula.getSinopsis();
    float puntajePromedio = pelicula.getPuntajePromedio();
    string poster = pelicula.getPoster();
    DtPelicula ret(titulo, sinopsis, puntajePromedio, poster);
    return ret;
}