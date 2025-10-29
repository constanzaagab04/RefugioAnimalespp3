#include "Dominio/Perro.h"

Perro::Perro(int i, std::string n, int e, std::string r) : Animal(i, n, e), raza(r) {}

std::string Perro::getEspecie() const {
    return "Perro";
}

void Perro::mostrarDetalles(std::ostream& os) const {
    os << "[ID: " << getId() << " / Especie: " << getEspecie() << "] Nombre: " << getNombre()
       << ", Edad: " << getEdad() << ", Raza: " << raza << ", Adoptado: " << (estaAdoptado() ? "SI" : "NO");
}