//
// Created by Constanza Gabriel on 10/18/25.
//
#include "Dominio/Vacunacion.h"

Vacunacion::Vacunacion(int i, std::string f, Animal* a) : ControlVeterinario(i, f, a) {}

std::string Vacunacion::getTipoControl() const {
    return "Vacunación";
}

void Vacunacion::mostrarDetalles(std::ostream& os) const {
    os << "[ID Control: " << getId() << " / Tipo: " << getTipoControl() << "] Animal: " << getAnimal()->getNombre()
       << " (ID: " << getAnimal()->getId() << "). Fecha: " << getFecha() << ". Observación: Vacuna aplicada.";
}