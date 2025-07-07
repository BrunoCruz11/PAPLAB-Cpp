CXX = g++ # Definir CXX como g++

SRCS = main.cpp Cine.cpp Comentario.cpp Credito.cpp Debito.cpp Descuentos.cpp DtCine.cpp DtComentario.cpp DtCredito.cpp DtDebito.cpp DtDireccion.cpp DtFecha.cpp DtFuncion.cpp DtHorario.cpp DtPelicula.cpp DtPuntaje.cpp DtSala.cpp Fabrica.cpp Fecha.cpp Funcion.cpp  Horario.cpp Pelicula.cpp  Puntaje.cpp Reserva.cpp  Sala.cpp SesionUsuarioController.cpp Usuario.cpp UsuarioHandler.cpp DtReserva.cpp CineController.cpp CineHandler.cpp PeliculaController.cpp PeliculaHandler.cpp FuncionController.cpp ReservaController.cpp  # Archivos fuente.(Los que se van a compilar jeje)
#Provisorio los sacamos:      
OBJS = $(SRCS:.cpp=.o)	

TARGET = main	

all: $(TARGET)

$(TARGET): $(OBJS)	
	$(CXX) -o $(TARGET) $(OBJS)	

%.o: %.cpp %.hpp # crea los archivos .o
	$(CXX) -c $< -o $@

main.o: main.cpp # compila el main solo(no tiene .hpp)
	$(CXX) -c main.cpp

clean: # Borrar
	rm -f *.o $(TARGET)
