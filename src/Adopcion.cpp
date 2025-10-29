//
// Created by Constanza Gabriel on 10/18/25.
//
#include "Dominio/Adopcion.h"
#include "Utilidad/Enums.h"

// Inicialización del contador estático [cite: 60]
int Adopcion::contadorInstancias = 0;

Adopcion::Adopcion(int i, Animal* a, double costo) : id(i), animal(a), estado(EstadoAdopcion::INICIADA), costoBase(costo) {
    ++contadorInstancias;
}

Adopcion::~Adopcion() {
    --contadorInstancias;
}

int Adopcion::getContadorInstancias() {
    return contadorInstancias;
}

// Sobrecarga de operador $++$ (Avanzar estado) [cite: 56]
Adopcion& Adopcion::operator++() {
    if (estado == EstadoAdopcion::INICIADA) estado = EstadoAdopcion::REVISION;
    else if (estado == EstadoAdopcion::REVISION) estado = EstadoAdopcion::APROBADA;
    else if (estado == EstadoAdopcion::APROBADA) {
        estado = EstadoAdopcion::CONCRETADA;
        animal->setAdoptado(true); // Baja Lógica
    }
    return *this;
}

// Sobrecarga de operador $--$ (Retroceder estado) [cite: 56]
Adopcion& Adopcion::operator--() {
    if (estado == EstadoAdopcion::CONCRETADA) {
        estado = EstadoAdopcion::APROBADA;
        animal->setAdoptado(false);
    }
    else if (estado == EstadoAdopcion::APROBADA) estado = EstadoAdopcion::REVISION;
    else if (estado == EstadoAdopcion::REVISION) estado = EstadoAdopcion::INICIADA;
    return *this;
}

// Sobrecarga de operador $()$ para calcular el monto total [cite: 58]
double Adopcion::operator()() const {
    // 15% de recargo por gestiones
    return costoBase * 1.15;
}

// Sobrecarga de operador $<<$ (Impresión) [cite: 54]
std::ostream& operator<<(std::ostream& os, const Adopcion& ad) {
    os << "[ID Adopción: " << ad.id << "] Animal: " << ad.animal->getNombre() << " (ID: " << ad.animal->getId()
       << "). Estado: " << estadoToString(ad.estado) << ". Costo Total: $" << ad() << "."; // Usa operador ()
    return os;
}