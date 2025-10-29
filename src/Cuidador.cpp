//
// Created by Constanza Gabriel on 10/18/25.
//
#include "Dominio/Cuidador.h"
#include <stdexcept>
#include <iostream>

// Inicialización del contador estático
int Cuidador::contadorInstancias = 0;

// CORREGIDO: Constructor de 3 argumentos
Cuidador::Cuidador(int i, std::string n, int c_max) : Persona(i, n), cargaMaxima(c_max) {
    ++contadorInstancias;
}

Cuidador::~Cuidador() {
    --contadorInstancias;
}

int Cuidador::getContadorInstancias() {
    return contadorInstancias;
}

bool Cuidador::puedeAsignar() const {
    return animalesAsignados.size() < cargaMaxima;
}

void Cuidador::asignarAnimal(Animal* a) {
    if (!puedeAsignar()) {
        throw std::runtime_error("ERROR: Cuidador ya alcanzó la carga máxima de animales (" + std::to_string(cargaMaxima) + ").");
    }
    animalesAsignados.push_back(a);
}

void Cuidador::mostrarDetalles(std::ostream& os) const {
    os << "[ID: " << getId() << "] Cuidador: " << getNombre()
       << ". Carga: " << animalesAsignados.size() << "/" << cargaMaxima << ".";
}

void Cuidador::listarAnimalesAsignados(std::ostream& os) const {
    os << "   --> Animales Asignados (" << animalesAsignados.size() << "):\n";
    if (animalesAsignados.empty()) {
        os << "      (Ninguno)\n";
        return;
    }
    for (const auto& a : animalesAsignados) {
        os << "      - " << a->getNombre() << " (ID: " << a->getId() << ", Especie: " << a->getEspecie() << ")\n";
    }
}