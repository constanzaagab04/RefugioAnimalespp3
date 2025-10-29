#include "Base/ControlVeterinario.h"

// Inicialización del contador estático [cite: 60]
int ControlVeterinario::contadorInstancias = 0;

ControlVeterinario::ControlVeterinario(int i, std::string f, Animal* a) : id(i), fecha(f), animal(a) {
    ++contadorInstancias;
}

ControlVeterinario::~ControlVeterinario() {
    --contadorInstancias;
}

int ControlVeterinario::getContadorInstancias() {
    return contadorInstancias;
}