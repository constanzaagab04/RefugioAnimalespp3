#include "Dominio/Desparasitacion.h"

// Implementación del constructor que llama al constructor de la clase base
Desparasitacion::Desparasitacion(int i, std::string f, Animal* a) : ControlVeterinario(i, f, a) {}

// Implementación de la función virtual getTipoControl()
std::string Desparasitacion::getTipoControl() const {
    return "Desparasitación";
}

// Implementación de la función virtual mostrarDetalles()
void Desparasitacion::mostrarDetalles(std::ostream& os) const {
    os << "[ID Control: " << getId() << " / Tipo: " << getTipoControl() << "] Animal: " << getAnimal()->getNombre()
       << " (ID: " << getAnimal()->getId() << "). Fecha: " << getFecha() << ". Observación: Desparasitación preventiva.";
}