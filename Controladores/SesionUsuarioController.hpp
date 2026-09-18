#ifndef SESIONUSUARIOCONTROLLER_HPP
#define SESIONUSUARIOCONTROLLER_HPP
#include <string>
#include "UsuarioHandler.hpp"
#include "ISesionUsuarioController.hpp"
class SesionUsuarioController : public ISesionUsuarioController { //Temita con la sesion. Para obtener el usuario actual tienen que comunicarse entre controladores(Indeseado).
    private:
        static SesionUsuarioController* instancia;
        SesionUsuarioController();
        ~SesionUsuarioController();

        std::string nicknameRecordado;
        std::string contraseniaRecordada;
        std::string urlRecordada;
        Usuario* usuarioActivo;//Es null si la sesion no esta iniciada
        UsuarioHandler* UH;
    public:
        static SesionUsuarioController* getInstancia();

        Usuario* getUsuarioActual();
        
        //void setNicknameActivo(std::string N); No se usa al final porque se usa puntero al usuario activo.
        void setNicknameRecordado(std::string N);
        void setContraseniaRecordada(std::string C);

        void ingresarNombreUsuario(std::string N);
        void ingresarContraseniaUsuario(std::string C);
        void confirmarSesion();//Setea como activo al usuario. Usar solo nickname o puntero a usuario?

        void crearUsuario(std::string nickname , std::string contrasenia);//Recuerda ambos parametros.
        void agregarFoto(std::string urlFoto);
        void confirmarAltaUsuario();

        void cerrarSesion();
        void confirmarCerrarSesion();

        

    };


#endif