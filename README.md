# PAV Obligatorio 5 — Sistema de Cine

Proyecto en C++ que simula el manejo de una cadena de cines: alta de películas,
cines y funciones, reserva de entradas, y comentarios/puntajes de películas.
Es una aplicación de consola con menús separados para administrador y usuario.

## Funcionalidades

**Administrador**
- Alta de películas, cines y funciones
- Ver reservas y eliminar películas
- Ver información, comentarios y puntajes de una película

**Usuario**
- Crear una reserva (elige película, cine, función y método de pago)
- Puntuar y comentar películas
- Ver información, comentarios y puntajes de una película

## Arquitectura

El código está organizado en capas:

| Carpeta         | Contenido                                              |
|-----------------|---------------------------------------------------------|
| `Dominio/`      | Clases de dominio (Cine, Pelicula, Usuario, Reserva, etc.) |
| `DTOs/`         | Data Transfer Objects (`Dt*`) usados entre capas         |
| `Interfaces/`   | Interfaces abstractas de los controladores (`I*`)        |
| `Controladores/`| Lógica de cada caso de uso                               |
| `Manejadores/`  | Handlers que administran las colecciones de dominio      |
| `tests/`        | Pruebas puntuales de algunos módulos                     |

`main.cpp` y `Fabrica.cpp/hpp` quedan en la raíz: `Fabrica` arma y conecta
todos los controladores/handlers, y `main` maneja los menús y el flujo del
programa.

## Compilar y ejecutar

Requiere `g++` (MinGW en Windows) y `make` (o `mingw32-make`).

```powershell
mingw32-make.exe
.\main.exe
```

Para limpiar los binarios generados:

```powershell
mingw32-make.exe clean
```
