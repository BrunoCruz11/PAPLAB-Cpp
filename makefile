CXX = g++ # Definir CXX como g++

# Carpetas del proyecto. Se agregan como -I para que los #include "Archivo.hpp"
# sigan funcionando igual sin importar en que carpeta este cada archivo.
INCLUDES = -IDominio -IDTOs -IInterfaces -IControladores -IManejadores
CXXFLAGS = $(INCLUDES)

SRCS = main.cpp Dominio/Cine.cpp Dominio/Comentario.cpp Dominio/Credito.cpp Dominio/Debito.cpp Dominio/Descuentos.cpp DTOs/DtCine.cpp DTOs/DtComentario.cpp DTOs/DtCredito.cpp DTOs/DtDebito.cpp DTOs/DtDireccion.cpp DTOs/DtFecha.cpp DTOs/DtFuncion.cpp DTOs/DtHorario.cpp DTOs/DtPelicula.cpp DTOs/DtPuntaje.cpp DTOs/DtSala.cpp Fabrica.cpp Dominio/Fecha.cpp Dominio/Funcion.cpp  Dominio/Horario.cpp Dominio/Pelicula.cpp  Dominio/Puntaje.cpp Dominio/Reserva.cpp  Dominio/Sala.cpp Controladores/SesionUsuarioController.cpp Dominio/Usuario.cpp Manejadores/UsuarioHandler.cpp DTOs/DtReserva.cpp Controladores/CineController.cpp Manejadores/CineHandler.cpp Controladores/PeliculaController.cpp Manejadores/PeliculaHandler.cpp Controladores/FuncionController.cpp Controladores/ReservaController.cpp  # Archivos fuente.(Los que se van a compilar jeje)
#Provisorio los sacamos:
OBJS = $(SRCS:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

%.o: %.cpp %.hpp # crea los archivos .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp # compila el main solo(no tiene .hpp)
	$(CXX) $(CXXFLAGS) -c main.cpp

clean: # Borrar
	rm -f $(OBJS) $(TARGET)
