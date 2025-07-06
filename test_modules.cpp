#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// Incluir los headers proporcionados
#include "Usuario.hpp"
#include "Pelicula.hpp"
#include "Comentario.hpp"
#include "Puntaje.hpp"
#include "DtComentario.hpp"
#include "DtPelicula.hpp"

using namespace std;

void testUsuario() {
    cout << "=== Probando clase Usuario ===" << endl;
    
    // Crear usuario
    Usuario usuario1("juan123", "password123");
    
    // Probar verificación de credenciales
    assert(usuario1.verificarCredenciales("password123") == true);
    assert(usuario1.verificarCredenciales("wrongpassword") == false);
    
    // Probar getter de nickname
    assert(usuario1.getNickname() == "juan123");
    
    // Probar setFoto
    usuario1.setFoto("http://example.com/foto.jpg");
    
    cout << "Usuario creado: " << usuario1.getNickname() << endl;
    cout << "Verificación de credenciales: OK" << endl;
    cout << "Set foto: OK" << endl;
    cout << "✓ Pruebas de Usuario completadas" << endl << endl;
}

void testPelicula() {
    cout << "=== Probando clase Pelicula ===" << endl;
    
    // Crear película
    Pelicula pelicula1("Inception", "Una película sobre sueños", "poster_inception.jpg");
    
    // Probar métodos básicos
    assert(pelicula1.esTitulo("Inception") == true);
    assert(pelicula1.esTitulo("Matrix") == false);
    assert(pelicula1.getTitulo() == "Inception");
    assert(pelicula1.getPoster() == "poster_inception.jpg");
    
    cout << "Película creada: " << pelicula1.getTitulo() << endl;
    cout << "Verificación de título: OK" << endl;
    cout << "Poster: " << pelicula1.getPoster() << endl;
    
    // Probar constructor de copia
    Pelicula pelicula2(pelicula1);
    assert(pelicula2.getTitulo() == "Inception");
    cout << "Constructor de copia: OK" << endl;
    
    cout << "✓ Pruebas de Pelicula completadas" << endl << endl;
}

void testPuntaje() {
    cout << "=== Probando clase Puntaje ===" << endl;
    
    // Crear usuario y película para el puntaje
    Usuario* usuario = new Usuario("maria456", "pass456");
    Pelicula* pelicula = new Pelicula("Avatar", "Película de ciencia ficción", "avatar_poster.jpg");
    
    // Crear puntaje
    Puntaje puntaje1(8, usuario, pelicula);
    assert(puntaje1.getPuntaje() == 8);
    
    // Probar constructor de copia
    Puntaje puntaje2(puntaje1);
    assert(puntaje2.getPuntaje() == 8);
    
    cout << "Puntaje creado: " << puntaje1.getPuntaje() << " puntos" << endl;
    cout << "Constructor de copia: OK" << endl;
    cout << "✓ Pruebas de Puntaje completadas" << endl << endl;
    
    // Limpiar memoria
    delete usuario;
    delete pelicula;
}

void testComentario() {
    cout << "=== Probando clase Comentario ===" << endl;
    
    // Crear usuario y película para el comentario
    Usuario* usuario = new Usuario("carlos789", "pass789");
    Pelicula* pelicula = new Pelicula("Interstellar", "Viaje espacial épico", "interstellar_poster.jpg");
    
    // Crear comentario principal
    Comentario* comentario1 = new Comentario("Excelente película!", pelicula, usuario);
    
    assert(comentario1->getTexto() == "Excelente película!");
    assert(comentario1->getPelicula() == pelicula);
    assert(comentario1->getUsuario() == usuario);
    assert(comentario1->getRespondeA() == nullptr); // Es comentario principal, no respuesta
    
    // Crear respuesta al comentario
    Usuario* usuario2 = new Usuario("ana321", "pass321");
    Comentario* respuesta = new Comentario("Totalmente de acuerdo!", comentario1, usuario2);
    
    assert(respuesta->getTexto() == "Totalmente de acuerdo!");
    assert(respuesta->getRespondeA() == comentario1);
    assert(respuesta->getUsuario() == usuario2);
    
    // Agregar respuesta al comentario original
    comentario1->agregarRespuesta(respuesta);
    
    // Verificar que la respuesta se agregó
    vector<Comentario*> respuestas = comentario1->getCopiaRespuestas();
    assert(respuestas.size() == 1);
    assert(respuestas[0] == respuesta);
    
    cout << "Comentario principal: " << comentario1->getTexto() << endl;
    cout << "Respuesta: " << respuesta->getTexto() << endl;
    cout << "Usuario del comentario: " << comentario1->getUsuario()->getNickname() << endl;
    cout << "Usuario de la respuesta: " << respuesta->getUsuario()->getNickname() << endl;
    cout << "Número de respuestas: " << respuestas.size() << endl;
    
    // Probar constructor de copia
    Comentario comentario2(*comentario1);
    assert(comentario2.getTexto() == "Excelente película!");
    cout << "Constructor de copia: OK" << endl;
    
    cout << "✓ Pruebas de Comentario completadas" << endl << endl;
    
    // Limpiar memoria
    delete comentario1;
    delete respuesta;
    delete usuario;
    delete usuario2;
    delete pelicula;
}

void testDtComentario() {
    cout << "=== Probando clase DtComentario ===" << endl;
    
    // Crear DtComentario para película
    DtComentario dt1("Gran película", "usuario123", "Titanic");
    
    assert(dt1.getTexto() == "Gran película");
    assert(dt1.getNicknameUsuario() == "usuario123");
    assert(dt1.getTituloP() == "Titanic");
    
    // Crear DtComentario como respuesta
    //DtComentario dt2("Estoy de acuerdo", "usuario456", dt1);
    
    //assert(dt2.getTexto() == "Estoy de acuerdo");
    //assert(dt2.getNicknameUsuario() == "usuario456");
    
    // Probar constructor de copia
    DtComentario dt3(dt1);
    assert(dt3.getTexto() == "Gran película");
    assert(dt3.getNicknameUsuario() == "usuario123");
    
    cout << "DtComentario principal: " << dt1.getTexto() << endl;
    cout << "Usuario: " << dt1.getNicknameUsuario() << endl;
    cout << "Película: " << dt1.getTituloP() << endl;
    //cout << "DtComentario respuesta: " << dt2.getTexto() << endl;
    cout << "Constructor de copia: OK" << endl;
    cout << "✓ Pruebas de DtComentario completadas" << endl << endl;
}

/*void testDtPelicula() {
    cout << "=== Probando clase DtPelicula ===" << endl;
    
    // Crear DtPelicula
    DtPelicula dt1("Matrix", "Realidad virtual", 9.5f, "matrix_poster.jpg");
    
    assert(dt1.getTitulo() == "Matrix");
    assert(dt1.getSinopsis() == "Realidad virtual");
    assert(dt1.getPuntajePromedio() == 9.5f);
    assert(dt1.getPoster() == "matrix_poster.jpg");
    
    // Probar constructor de copia
    DtPelicula dt2(dt1);
    assert(dt2.getTitulo() == "Matrix");
    assert(dt2.getPuntajePromedio() == 9.5f);
    
    cout << "DtPelicula: " << dt1.getTitulo() << endl;
    cout << "Sinopsis: " << dt1.getSinopsis() << endl;
    cout << "Puntaje promedio: " << dt1.getPuntajePromedio() << endl;
    cout << "Poster: " << dt1.getPoster() << endl;
    cout << "Constructor de copia: OK" << endl;
    cout << "✓ Pruebas de DtPelicula completadas" << endl << endl;
}
*/
int main() {
    cout << "===========================================" << endl;
    cout << "    PRUEBAS DE MÓDULOS DEL SISTEMA" << endl;
    cout << "===========================================" << endl << endl;
    
    try {
        testUsuario();
        testPelicula();
        testPuntaje();
        testComentario();
        testDtComentario();
        //testDtPelicula();
        
        cout << "===========================================" << endl;
        cout << "✓ TODAS LAS PRUEBAS COMPLETADAS CON ÉXITO" << endl;
        cout << "===========================================" << endl;
        
    } catch (const exception& e) {
        cout << "❌ Error durante las pruebas: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}