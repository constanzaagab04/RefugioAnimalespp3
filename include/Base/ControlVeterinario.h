#ifndef CONTROL_VETERINARIO_H
#define CONTROL_VETERINARIO_H

#include <iostream>
#include <string>
#include "Animal.h" // Dependencia

class ControlVeterinario {
private:
    static int contadorInstancias; // Contador estático 
    int id;
    std::string fecha;
    Animal* animal;

public:
    ControlVeterinario(int i, std::string f, Animal* a); // Declaración
    virtual ~ControlVeterinario(); // Declaración

    // Funciones virtuales puras (Clase Abstracta polimorfismo) 
    virtual std::string getTipoControl() const = 0;
    virtual void mostrarDetalles(std::ostream& os) const = 0;

    // Métodos
    int getId() const { return id; }
    Animal* getAnimal() const { return animal; }
    std::string getFecha() const { return fecha; }
    static int getContadorInstancias();

    // Sobrecarga de operador << (para impreImpresión) 
    friend std::ostream& operator<<(std::ostream& os, const ControlVeterinario& c) {
        c.mostrarDetalles(os);
        return os;
    }
};

#endif // CONTROL_VETERINARIO_H
