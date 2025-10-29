README

Sistema de Gestión de Refugio de Animales (C++ Avanzado)

¿Qué es el Proyecto?
Este es un Sistema Integral de Gestión (Backend) para un Refugio de Animales, desarrollado completamente en C++ con una interfaz de consola interactiva.
El proyecto es una demostración de Programación Orientada a Objetos (POO) avanzada, aplicando conceptos como Herencia Polimórfica, Plantillas (template) para la gestión genérica de datos, Sobrecarga de Operadores, y una interfaz de usuario creada con la librería ncurses.

Funcionalidades Clave

Gestión de Entidades: Alta, baja, modificación y listado de Animales (Perros/Gatos), Cuidadores, Controles Veterinarios, y Adopciones.
Lógica de Negocio: Asignación de Animales a Cuidadores con restricción de Carga Máxima. Transacciones: Control de estado de adopción mediante sobrecarga de operadores (++ y --). Reportes: Generación de listados filtrados y ordenados (ej., Animales por edad).

Utilidad

Este sistema resuelve la necesidad de una gestión robusta y eficiente de un refugio, mientras demuestra el uso de patrones de diseño de software de alto nivel.
Eficiencia POO: Utiliza el Patrón Repositorio (ContenedorDinamico<T>) implementado con Plantillas, lo que permite una reutilización de código del 100% para las operaciones básicas (CRUD) en todas las entidades.
Robustez: Incluye soluciones para problemas comunes en C++, como la limpieza crítica del buffer de I/O para garantizar que la entrada de datos (cin) no falle después de usar la interfaz de ncurses.
Visión a Futuro (IA): El sistema está diseñado para integrarse con un Asistente Inteligente (Scikit-learn), permitiendo predicciones de visitas y recomendaciones clínicas personalizadas, lo que optimiza la toma de decisiones.

¿Cómo Empezar? (Compilación y Ejecución)

El proyecto está diseñado para compilarse usando CMake en un entorno Unix (macOS o Linux).\
Requisitos
Compilador C++ (g++ o clang) CMake
Librería ncurses (generalmente incluida o instalable con sudo apt install libncurses5-dev). Pasos de Ejecución
1. Clonar el Repositorio: Bash
2. Compilar (Usando CMake): Bash
3. Ejecutar el Binario (CRÍTICO):

IMPORTANTE!!!! Debe ejecutar el programa directamente en la Terminal nativa para que la interfaz ncurses
funcione correctamente (evitando los problemas de la consola de CLion). Bash
    ./RefugioAnimales
