#include "Sala.hpp"
#include <vector>
#include <map>
#include <string>
#include <iostream>
    Sala::Sala(int id, int capacidad){
        this->id = id;
        this->capacidad = capacidad;
    }
    
    Sala::Sala(const Sala& S){
        this->id = S.getId();
        this->capacidad = S.getCapacidad();
        this->funciones = S.getFunciones(); //creo q da error por ser un vector
    }
    
    Sala::~Sala(){

    }

    int Sala::getId() const{
        return this->id;
    }
    
    int Sala::getCapacidad() const{
        return this->capacidad;
    }
    
    std::vector<DtFuncion> Sala::getDataFunciones(){
        std::vector<DtFuncion> dataFunciones;
        for(std::map<int , Funcion*>::iterator it = funciones.begin() ; it!=funciones.end() ; it++){
            Funcion* F = it->second;
            DtFuncion dataActual = F->getData();
            dataFunciones.push_back(dataActual);
        }
        return dataFunciones;
    }
    
    std::map<int , Funcion*> Sala::getFunciones()const{
        return this->funciones;
    }
    
    bool Sala::checkDisponibilidad(DtFecha fecha,  DtHorario horario){
        bool disponible = true;
        for(std::map<int , Funcion*>::iterator it = funciones.begin() ; it!=funciones.end() ; it++){
            Funcion* F = it->second;
            disponible = !F->seSuperpone(fecha , horario);
            if(disponible == false){
                return disponible;
            }
        }
        return disponible;
    }
    
    void Sala::asociarPeliYFuncion(Pelicula* p , int idFuncion){
        std::map<int,Funcion*>::iterator it = this->funciones.find(idFuncion);
        Funcion* funcion = it->second;
        funcion->setPelicula(p);
    }
    
    void Sala::crearFuncion(int id, DtFecha fecha , DtHorario horario, Pelicula* P){
        Sala* S = this;
        Funcion* nuevaFuncion = new Funcion(id,fecha ,horario , P ,this); //falta seguir este renglon
        this->funciones.insert({nuevaFuncion->getId() , nuevaFuncion});
        if(funciones.find(nuevaFuncion->getId()) != funciones.end()){
            std::cout << "Funcion agregada con exito" << std::endl;
        }
        else{
            throw std::invalid_argument("No quedo creada la sala. [S][crearFunc]");
        }
    }

    
    DtFuncion Sala::getFuncion(int idFuncion){
        std::map<int,Funcion*>::iterator it = this->funciones.find(idFuncion);
        Funcion* funcion = it->second;
        return funcion->getData();
    }
    
    bool Sala::comprobarEspacioEnFuncion(int asientos, int funcionRecordada){
        std::map<int,Funcion*>::iterator it = this->funciones.find(funcionRecordada);
        Funcion* funcion = it->second;
        return funcion->hayAsientosDisponibles(asientos);
    }
    bool Sala::tieneFuncion(int idFuncion){
        if(funciones.find(idFuncion) != funciones.end()){
            return true;
        }
        return false;
    }
    
    Reserva* Sala::agregarReserva(int idFuncion,TipoReserva metodoDePago, std::string dataTarjeta ,float costo,int cantEntradas,Usuario* u ){
        std::map<int,Funcion*>::iterator it = this->funciones.find(idFuncion); //falta definir funcion recordada UPDATE: La recordada es del controller. DE HECHO, ya se estaba pasando el id, lol! 
        Funcion* funcion = it->second;
        if(metodoDePago == esDebito){
            return funcion->CrearReservaDebito(dataTarjeta ,costo , cantEntradas ,u);
        }
        else{
            return funcion->CrearReservaCredito(dataTarjeta, costo , cantEntradas , u );
        }
    }
    
    std::vector<DtFuncion> Sala::listarFunciones(){
        std::cout << "llego a sala" << std::endl;
        std::vector<DtFuncion> dataFunciones;
        for(std::map<int , Funcion*>::iterator it = funciones.begin() ; it!=funciones.end() ; it++){

            Funcion* F = it->second;
            dataFunciones.push_back(DtFuncion(F));
        }
        std::cout << "llego a retorno sala" << std::endl;
        return dataFunciones;
    }
    
    void Sala::removerPeliDeFunciones(std::string tituloP){ //Deberia eliminar las funciones o lo hacemos en una funcion separada?
        for(std::map<int , Funcion*>::iterator it = funciones.begin() ; it!=funciones.end() ; it++){
            Funcion* F = it->second;
            if(F->getTituloPeli() == tituloP){
                F->setPelicula(NULL);
                delete F;
            }
        }
    }

    std::vector<DtFuncion> Sala::listarFuncionesConSusReservasSala(std::string titulo){
        std::vector<DtFuncion> FuncionesADevolver;
        for(std::map<int,Funcion*>::iterator it2 = funciones.begin() ; it2 != funciones.end() ; it2++){
                Funcion* F = it2->second;
                if(F->getTituloPeli() == titulo){
                    FuncionesADevolver.push_back(F->getData());
                }
        }
        return FuncionesADevolver;
    }
