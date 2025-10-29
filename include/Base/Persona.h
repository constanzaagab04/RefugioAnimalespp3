#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

class Persona {
protected:
    std::string nombre;
    int id;

public:
    Persona(int i, std::string n);
    virtual ~Persona();

    int getId() const { return id; }
    std::string getNombre() const { return nombre; }

    virtual void mostrarDetalles(std::ostream& os) const = 0; // Pura (clase abstracta)

    // Sobrecarga de operador $<<$ (Impresión) - Llama a mostrarDetalles
    friend std::ostream& operator<<(std::ostream& os, const Persona& p) {
        p.mostrarDetalles(os);
        return os;
    }
};

#endif // PERSONA_H