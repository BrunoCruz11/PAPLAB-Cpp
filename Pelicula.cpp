
#include <string>
#include <vector>
#include "Pelicula.hpp"
#include "DtPelicula.hpp" 
        Pelicula::~Pelicula(){
            for (Puntaje* p : puntajes) {
                    delete p; // Liberar memoria de los puntajes
                }
                puntajes.clear();
                for (Comentario* c : comentarios) {
                    delete c; // Liberar memoria de los comentarios
                }
                comentarios.clear();
        }
        Pelicula::Pelicula(std::string titulo, std::string sinopsis, std::string poster){
            this->titulo = titulo;
            this->sinopsis = sinopsis;
            this->poster = poster;
        }

        Pelicula::Pelicula(Pelicula& p){
            this->titulo = p.titulo;
            this->sinopsis = p.sinopsis;
            this->poster = p.poster;
        }
        Pelicula::Pelicula(DtPelicula p){
            this->titulo = p.getTitulo();
            this->sinopsis = p.getSinopsis();
            this->poster = p.getPoster();
        }
        bool Pelicula::esTitulo( std::string titulo){
            return this->getTitulo() == titulo;
        }

        std::string Pelicula::getTitulo(){
            return this->titulo;
        }

        float Pelicula::getPuntajePromedio(){
            if (puntajes.empty()) return 0; // Evitar división por cero

            float suma= 0;

            for(std::vector <Puntaje*>::iterator j=puntajes.begin();j!=puntajes.end(); ++j){

                Puntaje* puntaje = *j;
                suma += puntaje->getPuntaje();

            }

            return suma / puntajes.size();

        }

        Puntaje* Pelicula::setPuntaje(float puntaje, Usuario* s){ // a chekear

            Puntaje* nuevo = new Puntaje(puntaje, s, this);

            puntajes.push_back(nuevo);  

            return nuevo;
            
        }

        //void setpuntaje (); //raro

         // vector <Dtcomentario> getComentarios(){


     // };

        Comentario* Pelicula::agregarComentario(std::string texto, Usuario* s){ // a chekear
            Comentario* nuevo = new Comentario(texto,this, s);
            comentarios.push_back(nuevo);
            return nuevo;
        }

        std::string Pelicula::getPoster(){
            return this->poster;
        }

        std::string Pelicula::getSinopsis(){
            return this->sinopsis;
        }

        //DtFuncion listrarFuncionesPosteriores(std::string titulo); 

       /**   DtPunYCom Pelicula::getPunYCom (){ // a chekear
          return DtPunYCom(this->getPuntajePromedio(), this->getPuntajes(), this->getComentarios());

        }
**/
        std::vector<DtComentario> Pelicula::getComentarios() {
            std::vector<DtComentario> dtComentarios;

            for (Comentario* c : comentarios){
                dtComentarios.push_back(DtComentario(c));
            }

             return dtComentarios;
         }


        std::vector<DtPuntaje> Pelicula::getPuntajes(){
            std::vector<DtPuntaje> dtPuntajes;
            for (Puntaje* p : puntajes){
                dtPuntajes.push_back(DtPuntaje(p));
            }

             return dtPuntajes;
            
        }

         DtPelicula Pelicula::getPunYCom() {
            return DtPelicula(this);
        }
            