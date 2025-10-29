#ifndef REFUGIO_H
#define REFUGIO_H

#include "Utilidad/ContenedorDinamico.h"
#include "Base/Animal.h"
#include "Dominio/Cuidador.h"
#include "Dominio/Adopcion.h"
#include "Base/ControlVeterinario.h"
#include "Utilidad/Enums.h"
#include <iostream>
#include <string>

class Refugio {
public:
    ContenedorDinamico<Animal> repoAnimales;
    ContenedorDinamico<Cuidador> repoCuidadores;
    ContenedorDinamico<Adopcion> repoAdopciones;
    ContenedorDinamico<ControlVeterinario> repoControles;

    Refugio();
    ~Refugio();

    // CRUD
    void altaAnimal(Animal* a);
    void bajaAnimal(int idAnimal);
    void altaControl(ControlVeterinario* c);

    // Módulo Cuidadores (CRUD)
    void altaCuidador(Cuidador* c); // Declaración unica
    void bajaCuidador(int id);
    void buscarYMostrarCuidador(int id);

    // modulo Animales (CRUD)
    void buscarYMostrarAnimal(int id);
    void modificarAnimal(int id);

    // Funcionalidades Clave
    void asignarAnimalACuidador(int idCuidador, int idAnimal);
    void avanzarEstadoAdopcion(int idAdopcion);
    void retrocederEstadoAdopcion(int idAdopcion);
    void ordenarAnimalesPorEdad();

    // Reportes
    void mostrarEstadisticas() const;
    void listarAdopcionesPorEstado(EstadoAdopcion estado) const;
    void listarReporteCuidadores() const;
    void reporteHistorialVeterinario(int idAnimal) const;

    // Listar Genérico (Polimorfismo y Sobrecarga <<)
    template <class T>
    void listarGenerico(ContenedorDinamico<T>& repo, const std::string& titulo) const {
        std::cout << "\n--- LISTA DE " << titulo << " (" << repo.getCantidad() << ") ---\n";
        if (repo.getCantidad() == 0) {
            std::cout << "  (No hay registros).\n";
            return;
        }
        for (const auto& item : repo) {
            std::cout << *item << std::endl;
        }
    }
};
#endif // REFUGIO_H
