#ifndef GATO_H
#define GATO_H
#include "Base/Animal.h"

class Gato : public Animal {
public:
    Gato(int i, std::string n, int e); 
    std::string getEspecie() const override; 
    void mostrarDetalles(std::ostream& os) const override; 
    // Implementación en Gato.cpp
};
#endif // GATO_H
