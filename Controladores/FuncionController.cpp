#include "FuncionController.hpp"
#include <vector>
#include <string>
#include <stdexcept>
        //Momento singleton
        FuncionController::FuncionController(){
            this->ultimoIdFuncion = 0;
            this->manejadorCine = CineHandler::getInstancia();
            this->manejadorPelicula = PeliculaHandler::getInstancia();
        }

        FuncionController* FuncionController::instancia = NULL;
        
        FuncionController* FuncionController::getInstancia(){
            if(instancia == NULL){
                instancia = new FuncionController();
            }
            return instancia;
        }
        //Momento autoincremental  
        int FuncionController::getNuevoIdFuncion(){
            this->ultimoIdFuncion = this->ultimoIdFuncion + 1;
            return ultimoIdFuncion;
        }


        // CREO QUE HAY QUE AGREGAR ATRIBUTOS DE TODOS LOS RECORDAR
        std::vector<DtPelicula> FuncionController::listarPeliculas(){
            return manejadorPelicula->darPeliculas();
        }

        void FuncionController::eligePelicula(string titulo){
            DtPelicula P = manejadorPelicula->getPelicula(titulo);
            PeliculaRecordada = P;
        }

        std::vector<DtCine> FuncionController::listarCines(){ 
           return manejadorCine->listarCines();
        }

        void FuncionController::eligeCine(int id){
            try{
                DtCine CineAPoner = manejadorCine->getCine(id);
                this->cineRecordado = CineAPoner;

            }
            catch(std::invalid_argument& e){
                throw e;
            }
        }
        std::vector<DtSala> FuncionController::listarSalas(){
            return manejadorCine->darSalas(cineRecordado);
        }

        void FuncionController::eligeSala(int id){
            Cine* c = manejadorCine->darCine(cineRecordado.getId()); //Cambie cine recordado por, el ultimo cine recordado.
            DtSala SalaAPoner= DtSala(c->getSala(id));
            salaRecordada = SalaAPoner;
        }

        void FuncionController::recordarHorario(DtFecha fecha, DtHorario horario){
            this->fechaRecordada = fecha;
            this->horarioRecordado = horario;
            }


        void FuncionController::confirmarAltaFuncion(){
            Cine* cine = manejadorCine->darCine(cineRecordado.getId());
            Pelicula* P = cine->getPelicula(PeliculaRecordada.getTitulo());
            cine->agregarFuncion(P , salaRecordada , fechaRecordada , horarioRecordado , this->getNuevoIdFuncion()) ;
            
        }


       // void ::FuncionController recordarFuncion(DtFuncion func){
            //Funcion* f= Funcion(func);
           // Sala* salaActual= Sala(salasRecordadas.back())
            


        //};
        //void ::FuncionController recordarPelicula(DtPelicula peli){

        //};
        //void ::FuncionController RecordarCine(DtCine cine){

        //};
       // void ::FuncionController recordarHorario(DtFecha fecha,DtHora horaComienzo ,DtHora horaFin){

        //};


