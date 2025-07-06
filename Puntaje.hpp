#ifndef PUNTAJE_HPP
#define PUNTAJE_HPP

#include <string>
//#include "Usuario.hpp" Se cambia este include por una declaracion adelantada para evitar inclusiones ciclicas.
class Usuario;
//#include "Pelicula.hpp" Corregir dependencias circulares con forward declaration.
class Pelicula;


class Puntaje{
    private:
        int puntos;
        Usuario* usuario;
        Pelicula* pelicula;
    public:
    Puntaje(int P , Usuario* U , Pelicula* peli);
    Puntaje(Puntaje& P);
    ~Puntaje();
    //getters
    std::string getNickUsuario()const;
    std::string getTituloPelicula()const;
    int getPuntaje()const; //Retorna el valor de "puntos".
};


#endif