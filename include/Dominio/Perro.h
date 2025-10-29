#ifndef PERRO_H
#define PERRO_H
#include "Base/Animal.h"

class Perro : public Animal {
private: std::string raza;
public:
// Declaraciones 
    Perro(int i, std::string n, int e, std::string r); 
    std::string getEspecie() const override; 
    void mostrarDetalles(std::ostream& os) const override; 
    // Implementación en Perro.cpp
};
#endif // PERRO_H
