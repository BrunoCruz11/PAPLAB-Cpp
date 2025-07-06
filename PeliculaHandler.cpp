#include <vector>
#include "PeliculaHandler.hpp"
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
    vector <DtPelicula> recordarPeliculas; //porq se llama igual que el atributo del handler, son el mismo?
    for(map<string,Pelicula*>::iterator iter = this->Pelicula.begin(); iter!= this->Pelicula.end(); iter++){ //el Pelicula de dentro de llama igual que el tipo de la clase Pelicula, capaz deberia llamarse al atributo de la clase
        Pelicula* p= iter->second;
        recordarPeliculas.push_back(DtPelicula(p));
        map<string, Pelicula*>::iterator;
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

void PeliculaHandler::ponerPuntaje(Puntaje puntaje, Usuario u*){ 
    map <string,Pelicula*>::iterator it = pelicula.find(Pelicularecordada.getTitulo());
    Pelicula* p = it->second;
    p.setPuntaje(puntaje,u,peliculaRecordada); 

}

}
*/
vector <DtComentario> PeliculaHandler::darComentariosPelicula(string titulo){ // aca se utiliza la misma pelicula recordada??, porque este titulo lo tenes con las funciones que ya aplicaste de recordar pelcula
    map <string,Pelicula*>:: iterator it = peliculas.find(titulo);

    Pelicula* p = it->second;

    return p.getComentarios();
}

Comentario* PeliculaHandler::agregarComentarioAPeli(DtComentario comentario, Usuario u*){
     map <string,Pelicula*>::iterator it = pelicula.find(Pelicularecordada.getTitulo());
     Pelicula* P= it->second
    return p. agregarComentario();

} // no te tienen que pasar el titulo??

Comentario* PeliculaHandler::agregarRespuestaAComentario(DtComentario comentario, Usuario* usuarioOriginal, Usuario* autorRespuesta){
    map <string,Pelicula*>::iterator it = pelicula.find(Pelicularecordada.getTitulo()); // buscas la pelicula en el map
    Pelicula* P= iterator->second; // tenes la informacion de esa pelicula
    Comentario* cometarioOriginal; 
    std::vector<Comentario*> comentarios = p->getComentarios();
    for (Comentario* c : comentarios) {
        if (c->getUsuario() == usuarioOriginal) {
            comentarioOriginal = c;
        }
    }

    Comentario* respuesta= new Comentario(comentario.getTexto(), p, autorRespuesta);
    comentarioOriginal->agregarRespuesta(respuesta);

    return respuesta;

} 

DtPelicula PeliculaHandler::obtenerPosterYSinopsis(string titulo){
    map<string,Pelicula*>::iterator = Pelicula.find(pelicularecordada.getTitulo());
    pelicula* p = iterator->second;
}

multimap<int,DtComentario> PeliculaHandler::listarPuntajeYComentarios(multimap <int,DtComentario> listado){
    vector <DtComentario> comentarios = this->pelicularecordada.getComentarios();
    for(vector<DtComentario>::iterator it = comentarios.begin(); it != comentarios.end(); it++){ //recorro los DtCom
        DtComentario comActual = *it;
        string nombreU = comActual.getNicknameUsuario();
        while(){
            
        }
        /*
        for(vector <DtComentario>::iterator it2 = it->getRespuestas().begin(); it2 != it->getRespuestas().end(); it2++){

        }//recorro el vector de las respuestas al comentario, y las guardo antes de seguir avanzando con los comentarios
        */
    }
} //devuelve los comentarios de la pelicula con el puntaje de los usuarios que la comentaron

/*
map<string,Pelicula*>::iterator = Pelicula.find(Pelicularecordada.getTitulo());
    Pelicula* p = iterator->second;

    DtPunYCom datos = p->getPunYCom();

    return  std::Vector<DtPunYCom> devolverPuntajeYComentarios.push_back(datos);
*/