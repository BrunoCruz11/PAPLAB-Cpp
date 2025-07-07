#ifndef CINEHANDLER_HPP
#define CINEHANDLER_HPP
#include "DtCine.hpp"
#include "DtSala.hpp"
#include "DtFuncion.hpp"
#include <vector>
#include "DtPelicula.hpp"


class CineHandler{
    private:
        static CineHandler* instancia;
        CineHandler();
        std::map<int,Cine*> cines; //no tendria que ser "<string, Cine*>"?? en vez de "<int, Cine*>" No, el id es un numero.
        DtCine cineRecordado;
        DtSala salaRecordada;
        DtFuncion FuncionRecordada;
        std::vector <DtFuncion> FuncionesRecordadas;   
        
        int ultimoIdSala;
        int ultimoIdCine;
        
        int darNuevoIdSala();//Aumentan el ultimo id y lo devuelven
        int darNuevoIdCine();

    public:

        static CineHandler* getInstancia();

        Cine* darCine(int id);
        std::vector<DtCine> listarCines();

        std::map <int, Cine*>getColeccionCines();
        std::vector<DtPelicula> darPeliculas();
        DtCine getCine(int idCine);
        std::vector<DtSala> darSalas(DtCine c);
        DtSala getSala(int idSala);
        bool esHorarioDisponible(DtFecha fecha, DtHorario horario,DtCine CineRecordado, DtFecha f);
        void agregarFuncionEnCine(int idFunc ,DtPelicula p, DtCine c, DtSala s, DtHorario horarioNuevo,DtFecha fechaNueva);
        //------------------------------------------------------------------------------------------------------- separar caso de uso
        void RecordarCine (Cine* c);
        void recordarFunciones (std::vector <DtFuncion> FuncionesRecordadas);
        bool hayAsientosDisponiblesEnFuncion(int asientos, int id);
        std::vector <DtCine> darCinesDePelicula (string titulo);
        std::vector <DtFuncion> darFuncionesDeCine(int idCine);
        Reserva* colocarReserva(int idFuncion, TipoReserva tipo, std::string dataTarjeta ,float costo, int cantEntradas, Usuario* u);
        void agregarCine(std::string direccion , vector<int> capacidadesDeSalasNuevas);
        void quitarPeliculaDeCines(string tituloPelicula); //solo elimina la pelicula de los cines, no del sistema
        std:: vector<DtFuncion> listarFuncionesConSusReservasCineHandler(string titulo);
    };

#endif