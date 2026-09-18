#include <string>
#include <vector>
#include "CineController.hpp"

using namespace std;

CineController* CineController::instancia = nullptr;

CineController::CineController(){
    this->manejadorCine = CineHandler::getInstancia();
    this->manejadorPelicula = PeliculaHandler::getInstancia();
}

CineController* CineController::getInstancia(){
    if(instancia == nullptr){
        instancia = new CineController();
    }
    return instancia;
}
CineController::~CineController() {}


void CineController::agregarDireccion(string Direccion){
    this->direcciones.push_back(Direccion);
}

void CineController::ingresarSalas(vector<int> capacidades){
    this->nuevasSalas.push_back(capacidades);
}

//void CineController::confirmarCine(){
 //   Cine* c;
   // c = new(idCine,NuevaDireccion,NuevaSalas);
    //controladorCine::getInstancia()->agregarCine(c);
//};



void CineController::cancelarCine(){//Limpiar los atributos del controller.

}

void CineController::confirmarAltaCine(){
    int aux = 0;
    for(string D : direcciones){
        manejadorCine->agregarCine(D , nuevasSalas[aux]);
        aux = aux + 1;
    }
}

void CineController::agregarPeliculaACine(std::string titulo , int id){
    Pelicula* peli = manejadorPelicula->darPelicula(titulo);
    Cine* cine = manejadorCine->darCine(id);
    cine->agregarPelicula(peli);
}