#include "Base/Animal.h"

// Inicialización del contador estático [cite: 60]
int Animal::contadorInstancias = 0;

Animal::Animal(int i, std::string n, int e) : id(i), nombre(n), edad(e), adoptado(false) {
    ++contadorInstancias;
}

Animal::~Animal() {
    --contadorInstancias;
}

int Animal::getContadorInstancias() {
    return contadorInstancias;
}

// Implementación de la sobrecarga de operador < [cite: 55]
bool Animal::operator<(const Animal& otro) const {
    return this->edad < otro.edad;
}
