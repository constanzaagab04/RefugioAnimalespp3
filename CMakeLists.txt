# Versión mínima de CMake necesaria
cmake_minimum_required(VERSION 3.10)

# 1. Definición del Proyecto 
project(RefugioAnimales CXX)

# 2. Configuración del Estándar C++11 (Corrige los errores de 'C++11 extension')
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Rutas donde se buscarán los archivos de cabecera (.h)
include_directories(include
        include/Base
        include/Utilidad
        include/Dominio
        include/Core)

# 3. LISTA COMPLETA DE ARCHIVOS FUENTE (.cpp)
# (Corrige los errores de 'Undefined symbols' de la fase de Linker)
set(SOURCE_FILES
        # Archivo principal
        main.cpp

        # Archivos de Implementación Base y Dominio
        src/Animal.cpp
        src/Persona.cpp
        src/ControlVeterinario.cpp
        src/Cuidador.cpp
        src/Adopcion.cpp
        src/Refugio.cpp

        # Implementaciones Específicas
        src/Perro.cpp
        src/Gato.cpp
        src/Vacunacion.cpp
        src/Desparasitacion.cpp
)

# Compila y enlaza el ejecutable con todos los archivos listados
add_executable(RefugioAnimales ${SOURCE_FILES})

# 4. ENLACE DE LIBRERÍAS EXTERNAS 
target_link_libraries(RefugioAnimales ncurses)
