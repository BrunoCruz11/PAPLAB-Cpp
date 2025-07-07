#include "CineHandler.hpp"
#include <vector>
#include <string>
#include "Sala.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

CineHandler::CineHandler(){
    ultimoIdCine = 0;
    ultimoIdSala = 0;
}
CineHandler* CineHandler::instancia = NULL;

CineHandler* CineHandler::getInstancia(){
    if(instancia == NULL){
        instancia = new CineHandler();
    }
    return instancia;
}

Cine* CineHandler::darCine(int id){
    if(cines.find(id) != cines.end()){
        return cines.find(id)->second;
    }
    else{
        throw std::invalid_argument("No existe el cine. [darCine]");
    }
}
std::vector<DtCine> CineHandler::listarCines(){
    std::vector<DtCine> ret;
    for(std::map<int,Cine*>::iterator it = cines.begin(); it != cines.end() ; it++){
        ret.push_back(DtCine(it->second));
    }
    return ret;
}

int CineHandler::darNuevoIdCine(){
    ultimoIdCine++;
    cout << "entro" << endl;

    return ultimoIdCine;
}
int CineHandler::darNuevoIdSala(){
    ultimoIdSala = ultimoIdSala + 1;
    return ultimoIdSala;
}
DtCine CineHandler::getCine(int idCine){
    if(cines.find(idCine) != cines.end()){
    map<int,Cine*>::iterator it= cines.find(idCine);
    Cine* c= it->second;
    return DtCine(c);
    }
    throw invalid_argument("No se encontro un cine con ese id.");
}

map <int, Cine*> CineHandler::getColeccionCines(){
    return this->cines;
}

vector<DtSala> CineHandler::darSalas(DtCine c){
    int idCine = c.getId();
    map<int,Cine*>::iterator it= cines.find(idCine);
    Cine* aux = it->second;
    return aux->listarSalas();
}

DtSala CineHandler::getSala(int idSala){//Ta mal.
    for(map<int, Cine*>::iterator it = cines.begin() ; it!=cines.end(); it++){
        map<int,Sala*> salasCineActual = it->second->getTodasLasSalas();
        if(salasCineActual.find(idSala) != salasCineActual.end()){
            return DtSala(salasCineActual.find(idSala)->second);
        }   
    }
    //Si no encontro la sala en ningun cine tira error.
        throw std::invalid_argument("No existe una sala con ese ID");
}

bool CineHandler::esHorarioDisponible(DtFecha fecha, DtHorario horario,DtCine CineRecordado, DtFecha f){ // aca podriamos sacar el cine recordado ya que ya recorde la sala antes. No, la sala no sabe a que cine pertenece.Igual entiendo que se podria buscar en todos los cines la sala.
    if(cines.find(cineRecordado.getId()) != cines.end()){
        Cine* cine = cines.find(cineRecordado.getId())->second;
        if(cine->getTodasLasSalas().find(salaRecordada.getId()) != cine->getTodasLasSalas().end()){
            Sala* sala = cine->darSala(salaRecordada.getId());
            return sala->checkDisponibilidad(fecha , horario);
        }
        else{
            throw std::invalid_argument("Irregularidad entre el cine y la sala recordados.");
        }
    }
    else{
        throw std::invalid_argument("No se encontro el cine. [esHorarioDisponible]");
    }
}


void CineHandler::agregarFuncionEnCine(int idFunc ,DtPelicula p, DtCine c, DtSala s, DtHorario horarioNuevo,DtFecha fechaNueva){ // agregue Dt fecha en parametros (antes no estaba), y le cambie el nombre de los cabezales asi es mas entendible
    //ATENCION, LOS HANDLERS NO DEBERIAN DE RECORDAR, PRIMER AVISO. LaltaFuncionOS CONTROLADORES RECUERDAN LO QUE LOS HANDLERS LES DAN EN TODO CASO.
    
    int idCine= c.getId(); // obtenes el id del cine que te pasan
    map<int,Cine*>::iterator it= cines.find(idCine); // buscas el cine 
    Cine* aux = it->second; // seteas el cine con iterator->second
    int idSala = s.getId(); // obtenes el Id de la sala recordada // La esta pasando por parametro, es confuso.
    if(aux->tieneSala(idSala) ){// chekeas si existe la sala en ese cine
        Sala* s = aux->darSala(idSala);
        
        map<string,Pelicula*>::iterator it2= aux->getTodasLasPelis().find(p.getTitulo()); // buscas la pelicula en el arry de peliculas para tener la verdadera informacion de ella // no se eee, mepa que hay que pasarle el puntero de una, y haberselo pedido al pelicula controller.
        Pelicula* peliculaNueva= aux->getPelicula(p.getTitulo()); // obtenes la nueva pelicula (se precisa para pasarsela al crear funcion)
        s->crearFuncion(idFunc,fechaNueva,horarioNuevo,peliculaNueva); 
    }
    else{
        throw invalid_argument("El cine dado no tiene la sala dada. WTF [CH][agregarFuncCine]");
    }
}


//void CineHandler::RecordarCine(DtCine c){//Cre que no es necesaria. Porque se usa para dar cines de una pelicuala pero se puede hacer con una variable local.
 //   cineRecordado = c;
//}

//void CineHandler::recordarFunciones(std::vector <DtFuncion> FuncionesRecordadas){//Esto esta terrible.Seguro me falta contexto, descomentar cuando se precise.
//    funcionesRecordadas.push_back(FuncionesRecordadas);
//}

bool CineHandler::hayAsientosDisponiblesEnFuncion(int asientos, int funcionRecordada){
    /*
    for(map<int,Cine*>::iterator it= cines.begin(); it!= cines.end(); it++){
            int idDeCineActual= it->first;
            if(cineRecordado.getId()==idDeCineActual){
            Cine* cineActual = it->second;
            return cineActual->tieneFuncionAsientosDisponibles(asientos,funcionRecordada);
        }
    }
        */
    for(map<int,Cine*>::iterator it= cines.begin(); it!= cines.end(); it++){
        Cine* C = it->second;
        cout << C->getId() << endl;
        if(C->tieneFuncion(funcionRecordada)){
            cout<<"tiene funcion!"<< endl;
            return C->tieneFuncionAsientosDisponibles(asientos , funcionRecordada);
        }
    }
    throw std::invalid_argument("No se encontro el cine. [hayAsientosDispFunc]");
}

std::vector <DtCine> CineHandler::darCinesDePelicula (string titulo){
    std::vector<DtCine> cinesADevolver;
    for(map<int,Cine*>::iterator it= cines.begin(); it!= cines.end(); it++){

        Cine* cineActual= it->second;
        
        if(cineActual->tienePelicula(titulo)){
            cinesADevolver.push_back(DtCine(cineActual));
        }
    }
    return cinesADevolver;
}

std::vector <DtFuncion> CineHandler::darFuncionesDeCine(int Id){
    if(cines.find(Id) != cines.end()){
        map<int,Cine*>::iterator it= cines.find(Id);
        Cine* c= it->second;
        return c->listarFunciones();
    }
    throw invalid_argument("No se econtro el cine. [darFuncionesDeCine]");
}

Reserva* CineHandler::colocarReserva(int idFuncion, TipoReserva tipo, std::string dataTarjeta ,float costo, int cantEntradas, Usuario* u){//Hacer que le pasen el precio final.
    Cine* c = NULL;
    for(map<int,Cine*>::iterator it = cines.begin() ; it != cines.end() ; it++){
        if(it->second->tieneFuncion(idFuncion)){
            c = it->second;
        }
    }
    if(c != NULL){
        return c->agregarReserva(idFuncion, tipo , dataTarjeta ,costo, cantEntradas, u);
    }
    else{
        throw std::invalid_argument("No hay ningun cine con esa funcion.(Emoji de calavera)");
    }
}


void CineHandler::agregarCine(std::string direccion , vector<int> capacidadesDeSalasNuevas){
    int nuevoId = this->darNuevoIdCine();
    std::cout << "mamen mamen" << std::endl;
    Cine* nuevoCine = new Cine(nuevoId , direccion);
        std::cout << "preloop" << std::endl;
    for(int c :  capacidadesDeSalasNuevas){
        nuevoCine->agregarSala(new Sala(this->darNuevoIdSala(), c));
    }
    std::cout << "preinsert" << std::endl;
    cines.insert({nuevoCine->getId() ,nuevoCine});
}

void CineHandler::quitarPeliculaDeCines(string tituloPelicula){
    for(map<int,Cine*>::iterator it = this->cines.begin() ; it != this->cines.end() ; it++){ //recorre todos los cines
        Cine* cineActual = it->second;
        if(cineActual->tienePelicula(tituloPelicula)){ //si el cine tiene la pelicula
            cineActual->removerPeliculaDeFuncion(tituloPelicula); //quita la pelicula de las funciones que la tengan
            cineActual->removerPelicula(tituloPelicula); //remueve la pelicula de las peliculas del cine.
        }
    }
    //No se elimina la pelicula del sistema, solo de los cines.
}

std::vector<DtFuncion> listarFuncionesConSusReservasCineHandler(string titulo){
 for(std::map<int,Cine*>::iterator it= cines.begin(); it!=cine.end();it++){
    Cine* cineAChekear= it->second;
    cineAChekear->listarFuncionesConsusReservasCine(string titulo);
 }

}