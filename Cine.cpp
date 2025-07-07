#include "Cine.hpp" 
#include "DtFuncion.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>
    Cine::Cine(int id , std::string direccion){
        this->id = id;
        this->direccion = direccion;
    }
    
    Cine::~Cine(){

    }
    
    int Cine::getId(){
        return this->id;
    }
    
    std::string Cine::getDireccion(){
        return this->direccion;
    }
    
    DtFuncion Cine::getFuncion(int id){
        for( std::pair<int , Sala*> S : salas){//Pair refiere a cada conjunto par int(clave) Sala(objeto del mapa) en el mapa.
            if(S.second->tieneFuncion(id)){
                return S.second->getFuncion(id);
            }
        }
        throw invalid_argument("No existe la Funcion");
    }
    
    DtSala Cine::getSala(int id){
        if(this->salas.find(id) == this->salas.end()){
            throw invalid_argument("No se encontro la sala. [getSala]");
        }
        DtSala dataSala = DtSala(this->salas.find(id)->second);
        return dataSala;
    }
    Sala* Cine::darSala(int id){
        if(salas.find(id) != salas.end()){
            return salas.find(id)->second;
        }
        else{
            throw invalid_argument("Se le pidio Sala a un cine que no la tiene.");
        }
    }
    
    Sala* Cine::getSalaConFuncion(int idFuncion){
        for(std::pair<int , Sala*> S : this->salas){
            if(S.second->tieneFuncion(idFuncion)){
                Sala* ret = S.second;
                return ret; //porque no devuelve S.second directamente? Buena pregunta.
            }
        }
        throw invalid_argument("Ninguna sala del cine tiene la funcion");
    }
    
    Pelicula* Cine::getPelicula(std::string titulo){
        if(this->peliculas.find(titulo) != peliculas.end()){
            Pelicula* ret = this->peliculas.find(titulo)->second;
            return ret; 
        }
        else{
            throw std::invalid_argument("El cine no tiene la pelicula.");
        }
        
    }
    std::map<std::string,Pelicula*>& Cine::getTodasLasPelis(){
        return this->peliculas;
    }
    std::map<int, Sala*>& Cine::getTodasLasSalas(){
        return this->salas;
    }

    std::vector<DtSala> Cine::listarSalas(){
        std::vector<DtSala> dataSalas;
        for(std::map<int , Sala*>::iterator it = this->salas.begin() ; it!= this->salas.end() ;it++){
            Sala* S = it->second;
            dataSalas.push_back(DtSala(S));
        }
        return dataSalas;
    }
    
    std::vector<DtFuncion> Cine::listarFunciones(){
        std::vector<DtFuncion> dataFunciones;
        for(std::map<int , Sala*>::iterator it = this->salas.begin() ; it!= this->salas.end() ;it++){
            Sala* S = it->second;
            vector<DtFuncion> funcionesSala = S->listarFunciones();
            for(DtFuncion F : funcionesSala){
                dataFunciones.push_back(F);
            }

            
            /*for(pair<int, Funcion*> parIdFuncion : funciones){//Se lee: Por cada conjunto de clave y funcion en las funciones de S
                Funcion* F = parIdFuncion.second; //Hace qe la Funcion del par sea F
                dataFunciones.push_back(F->getData());// Y la guarda como DT en datafunciones.
            }*/
        }
        cout << "llego a retorno cine" << endl;

        return dataFunciones;
    }
    /*
    std::vector<DtFuncion> Cine::listarFuncionesConSusReservas(){
        //Cada vez me convence más de que con listarFunciones ya da.

    } */
    
    std::vector<DtFuncion> Cine::buscarFuncionesPosteriores(std::string titulo , DtFecha fechaActual , DtHorario horaActual){
        std::vector<DtFuncion> dataFunciones;
        for(std::map<int , Sala*>::iterator it = this->salas.begin() ; it!= this->salas.end() ;it++){
            Sala* S = it->second;
            for(pair<int, Funcion*> parIdFuncion : S->getFunciones()){
                Funcion * F = parIdFuncion.second; 
                if(F->esPosterior(fechaActual , horaActual)){
                    dataFunciones.push_back(F->getData());
                }
            }
        }
        return dataFunciones;
    }

    void Cine::agregarSala(Sala* S){
        this->salas.insert({S->getId() , S});
    }
    
    void Cine::agregarFuncion(Pelicula* P, DtSala S , DtFecha F , DtHorario H , int idFuncion){
        if(this->salas.find(S.getId()) == this->salas.end()){
            throw invalid_argument("No se enconto la sala en el cine. [agregarFunc]");
        }
        Sala* sala = this->salas.find(S.getId())->second;

        if(this->tienePelicula(P->getTitulo())){
            Pelicula* pelicula = this->getPelicula(P->getTitulo());
            sala->crearFuncion(idFuncion , F ,H , P);
            sala->asociarPeliYFuncion(pelicula , idFuncion);
        }
        else{
            throw invalid_argument("El cine no tiene la pelicula a su disposicion.");
        }
    }
    
    Reserva* Cine::agregarReserva(int idFuncion, TipoReserva metodoPago ,std::string dataTarjeta, float costo , int cantEntradas , Usuario* U){
        if(this->tieneFuncion(idFuncion)){
            Sala * sala = this->getSalaConFuncion(idFuncion);
            return sala->agregarReserva(idFuncion, metodoPago , dataTarjeta , costo,  cantEntradas, U);
        }
        throw invalid_argument("La funcion no existe en el cine.");
    }
    
    void Cine::removerPelicula(std::string titulo){
        this->peliculas.erase(titulo);
    }
    
    void Cine::removerPeliculaDeFuncion(std::string titulo){
        for(std::map<int , Sala*>::iterator it = this->salas.begin() ; it!= this->salas.end() ;it++){
            Sala* S = it->second;
            S->removerPeliDeFunciones(titulo);
        }
    }
    
    bool Cine::tieneSala(int id){
        if(this->salas.find(id) != this->salas.end()){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool Cine::tieneFuncion(int id){
        for(map<int,Sala*>::iterator it = salas.begin() ; it != salas.end() ; it++){
            Sala* S = it->second;
            if(S->tieneFuncion(id)){
                return true;
            }
        }
        return false;
    }

    bool Cine::estaDisponibleHorarioEnSala(DtFecha f , DtHorario H){
        Sala* sala = this->salas.find(salaRecordada.getId())->second;
        return sala->checkDisponibilidad(f, H);  
    }
    
    bool Cine::tienePelicula(std::string titulo){
        return this->peliculas.find(titulo) != this->peliculas.end();
    }

    bool Cine::tieneFuncionAsientosDisponibles(int asientos, int id){
        Sala* sala = getSalaConFuncion(id);
        return sala->comprobarEspacioEnFuncion(asientos, id);
    }

    void Cine::agregarPelicula(Pelicula* P){
        this->peliculas.insert({P->getTitulo() , P});
    }