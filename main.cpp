#include "Fabrica.hpp"
/*

*/
#include "IPeliculaController.hpp"
#include "ICineController.hpp"
#include "ISesionUsuarioController.hpp"
#include "IFuncionController.hpp"
#include "IReservaController.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <string>
#include <iostream>
#include <unistd.h>
#include "Usuario.hpp" //Crear el usuario admin por defecto
using namespace std;
 
Fabrica *f;
ISesionUsuarioController* iSesUsCont;
/*
*/
IReservaController* IReservaCont;
ICineController *iCineCont;
IPeliculaController* iPeliCont;
IFuncionController *iFunCont;

void limpiarPantalla(){
    sleep(1*0.1*0);
    system("clear");
    fflush(stdout);
}
//Auxliares
void agregarPeliculaACine(std::string peli , int idCine){
    iCineCont->agregarPeliculaACine(peli , idCine);
}
//Auxiliares de impresion
 void imprimirPeliculas(vector <DtPelicula> pelis){
    
    for(vector<DtPelicula>::iterator it = pelis.begin(); it != pelis.end(); it++){
        DtPelicula peliculaActual = *it; //desreferencio el iterador para obtener el objeto actual
        cout << "--------------" << endl;
        cout << "Titulo: " << peliculaActual.getTitulo() << endl;
        cout << "Sinopsis: " << peliculaActual.getSinopsis() << endl;
        cout << "Puntaje Promedio: " << peliculaActual.getPuntajePromedio() << endl;
        cout << "Poster: " << peliculaActual.getPoster() << endl;
        cout << "--------------" << endl;
    }
}
void imprimirCines(vector <DtCine> cines){
    for(vector<DtCine>::iterator it = cines.begin(); it != cines.end(); it++){ //recorro los DtCine
        DtCine cineActual = *it; //desreferencio el iterador para obtener el objeto actual
        cout << "--------------" << endl;
        cout << "ID: " << cineActual.getId() << endl;
        cout << "Direccion: " << cineActual.getDireccion() << endl;
        cout << "--------------" << endl;

    }
}
void imprimirSalas(vector <DtSala> salasImprimir){
    for(vector<DtSala>::iterator it = salasImprimir.begin(); it != salasImprimir.end(); it++){ //recorro los DtSala
        DtSala salaActual = *it; //desreferencio el iterador para obtener el objeto actual
        cout << "--------------" << endl;
        cout << "ID: " << salaActual.getId() << endl;
        cout << "Capacidad: " << salaActual.getCapacidad() << endl;
        cout << "--------------" << endl;
    }
}
void imprimirFunciones(vector <DtFuncion> impFuncion){
    for(vector<DtFuncion>::iterator it = impFuncion.begin(); it != impFuncion.end(); it++){
        DtFuncion funAct = *it; //desreferencio el iterador para obtener el objeto actual
        cout << "--------------" << endl;
        cout << "ID: " << funAct.getId() << endl;
        cout << "Horario: " << funAct.getHorario().getHoraComienzo() << "  " << funAct.getHorario().getHoraFin() << endl;
        cout << "Sala: " << funAct.getSala().getId() << endl;
        cout << "Pelicula: " << funAct.getPelicula().getTitulo() << endl;
        cout << "--------------" << endl;

    }
}
// Menu
void menuSes() {
    limpiarPantalla();
    cout << "\033[1;33m╔═══════════════════════════════════╗\033[0m" << endl;
    cout << "\033[1;33m║\033[0m       \033[1;34m   Menu Principal    \033[0m       \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m╠═══════════════════════════════════╣\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m1.\033[0m Iniciar Sesion                \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m2.\033[0m Alta Usuario                  \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m0.\033[0m Cerrar programa               \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m╚═══════════════════════════════════╝\033[0m" << endl;
    cout << "\033[1;35mIngrese una opción:\033[0m ";
}

void menuAdmin() {
    limpiarPantalla();
    cout << "\033[1;33m╔════════════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[1;33m║\033[0m         \033[1;34m    Menu - Sesion Admin       \033[0m         \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m╠════════════════════════════════════════════════╣\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m1.\033[0m Cerrar Sesion                              \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m2.\033[0m Alta Pelicula                              \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m3.\033[0m Alta Cine                                  \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m4.\033[0m Alta Funcion                               \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m5.\033[0m Ver Reservas de Pelicula                   \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m6.\033[0m Eliminar Pelicula                          \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m7.\033[0m Ver Información de Pelicula                \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m8.\033[0m Ver Comentarios y Puntaje de Pelicula      \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m╚════════════════════════════════════════════════╝\033[0m" << endl;
    cout << "\033[1;35mIngrese una opción:\033[0m ";
}

void menuUsuario() {
    limpiarPantalla();
    cout << "\033[1;33m╔═════════════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[1;33m║\033[0m         \033[1;34m    Menu - Sesion Usuario    \033[0m           \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m╠═════════════════════════════════════════════════╣\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m1.\033[0m Cerrar Sesion                               \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m2.\033[0m Crear Reserva                               \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m3.\033[0m Puntuar Pelicula                            \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m4.\033[0m Comentar Pelicula                           \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m5.\033[0m Ver Información de Pelicula                 \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m║\033[0m  \033[1;32m6.\033[0m Ver Comentarios y Puntaje de Pelicula       \033[1;33m║\033[0m" << endl;
    cout << "\033[1;33m╚═════════════════════════════════════════════════╝\033[0m" << endl;
    cout << "\033[1;35mIngrese una opción:\033[0m ";
}

//══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════//

// 1. Iniciar Sesion
void iniciarSesion(bool& admin, int& op){
    //Pedir Datos
    std::string nickname;
    std::string contrasenia;
    std::cout << "\033[1;33m      ┌──────────────────────┐\033[0m" << endl;
    std::cout << "\033[1;33m      │   \033[0m\033[1;34m Iniciar Sesion   \033[0m \033[1;33m│\033[0m" << endl;
    std::cout << "\033[1;33m      └──────────────────────┘\033[0m" << endl;
    std::cout << "\033[34mIngrese su nickname:\033[0m ";
    std::cin >> nickname;
    iSesUsCont->ingresarNombreUsuario(nickname);
    bool quiereRepetir = true;
    while(quiereRepetir == true){
        std::cout << "\033[34mIngrese la contrasenia:\033[0m ";
        std::cin >> contrasenia;
        iSesUsCont->ingresarContraseniaUsuario(contrasenia);
        //Confirmar la sesion.
        try{
            iSesUsCont->confirmarSesion();
            quiereRepetir = false;
            //Chequear si el usuario es admin
            if(iSesUsCont->getUsuarioActual()->esAdmin()){
                admin = true;
            }
            else{
                admin = false;
            }
                        
        }
        catch(std::invalid_argument& e){//Si se equivoca confirmarSesion tira error. Aca se maneja.
            cout << e.what() << endl; //Imprime el mensaje del error encontrao.
            std::cout << "\033[31mIntentar de nuevo? 1:Si 0:No\033[0m" << std::endl;
            cin >> quiereRepetir;
            if (!quiereRepetir)
                op=9;
        }
    }
}

// 3. Alta Usuario
void altaUsuario(){
    string nickname;
    string contrasenia;
    bool quiereRepetir = true;
    bool ingresarFoto = false;
    while(quiereRepetir){
        std::cout << "\033[1;33m      ┌──────────────────────┐\033[0m" << endl;
        std::cout << "\033[1;33m      │   \033[0m\033[1;34m  Alta Usuario    \033[0m \033[1;33m│\033[0m" << endl;
        std::cout << "\033[1;33m      └──────────────────────┘\033[0m" << endl;
        cout << "\033[34mIngrese el nickname del usuario a dar de alta:\033[0m ";
        cin >> nickname;                    
        cout << "\033[34mIngrese el contrasenia del usuario a dar de alta:\033[0m ";
        cin >>contrasenia;
        try{
            iSesUsCont->crearUsuario(nickname , contrasenia);
            quiereRepetir = false;
            cout << "\033[34mDesea ingresar foto? 1:Si 0:No\033[0m " << endl;
            cin >> ingresarFoto;
            string urlFoto;
                            
            iSesUsCont->confirmarAltaUsuario(); //Separados la creacion del usuario y el seteo de la foto.

            if(ingresarFoto){
                cout << "\033[34mIngrese el url: \033[0m ";
                cin >> urlFoto;
                iSesUsCont->agregarFoto(urlFoto);
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl; //Imprime el mensaje del error encontrao.
            cout << "\033[31mReintentar? 1:Si 0:No\033[0m" << endl;
            cin >> quiereRepetir;
        }
    }
}

// 4. Alta Pelicula 
void altaPelicula(){
    bool quiereAgregarPeli = true;
    std::string tituloNuevaPeli;
    std::string sinopsisNuevaPeli;
    std::string urlPosterNuevaPeli;
    vector<pair<string , int>> peliculasAAgregarACines;//Solucion elegante.
    while(quiereAgregarPeli){
        cout << "Ingrese el titulo de la nueva pelicula: ";
        cin >> tituloNuevaPeli;

        cout << "Ingrese la sinopsis de la nueva pelicula: ";
        cin >> sinopsisNuevaPeli;
        
        cout << "Ingrese el url del poster de la nueva pelicula: ";
        cin >> urlPosterNuevaPeli;
        try{
            iPeliCont->agregarPelicula(tituloNuevaPeli, sinopsisNuevaPeli , urlPosterNuevaPeli);
            //Agregar peli a un cine
            bool agregarPeliACine = true;
            while(agregarPeliACine){
                int op;
                cout << "Agregar la pelicula a un cine? 1:Si 0:No" << endl;
                cin >> op;
                if(op == 1){
                    int idCine;
                    cout << "Ingrese el id del cine: (Por ahora no hay chequeo de si existe hasta el confirmar)" << endl;
                    cin >> idCine;
                    peliculasAAgregarACines.push_back({tituloNuevaPeli , idCine});
                }
                else{
                    agregarPeliACine = false;
                }
            }

        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
        }
        cout << "Agregar otra pelicula? 1:Si 0:No(Confirmar peliculas) 2:Cancelar" << endl;
        int op;
        cin >> op;
        if(op == 0){
            iPeliCont->confirmarAltaPelicula();
            for(pair<string , int> par : peliculasAAgregarACines){
                agregarPeliculaACine(par.first , par.second);
            }
            quiereAgregarPeli = false;
        }
        else if(op == 2){
            quiereAgregarPeli = false;
        }
    }
}
// 5. Alta Cine
void altaCine(){
    bool quiereAgregarCine = true;
    bool quiereAgregarSala = true;
    std::vector<int> capNuevasSalas;
    string dirCine;
    unsigned int capNuevaSala;
    unsigned int op;
    while(quiereAgregarCine == true){
        cout << "Ingrese la direccion del nuevo cine." << endl;
        cin >> dirCine;
        iCineCont->agregarDireccion(dirCine); // Recuerda la direccion en un vector string.
        while(quiereAgregarSala){
            cout << "Ingrese la capacidad de la nueva sala." << endl;
            cin >> capNuevaSala;
            capNuevasSalas.push_back(capNuevaSala);
            cout << "Desea agregar otra sala al cine? 1:Si 0:No" << endl;
            cin >> op;
            if(op == 0){
                quiereAgregarSala = false;
                iCineCont->ingresarSalas(capNuevasSalas);
            }
        }
        //Aca mate un ConfirmarCine, porque no servia pa na, bah, mas bien complicaba mas la cuestion.
        cout << "Desea agregar otro cine? 1:Si 0:No(Confirmar Cines) 2:Cancelar operacion" << endl;
        cin >> op;
        if(op ==2){
            iCineCont->cancelarCine();
            quiereAgregarCine = false;
        }
        else if(op == 0){
            try{
                iCineCont->confirmarAltaCine();//Deberia por cada direccion guardada crear un cine con tantas salas como haya en el vector de capacidades de la misma posicion que la direccion. Confien.
                quiereAgregarCine = false;
            }
            catch(invalid_argument& e){
                cout << e.what() << endl;
            }
        }
        //Si es 1 o cualquier otra cosa lo confirma, lol.
    }
}
// 6. Alta Función
void altaFuncion(){
    bool SeguirAgregandoFunciones= true;
    imprimirPeliculas(iFunCont->listarPeliculas());
    string tituloNuevaPeli;
    int idCine;
    int anioGuardado;
    int mesGuardado;
    int diaGuardado;
    string horaComienzoActual;
    string horaFinActual;
    int idSalaNueva;
    cout << "Ingrese el titulo de la pelicula." << endl;
    cin >> tituloNuevaPeli;
    iFunCont->eligePelicula(tituloNuevaPeli);

    while(SeguirAgregandoFunciones){
        try{
            imprimirCines(iFunCont->listarCines());
            cout << "Elija el cine donde sera la funcion: " << endl;
            cin >> idCine;
            iFunCont->eligeCine(idCine);
            imprimirSalas(iFunCont->listarSalas());
            cout << "Elija la sala donde sera la funcion: "<< endl;
            cin >> idSalaNueva;
            iFunCont->eligeSala(idSalaNueva);
            cout<< "ingrese el anio" << endl;
            cin>> anioGuardado;
            cout<<"ingrese el mes"<< endl;
            cin>> mesGuardado;
            cout<<"ingrese el dia"<< endl;
            cin>> diaGuardado;
            cout<<"ingrese la hora de comienzo"<< endl;
            cin>> horaComienzoActual;
            cout<<"ingrese la hora final"<< endl;
            cin>> horaFinActual;
            DtFecha fechaNueva(anioGuardado,mesGuardado,diaGuardado);
            DtHorario horarioNuevo(horaComienzoActual,horaFinActual);

        iFunCont->recordarHorario(fechaNueva,horarioNuevo);
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
        }
        
        cout << "Desea agregar otra funcion? 1:Si 0:No(Confirmar Funcion)"<< endl;
        int op;
        cin >> op; 
        if(op ==0){
            try{
                iFunCont->confirmarAltaFuncion();
                SeguirAgregandoFunciones= false;
            }
            catch(invalid_argument& e){
                cout << e.what() << endl;
                SeguirAgregandoFunciones= false;
            }
        }

    }


}
// 7. Crear Reserva
void CrearReserva(){
    int op;
    string nuevoTitulo;
    DtPelicula peliculaActual;
    int idCine;
    int idNuevoCine;
    int idFuncionActual;
    bool quieroAgregarPeliculas= true;
    int metodo;
    string nombreBanco;
    string nombreFinanciera;
    int cantAsientos;
    while(quieroAgregarPeliculas){
        //imprimirPeliculas(IReservaCont->listarPeliculas());
        cout << "quiere elegir un titulo o salir? 1:seleccionar titulo 0:cancelar(cancelaCompra)" << endl;
        cin >> op;  
        if(op ==0){
            quieroAgregarPeliculas= false;
            IReservaCont->cancelaCompra(); 
        }
        else if(op ==1){
            imprimirPeliculas(IReservaCont->listarPeliculas());
            cout <<"que titulo quiere seleccionar?:"<< endl;
            cin >>nuevoTitulo;
            peliculaActual = IReservaCont->eligePelicula(nuevoTitulo);
            //peliculaActual= iPeliCont->obtenerPosterSipnosisDeLaPelicula(nuevoTitulo);
            cout << endl << peliculaActual.getTitulo() << endl;
            cout << endl << "Sinopsis: "<< peliculaActual.getSinopsis() << endl;
            cout<<"elija una opcion: 1:seguir con la reserva y ver informacion adicional 0:cancelar reserva"<< endl;
            cin>> op;
            if(op ==0){
                IReservaCont->cancelaCompra();
            }
            else{
                imprimirCines(IReservaCont->listarCinesdePelicula(nuevoTitulo));
                cout<<"elija una opcion: 1:seleccionar un cine, 0:cancelar reserva" << endl;
                cin >> op;
                if(op ==0){
                    IReservaCont->cancelaCompra();
                }
                else if(op== 1){
                    //imprimirCines(IReservaCont->listarCinesdePelicula(nuevoTitulo));
                    cout<<"Ingrese el id del cine:"<< endl;
                    cin>> idCine;
                    try{

                    

                    IReservaCont->eligeCine(idCine); 
                    
                    imprimirFunciones(IReservaCont->listarFuncionDeCine(idCine));
                    cout<<"elija la funcion"<< endl;
                    cin>> idFuncionActual;
                    IReservaCont->seleccionaFuncion(idFuncionActual);
                    cout<<"ingrese la cantidad de asientos que desea reservar:"<< endl;
                    cin>> cantAsientos;
                    if(IReservaCont->ComprobarLugarDeAsientos(cantAsientos,idFuncionActual)){
                        cout<<"ingrese el metodo de pago 1:Credito 2:Debito"<< endl;
                        cin>> metodo;
                        if(metodo== 1){
                            cout<<"ingrese el nombre de la financiera"<< endl;
                            cin>> nombreFinanciera;
                            IReservaCont->ingreseNomFinanciera(nombreFinanciera);
                            cout<<"su descuentos es:"<< endl;
                            cout <<IReservaCont->descuentoDe(nombreFinanciera)<< endl;
                        }
                    

                        else if(metodo== 2){
                            cout<<"ingrese el nombre del banco"<< endl;
                            cin>> nombreBanco;
                            IReservaCont->ingreseNomBanco(nombreBanco);
                        }
                    }else{
                    cout<<"error, no hay suficientes hacientos para esta funcion."<< endl;
                    }
                }
                    catch(invalid_argument& e){
                        cout << e.what() << endl;
                    }
                }
            } 

        IReservaCont->precioFinal(IReservaCont->descuentoDe(nombreFinanciera) , cantAsientos);
        cout <<"elija una opcion 1:confirmar compra 0:cancelar compra"<< endl;
        cin>> op;
        if(op== 1){
            TipoReserva tipo = esDebito;
            if(metodo == 1){
                tipo = esCredito;
            }
            IReservaCont->confirmarCompra(iSesUsCont->getUsuarioActual() , tipo , IReservaCont->precioFinal(IReservaCont->descuentoDe(nombreFinanciera) , cantAsientos), cantAsientos);

        }
        else if(op== 0){
            IReservaCont->cancelaCompra();
        }
    
    }
        
  }
}

// 8. Ver Reservas de Pelicula

// 9. Eliminar Pelicula 
void EliminarPelicula(){
    bool quiereEliminarPelicula = true;
    string peliculaElegida;
    int op;
    try{
        cout << "Que pelicula desesa eliminar?"  << endl;
        imprimirPeliculas(iPeliCont->listarPeliculas());
        cin >> peliculaElegida;
        iPeliCont->eligePelicula(peliculaElegida);
        cout << "Confirmar operacion? 1:Si 0:No" << endl;
        cin >> op;
        if(op == 1){
            iPeliCont->borrarPelicula();
        }
        else{
            iPeliCont->cancelarEliminarPelicula();
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}



// 10. Puntuar Pelicula

// 11. Comentar Pelicula

// 12. Ver Informacion Pelicula 

// 13. Ver Comentarios y Puntaje de Pelicula


//══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════//

// MAIN
int main(){
    f = new Fabrica();
    iSesUsCont = f->getISesionUsuarioController();
    iCineCont = f->getICineController();
    iPeliCont = f->getIPeliculaController();
    iFunCont = f->getIFuncionController();
    IReservaCont = f->getIReservaController();
    int op = 1;
    bool admin;
    while( op!=0 ){
        menuSes();
        cin >> op;
        switch (op){
            case 1:{ //Iniciar Sesion.
                limpiarPantalla();
                iniciarSesion(admin, op);
                limpiarPantalla();
                break;}
            case 2 :{ //Alta Usuario.
                limpiarPantalla();
                altaUsuario();
                limpiarPantalla();
                break;}
            case 0 ://chau
                cout << "Chau xd" << endl;
                exit(0);//Temporal xd
        }
        if( (op==1) && (admin) ){//si soy admin...
            menuAdmin();
            cin >> op;
            while( op!=1 ){
                switch (op) {
                    case 2: //Alta Pelicula. Admin
                        altaPelicula();
                    break;
                    case 3: //Alta Cine. Admin
                        altaCine();
                    break;
                    case 4: //Alta Funcion. Admin
                        altaFuncion();
                    break;
                    case 5: //Ver Reservas de Pelicula. Admin
 
                    break;
                    case 6: //Eliminar Pelicula. Admin
                        EliminarPelicula();
                    break;
                    case 7: //Ver Información de Pelicula. Admin

                    break;
                    case 8: //Ver Comentarios y Puntaje de Pelicula. Admin

                    break;
                }
        
                menuAdmin();
                cin >> op;
            }//Termina while de admin, con op=1
        } else 
            if(op==1){//termina if de admin //si soy usuario  
                menuUsuario();
                cin >> op;
                while(op!=1){
                        switch (op) {
                        case 2: //Crear Reserva. 
                            CrearReserva();
                        break;
                        case 3: //Puntuar Pelicula. 
            
                        break;
                        case 4: //Comentar Pelicula. 

                        break;
                        case 5: //Ver Información de Pelicula. 

                        break;
                        case 6: //Ver Comentarios y Puntaje de Pelicula. 

                        break;            
                    }
                    menuUsuario();
                    cin >> op;
                }//Termina while de usuario, con op=1
            }//termina if de usuario


    }//termina cuando estoy en menu de inicio y doy 0

    return 0;
}

