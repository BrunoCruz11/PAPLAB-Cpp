#ifndef CINECONTROLLER_HPP
#define CINECONTROLLER_HPP
#include "CineHandler.hpp"
#include "ICineController.hpp"
#include "PeliculaHandler.hpp"
#include "DtSala.hpp"
#include <vector>
#include <string>

class CineController : public ICineController{
    private: 
        static CineController* instancia;
        CineController();
        ~CineController();
        std::vector<std::string> direcciones;
        std::vector <std::vector<int>> nuevasSalas;
        std::vector <DtCine> CinesRecordados;
        CineHandler* manejadorCine;
        PeliculaHandler* manejadorPelicula;
    public:
        static CineController* getInstancia();
        void agregarDireccion(string Direccion); // le cambie de nombre porque en realidada le agregas la direccion nomas no el cine en si
        void ingresarSalas(std::vector<int>);//Guarda el vector en el vector de vectores nuevas salas.
        //void confirmarCine();
        void cancelarCine();
        void confirmarAltaCine();
        void agregarPeliculaACine(std::string titulo , int id);
};


#endif