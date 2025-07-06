#include "DtCine.hpp"
#include "Cine.hpp"
#include <string>

using namespace std;

//Constructores
    DtCine::DtCine(){}
    DtCine::DtCine(int id, string direccion){
        this->id = id;
        this->direccion = direccion;
    }
    DtCine::DtCine(Cine& C){ //antes decia DtCine ahi, lo cambie por Cine <3
        this->id = C.getId();
        this->direccion = C.getDireccion();
    }
    DtCine::DtCine(Cine* C){
        this->id = C->getId();
        this->direccion = C->getDireccion();
    }
//Getters
    int DtCine::getId(){
        return this->id;
    }
    string DtCine::getDireccion(){
        return this->direccion;
    }
