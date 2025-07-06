#ifndef ISESIONUSUARIOCONTROLLER_HPP
#define ISESIONUSUARIOCONTROLLER_HPP

#include "Usuario.hpp"

class ISesionUsuarioController{
    public:
        virtual Usuario* getUsuarioActual()=0;
        
        virtual void setNicknameRecordado(std::string N)=0;
        virtual void setContraseniaRecordada(std::string C)=0;

        virtual void ingresarNombreUsuario(std::string N)=0;
        virtual void ingresarContraseniaUsuario(std::string C)=0;
        virtual void confirmarSesion()=0;

        virtual void crearUsuario(std::string nickname , std::string contrasenia)=0;
        virtual void agregarFoto(std::string urlFoto)=0;
        virtual void confirmarAltaUsuario()=0;

        virtual void cerrarSesion()=0;
        virtual void confirmarCerrarSesion()=0;
};
#endif