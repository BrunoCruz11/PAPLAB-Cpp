#ifndef DTPUNTAJE_HPP
#define DTPUNTAJE_HPP
#include <string>
#include "Puntaje.hpp"

class DtPuntaje{
    private:
        int puntos;
        std::string nicknameUsuario;
        std::string tituloPelicula;
    public:
    DtPuntaje(int P , std::string U , std::string peli);
    DtPuntaje(const DtPuntaje& P);
    DtPuntaje(Puntaje* P);
    ~DtPuntaje();

    std::string getNicknameUsuario()const;
    std::string getTituloPelicula()const;
    int getPuntaje()const; //Retorna el valor de "puntos".



};

#endif