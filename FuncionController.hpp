#ifndef FUNCIONCONTROLLER_HPP
#define FUNCIONCONTROLLER_HPP
#include <vector>
#include <string>

#include "DtPelicula.hpp"
#include "DtCine.hpp"
#include "DtSala.hpp"
#include "DtHorario.hpp"
#include "DtFecha.hpp"
#include "DtFuncion.hpp"

#include "IFuncionController.hpp"
#include "CineHandler.hpp"
#include "PeliculaHandler.hpp"


class FuncionController : public IFuncionController{
    private:
        int ultimoIdFuncion;

        static FuncionController* instancia;  
        FuncionController();
        ~FuncionController();   

        DtPelicula PeliculaRecordada;
        DtSala salaRecordada;
        DtFecha fechaRecordada;
        DtHorario horarioRecordado;
        DtCine cineRecordado;
        std:: vector<DtCine> cinesRecordados;
        std:: vector<DtSala> salasRecordadas;
        std:: vector<DtHorario> horariosRecordados;
        std:: vector <DtFecha> fechaRecordadas;
        CineHandler* manejadorCine;
        PeliculaHandler* manejadorPelicula;
    public:
        static FuncionController* getInstancia();

        int getNuevoIdFuncion();

        std::vector<DtPelicula> listarPeliculas();
        void eligePelicula(string titulo);
        std::vector<DtCine> listarCines();
        void eligeCine(int id);
        std::vector<DtSala> listarSalas();
        void eligeSala(int id);
        //DtHorario asignarHorario(DtFecha fecha, DtHorario horario);
        void confirmarAltaFuncion();
        //void recordarFuncion(DtFuncion func);
        //void recordarPelicula(DtPelicula peli);
        //void RecordarCine(DtCine cine);
        void recordarHorario(DtFecha fecha, DtHorario horario);

};



#endif