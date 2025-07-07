//quite el ifndef que quedo en este .cpp
#include <string>
#include <vector>
#include "Sala.hpp"
#include "Funcion.hpp"
#include "Debito.hpp"
#include "Credito.hpp"
Funcion::Funcion(){}
Funcion::~Funcion(){
    for(Reserva* r : this->reservas){
        delete r;
    }
    this->reservas.clear();
    this->sala = NULL;
    this->pelicula = NULL;
}
Funcion::Funcion(int id, DtFecha dia, DtHorario horario){
    this->id = id;
    this->dia = dia;
    this->horario = Horario(horario);
}
Funcion::Funcion(int id, DtFecha dia, DtHorario horario, Pelicula* P , Sala* S){
    this->id = id;
    this->dia = dia;
    this->horario = Horario(horario);
    this->pelicula = P;
    this->sala = S;
}
bool Funcion::seSuperpone(DtFecha f, DtHorario horario){
    bool estaOcupado = true;

    if(this->dia.getDia() != f.getDia()){ //cambie donde decia this->fecha por this->dia
        estaOcupado = false;
    }

    std::string comienzoActual = this->horario.getHoraComienzo();
    std::string finActual = this->horario.getHoraFin();
    
    if(comienzoActual > horario.getHoraComienzo() || finActual < horario.getHoraFin()){
        estaOcupado = false;
    }
        // en este metodo hay que sobrecargar los operadores para que puede comparar bien los objetos
    return estaOcupado;
}

void Funcion::setSala(Sala* s){
    this->sala = s;
}

void Funcion::setPelicula(Pelicula* p){
    this->pelicula= p;
}

DtFuncion Funcion::getData(){
    vector <DtReserva*> Dtreservas;

    for(Reserva* r : this->reservas){
        DtReserva* reservaActual = new DtReserva(r);
        Dtreservas.push_back(reservaActual);

    }

    return DtFuncion(this->getId(),DtHorario(this->getHorario()),Dtreservas,DtSala(this->getSala()),DtPelicula(this->getPelicula()));

}

bool Funcion::hayAsientosDisponibles(int asientos){
        int TotalAsientosDisponibles = this->sala->getCapacidad();
        int TotalAsientosReservados = 0;

        for (Reserva* r : this->reservas){
        TotalAsientosReservados = TotalAsientosReservados + r->getCantEntradas();
        };
        int esDisponible = TotalAsientosDisponibles - TotalAsientosReservados;

        return esDisponible >= asientos;
}

Reserva* Funcion::CrearReservaDebito(std::string dataTarjeta, float costo, int cantEntradas, Usuario* u){ //Cambie Crear Reserva por 2 funciones diferentes.
    Reserva* nuevaReserva;
    nuevaReserva = new Debito(dataTarjeta, costo, cantEntradas, this,u);
    reservas.push_back(dynamic_cast<Reserva*>(nuevaReserva));
    return nuevaReserva;
}
Reserva* Funcion::CrearReservaCredito(std::string dataTarjeta , float costo, int cantEntradas, Usuario* u){
    Reserva* nuevaReserva;
    nuevaReserva = new Credito(dataTarjeta, costo, cantEntradas, this, u);
    reservas.push_back(dynamic_cast<Reserva*>(nuevaReserva));
    return nuevaReserva;
}

bool Funcion::chekPelicula(std::string titulo){ 
    return this->pelicula->getTitulo() == titulo;
}

std::vector<DtReserva*> Funcion::listarReservas(){
    std::vector<DtReserva*> dataReservas;

    for(Reserva* r : reservas){
        DtReserva* reservaActual = new DtReserva(r);
        dataReservas.push_back(reservaActual);
    };

    return dataReservas;
}

std::string Funcion::getTituloPeli(){
    return this->pelicula->getTitulo();
}

void Funcion::olvidarPeli(){
    this->pelicula = NULL;
}

bool Funcion::esPosterior(DtFecha fecha, DtHorario horario){
    if(this->dia >= fecha ){
        if(fecha == this->dia && this->horario < horario ){
            return false;
        }
        return true; 
    }
    else{
        return false;
    }
}

int Funcion::getId(){
    return this->id;

}

Horario Funcion::getHorario(){
    return this->horario;
}

Sala* Funcion::getSala(){
    return this->sala;
}

Pelicula* Funcion::getPelicula(){
    return this->pelicula;
}

vector <Reserva*> Funcion::getReservas(){
    return this->reservas;
}

    