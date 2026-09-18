#ifndef ICINECONTROLLER_HPP
#define ICINECONTROLLER_HPP

#include<string>
#include "Cine.hpp"
class ICineController{
    private:
    public:

        virtual void agregarDireccion(std::string Direccion)= 0; // le cambie de nombre porque en realidada le agregas la direccion nomas no el cine en si
        //virtual void RecuerdaNuevoCine(std::string Direccion)= 0;
        virtual void ingresarSalas(std::vector<int> salas)= 0;
        //virtual void recuerdaCineYSalas(Cine* c, std::vector<Sala> salas)= 0;
        //virtual void confirmarCine()= 0;
        virtual void cancelarCine()= 0;
        virtual void confirmarAltaCine()= 0;

        virtual void agregarPeliculaACine(std::string titulo , int id) = 0;
        virtual ~ICineController() = default;


};
 #endif