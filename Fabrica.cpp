#include "Fabrica.hpp"
#include "ISesionUsuarioController.hpp"
#include "SesionUsuarioController.hpp"
#include "CineController.hpp"
#include "IPeliculaController.hpp"
#include "PeliculaController.hpp"
#include "FuncionController.hpp"

/*

   



   IConsultasPeliculasController* getIConsultasPeliculasController(){
      return PeliculaController::getInstancia();
   }
   IComentarioPuntajeController* getIComentarioPuntajeController(){
      return ComentarioPuntajeController::getInstancia();
   }

   IReservaController* getIReservaController(){
      return ReservaController::getInstancia();
   }
   */
   ISesionUsuarioController* Fabrica::getISesionUsuarioController(){
      return SesionUsuarioController::getInstancia();
   }

   ICineController* Fabrica::getICineController(){
      return CineController::getInstancia();
   }
     IPeliculaController* Fabrica::getIPeliculaController(){
     return  PeliculaController::getInstancia();
  }
   IFuncionController* Fabrica::getIFuncionController(){
      return FuncionController::getInstancia();
   }