#ifndef FABRICA_HPP
#define FABRICA_HPP
#include "IPeliculaController.hpp"
#include "ICineController.hpp"
#include "IFuncionController.hpp"
//#include "IConsultasPeliculasController.hpp"
//#include "IComentarioPuntajeController.hpp"
#include "IReservaController.hpp"
#include "ISesionUsuarioController.hpp"


class Fabrica{
    private:
        static Fabrica* instancia;
    public:
        IPeliculaController* getIPeliculaController();
        ICineController* getICineController();
        IFuncionController* getIFuncionController();
//        IConsultasPeliculasController* getIConsultasPeliculasController();
//        IComentarioPuntajeController* getIComentarioPuntajeController();
        IReservaController* getIReservaController();
        ISesionUsuarioController* getISesionUsuarioController();


};


#endif