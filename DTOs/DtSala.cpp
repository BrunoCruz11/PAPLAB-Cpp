#include "DtSala.hpp"
#include "Sala.hpp"
#include "DtFuncion.hpp"
//Constructores
    DtSala::DtSala(){}
    DtSala::~DtSala(){}

    DtSala::DtSala(int id, int capacidad ){
        this->id = id ;
        this->capacidad = capacidad;
        
    }
    DtSala::DtSala(const DtSala& S){
        this->id = S.getId();
        this->capacidad = S.getCapacidad();
        this->funciones = S.getFunciones();
    }
    DtSala::DtSala(DtSala& S){
        this->id = S.getId();
        this->capacidad = S.getCapacidad();
        this->funciones = S.getFunciones();
    }
    DtSala::DtSala(Sala& S){ //no tiene sala incluido
        this->id = S.getId();
        this->capacidad = S.getCapacidad();
        this->funciones = S.getDataFunciones();
    }
    DtSala::DtSala(Sala* S){
        this->id = S->getId();
        this->capacidad = S->getCapacidad();
        this->funciones = S->getDataFunciones();
    }
//Getters
    int DtSala::getId()const{
        return this->id;
    }
    int DtSala::getCapacidad()const{
        return this->capacidad;
    }

    std::vector<DtFuncion> DtSala::getFunciones()const{
        return this->funciones;
    }

    //falta el de los dthorarios

