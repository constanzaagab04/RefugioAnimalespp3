#ifndef PERRO_H
#define PERRO_H
#include "Base/Animal.h"

class Perro : public Animal {
private: std::string raza;
public:
    Perro(int i, std::string n, int e, std::string r); // Declaración
    std::string getEspecie() const override; // Declaración
    void mostrarDetalles(std::ostream& os) const override; // Declaración
    // Implementación en Perro.cpp
};
#endif // PERRO_H