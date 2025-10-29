#include "Core/Refugio.h"
#include "Dominio/Perro.h"
#include "Dominio/Gato.h"
#include "Dominio/Vacunacion.h"
#include "Dominio/Desparasitacion.h"
#include <stdexcept>
#include <algorithm>

Refugio::Refugio() {
    // Datos iniciales de prueba
    repoAnimales.insertar(new Perro(1, "Fido", 5, "Labrador"));
    repoAnimales.insertar(new Gato(2, "Mishi", 2));
    repoAnimales.insertar(new Perro(3, "Rex", 10, "Pastor Aleman"));

    // CORREGIDO: Instanciación de Cuidador con 3 argumentos (ID, Nombre, Carga Máxima)
    repoCuidadores.insertar(new Cuidador(101, "Ana Lopez", 5));
    repoCuidadores.insertar(new Cuidador(102, "Juan Perez", 5));

    repoAdopciones.insertar(new Adopcion(501, repoAnimales.buscarPorID(1), 100.0));

    repoControles.insertar(new Vacunacion(701, "15/10/2025", repoAnimales.buscarPorID(1)));
    repoControles.insertar(new Desparasitacion(702, "01/10/2025", repoAnimales.buscarPorID(2)));
}

Refugio::~Refugio() {
    for(auto animal : repoAnimales) delete animal;
    for(auto cuidador : repoCuidadores) delete cuidador;
    for(auto adopcion : repoAdopciones) delete adopcion;
    for(auto control : repoControles) delete control;
}

// CRUD Animales
void Refugio::altaAnimal(Animal* a) { repoAnimales.insertar(a); std::cout << "Animal " << a->getNombre() << " registrado con ID " << a->getId() << "." << std::endl; }
void Refugio::bajaAnimal(int idAnimal) {
    try {
        repoAnimales.eliminarFisico(idAnimal);
        std::cout << "Animal ID " << idAnimal << " eliminado físicamente." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

// CRUD Cuidadores y Controles
void Refugio::altaCuidador(Cuidador* c) { repoCuidadores.insertar(c); std::cout << "Cuidador " << c->getNombre() << " registrado." << std::endl; }
void Refugio::altaControl(ControlVeterinario* c) { repoControles.insertar(c); std::cout << "Control " << c->getTipoControl() << " registrado." << std::endl; }

// Funcionalidades
void Refugio::asignarAnimalACuidador(int idCuidador, int idAnimal) {
    Cuidador* c = repoCuidadores.buscarPorID(idCuidador);
    Animal* a = repoAnimales.buscarPorID(idAnimal);

    if (!c || !a) { std::cout << "Error: Cuidador o Animal no encontrado." << std::endl; return; }

    try {
        c->asignarAnimal(a);
        std::cout << "Animal " << a->getNombre() << " asignado a Cuidador " << c->getNombre() << "." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Refugio::avanzarEstadoAdopcion(int idAdopcion) {
    Adopcion* ad = repoAdopciones.buscarPorID(idAdopcion);
    if (ad) {
        ++(*ad);
        // CRÍTICO: Usar el operador << sobrecargado para Adopcion
        std::cout << "Estado avanzado. Nuevo estado: " << *ad << std::endl;
    } else { std::cout << "Adopción ID " << idAdopcion << " no encontrada." << std::endl; }
}

void Refugio::retrocederEstadoAdopcion(int idAdopcion) {
    Adopcion* ad = repoAdopciones.buscarPorID(idAdopcion);
    if (ad) {
        --(*ad);
        // CRÍTICO: Usar el operador << sobrecargado para Adopcion
        std::cout << "Estado retrocedido. Nuevo estado: " << *ad << std::endl;
    } else { std::cout << "Adopción ID " << idAdopcion << " no encontrada." << std::endl; }
}

void Refugio::ordenarAnimalesPorEdad() {
    repoAnimales.ordenar([](const Animal& a1, const Animal& a2) {
        if (a1.getEdad() < a2.getEdad()) return -1;
        if (a1.getEdad() > a2.getEdad()) return 1;
        return 0;
    });
}

// Reportes
void Refugio::listarAdopcionesPorEstado(EstadoAdopcion estado) const {
    ContenedorDinamico<Adopcion>* filtrados = repoAdopciones.filtrar([estado](const Adopcion& a){
        return a.getEstado() == estado;
    });

    std::cout << "\n--- ADOPCIONES FILTRADAS POR ESTADO: " << estadoToString(estado) << " (" << filtrados->getCantidad() << ") ---\n";
    for (const auto& ad : *filtrados) { std::cout << *ad << std::endl; }

    delete filtrados;
}

void Refugio::listarReporteCuidadores() const {
    std::cout << "\n--- REPORTE DE CUIDADORES Y ANIMALES ASIGNADOS ---\n";
    for (const auto& c : repoCuidadores) {
        std::cout << *c << std::endl;
        c->listarAnimalesAsignados(std::cout);
    }
}

void Refugio::reporteHistorialVeterinario(int idAnimal) const {
    Animal* a = repoAnimales.buscarPorID(idAnimal);
    if (!a) { std::cout << "Animal ID " << idAnimal << " no encontrado." << std::endl; return; }

    ContenedorDinamico<ControlVeterinario>* historial = repoControles.filtrar([a](const ControlVeterinario& c){
        return c.getAnimal()->getId() == a->getId();
    });

    std::cout << "\n--- HISTORIAL VETERINARIO PARA: " << a->getNombre() << " (ID: " << a->getId() << ") ---\n";
    if (historial->getCantidad() == 0) {
        std::cout << "  (No se encontraron controles registrados).\n";
    } else {
        for (const auto& control : *historial) {
            std::cout << *control << std::endl;
        }
    }
    delete historial;
}

void Refugio::mostrarEstadisticas() const {
    std::cout << "\n--- PANEL DE DASHBOARD / ESTADÍSTICAS ---\n";
    std::cout << "Animales Vivos (Total): " << Animal::getContadorInstancias() << std::endl;
    std::cout << "Animales Disponibles para Adopción: " << repoAnimales.filtrar([](const Animal& a){ return !a.estaAdoptado(); })->getCantidad() << std::endl;
    std::cout << "Procesos de Adopción Activos: " << Adopcion::getContadorInstancias() << std::endl;
    std::cout << "Cuidadores Registrados: " << Cuidador::getContadorInstancias() << std::endl;
    std::cout << "--------------------------------------------\n";
}

// Implementación de funciones de CRUD adicionales para Animales/Cuidadores
void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Refugio::buscarYMostrarAnimal(int id) {
    Animal* a = repoAnimales.buscarPorID(id);

    if (a != nullptr) {
        std::cout << "\n--- ANIMAL ENCONTRADO ---" << std::endl;
        std::cout << *a << std::endl; // Uso del operador <<
        std::cout << "-------------------------" << std::endl;
    } else {
        std::cout << "ERROR: Animal con ID " << id << " no encontrado." << std::endl;
    }
}

void Refugio::modificarAnimal(int id) {
    Animal* a = repoAnimales.buscarPorID(id);

    if (a != nullptr) {
        std::cout << "\n--- MODIFICANDO ANIMAL ID: " << id << " ---" << std::endl;
        std::cout << *a << std::endl;

        std::string nuevoNombre;
        int nuevaEdad;

        std::cout << "Nuevo Nombre (dejar vacío para no cambiar): ";
        std::getline(std::cin, nuevoNombre);
        if (!nuevoNombre.empty()) {
            a->setNombre(nuevoNombre);
        }

        std::cout << "Nueva Edad (0 para no cambiar): ";
        if (!(std::cin >> nuevaEdad)) {
            std::cin.clear(); limpiarBuffer();
        } else if (nuevaEdad > 0) {
            a->setEdad(nuevaEdad);
        }
        limpiarBuffer();

        std::cout << "\n[OK] Animal modificado exitosamente." << std::endl;
    } else {
        std::cout << "ERROR: Animal con ID " << id << " no encontrado para modificar." << std::endl;
    }
}

void Refugio::bajaCuidador(int id) {
    Cuidador* c = repoCuidadores.buscarPorID(id);

    if (c != nullptr) {
        if (c->getAnimalesAsignados().size() > 0) {
            std::cout << "ERROR: El cuidador " << c->getNombre() << " tiene " << c->getAnimalesAsignados().size()
                      << " animales asignados. Debe reasignarlos primero." << std::endl;
            return;
        }

        // Usar eliminarFisico del ContenedorDinamico para la baja
        repoCuidadores.eliminarFisico(id);
        std::cout << "\n[OK] Cuidador ID " << id << " eliminado exitosamente." << std::endl;
    } else {
        std::cout << "ERROR: Cuidador con ID " << id << " no encontrado para dar de baja." << std::endl;
    }
}

void Refugio::buscarYMostrarCuidador(int id) {
    Cuidador* c = repoCuidadores.buscarPorID(id);

    if (c != nullptr) {
        std::cout << "\n--- CUIDADOR ENCONTRADO ---" << std::endl;
        std::cout << *c << std::endl; // Uso del operador <<
        c->listarAnimalesAsignados(std::cout);
        std::cout << "-------------------------" << std::endl;
    } else {
        std::cout << "ERROR: Cuidador con ID " << id << " no encontrado." << std::endl;
    }
}