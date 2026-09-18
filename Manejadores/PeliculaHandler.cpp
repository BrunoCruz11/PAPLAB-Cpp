#include <vector>
#include "PeliculaHandler.hpp"
#include "CineHandler.hpp"
#include "UsuarioHandler.hpp"
#include <stdexcept>
using namespace std;
PeliculaHandler* PeliculaHandler::instancia = nullptr;

PeliculaHandler::PeliculaHandler(){}

PeliculaHandler::~PeliculaHandler(){}

PeliculaHandler* PeliculaHandler::getInstancia(){
    if(instancia == nullptr){
        instancia = new PeliculaHandler();
    }
    return instancia;
}

void PeliculaHandler::agregarPelicula(DtPelicula P){
    peliculas.insert({P.getTitulo() ,new Pelicula(P)});
}
bool PeliculaHandler::existePelicula(std::string titulo){
    return peliculas.find(titulo) != peliculas.end();
}

vector <DtPelicula> PeliculaHandler::darPeliculas(){
    vector <DtPelicula> recordarPeliculas;


    for(map<string,Pelicula*>::iterator iter = this->peliculas.begin(); iter!= this->peliculas.end(); iter++){
        Pelicula* p= iter->second;
        recordarPeliculas.push_back(DtPelicula(p));
        //map<string, Pelicula*>::iterator

    }

    return recordarPeliculas;


} 
void PeliculaHandler::recordarPelicula(string titulo){

    Pelicula* p = this->peliculas.find(titulo)->second;
    this->pelicularecordada = DtPelicula(p);

}


DtPelicula PeliculaHandler::getPelicula(string titulo){ 
    DtPelicula ret;
    map <string,Pelicula*>:: iterator it = peliculas.find(titulo);
    Pelicula* p= it->second;
    ret = DtPelicula(p);

    return ret;
}

float PeliculaHandler::getPuntajePromedioPelicula(string titulo){ // creo que no se tendria que pasa un titulo como parametro
    string TituloRecordado = pelicularecordada.getTitulo();
    map<string,Pelicula*>::iterator it = peliculas.find(TituloRecordado);
    
    
    Pelicula* p = it->second;

    return p->getPuntajePromedio();

}


/*

Puntaje* PeliculaHandler::crearPuntaje(float puntuacion){  

    map <string,Pelicula*>::iterator it = peliculas.find(pelicularecordada.getTitulo());
    
    Pelicula* p= it->second;

    return new Puntaje(puntuacion,p); // creo que tendria que recibir tambien un usuario como parametro es medio raro
}
void PeliculaHandler::ponerPuntaje(Puntaje puntaje, Usuario* u){ 
    map <string,Pelicula*>::iterator it = peliculas.find(pelicularecordada.getTitulo());
    Pelicula* p = it->second;
    p->setPuntaje(puntaje,u,pelicularecordada); 

}
*/
vector <DtComentario> PeliculaHandler::darComentariosPelicula(string titulo){ // aca se utiliza la misma pelicula recordada??, porque este titulo lo tenes con las funciones que ya aplicaste de recordar pelcula
    map <string,Pelicula*>:: iterator it = peliculas.find(titulo);

    Pelicula* p = it->second;

    return p->getComentarios();
}

Comentario* PeliculaHandler::agregarComentarioAPeli(DtComentario comentario, Usuario* u){
     map <string,Pelicula*>::iterator it = peliculas.find(pelicularecordada.getTitulo());
     Pelicula* P= it->second;
    return P->agregarComentario(comentario.getTexto() , u);

} // no te tienen que pasar el titulo??
/*
Comentario* PeliculaHandler::agregarRespuestaAComentario(DtComentario comentario, Usuario* usuarioOriginal, Usuario* autorRespuesta){
    map <string,Pelicula*>::iterator it = peliculas.find(pelicularecordada.getTitulo()); // buscas la pelicula en el map
    Pelicula* P= it->second; // tenes la informacion de esa pelicula
    Comentario* comentarioOriginal; 
    std::vector<Comentario*> comentarios = P->getComentarios();
    for (Comentario* c : comentarios) {
        if (c->getUsuario() == usuarioOriginal) {
            comentarioOriginal = c;
        }
    }

    Comentario* respuesta= new Comentario(comentario.getTexto(), p, autorRespuesta);
    comentarioOriginal->agregarRespuesta(respuesta);

    return respuesta;

}

DtPelicula obtenerPosterYSinopsis(string titulo){
    map<string,Pelicula*>::iterator = Pelicula.find(pelicularecordada.getTitulo());
    Pelicula* p = iterator->second;

}


vector <DtPunYCom> listarPuntajeYComentarios(){
    std::Vector<DtPunYCom> devolverPuntajeYComentarios;
    std::map<string,Pelicula*>::iterator = Pelicula.find(Pelicularecordada.getTitulo());
    Pelicula* p = iterator->second;

    DtPunYCom datos = p->getPunYCom();

    return  std::Vector<DtPunYCom> devolverPuntajeYComentarios.push_back(datos);

}; // raro que devuelva un vector
*/

Pelicula* PeliculaHandler::darPelicula(std::string titulo){
    if(peliculas.find(titulo) != peliculas.end()){
        return peliculas.find(titulo)->second;
    }
    throw std::invalid_argument("No existe la pelicula.");
}

    void PeliculaHandler::quitaryborrarPelicula(){
    map<string,Pelicula*>::iterator it = peliculas.find(pelicularecordada.getTitulo()); //enecuentro la pelicula en el vector
    Pelicula* p = it->second;
    UsuarioHandler* usuarioHandler = UsuarioHandler::getInstancia();
    usuarioHandler->desasociarReservasDePeli(p->getTitulo());//Quita las reservas de funciones de esa peli del usuario.
    //llamo al cinehandler para que elimine la pelicula de los cines donde estaba
    CineHandler* cineHandler = CineHandler::getInstancia();
    cineHandler->quitarPeliculaDeCines(p->getTitulo()); //esto quita la pelicula de los vectores de los cines, salas y funciones donde estaba de todos los cines.

    peliculas.erase(it); //elimina la pelicula del map
    delete p; // Elimina la pelicula del sistema
}