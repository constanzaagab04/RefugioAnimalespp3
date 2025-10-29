#include "Dominio/Gato.h"

Gato::Gato(int i, std::string n, int e) : Animal(i, n, e) {}

std::string Gato::getEspecie() const {
    return "Gato";
}

void Gato::mostrarDetalles(std::ostream& os) const {
    os << "[ID: " << getId() << " / Especie: " << getEspecie() << "] Nombre: " << getNombre()
       << ", Edad: " << getEdad() << ", Adoptado: " << (estaAdoptado() ? "SI" : "NO");
}