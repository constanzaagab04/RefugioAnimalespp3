#ifndef GATO_H
#define GATO_H
#include "Base/Animal.h"

class Gato : public Animal {
public:
    Gato(int i, std::string n, int e); // Declaración
    std::string getEspecie() const override; // Declaración
    void mostrarDetalles(std::ostream& os) const override; // Declaración
    // Implementación en Gato.cpp
};
#endif // GATO_H