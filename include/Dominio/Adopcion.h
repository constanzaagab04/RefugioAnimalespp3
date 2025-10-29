#ifndef ADOPCION_H
#define ADOPCION_H

#include "Base/Animal.h"
#include "Utilidad/Enums.h"

class Adopcion {
private:
    static int contadorInstancias; // Contador estático [cite: 60]
    int id;
    Animal* animal;
    EstadoAdopcion estado;
    double costoBase;

public:
    Adopcion(int i, Animal* a, double costo); // Declaración
    ~Adopcion(); // Declaración

    int getId() const { return id; }
    Animal* getAnimal() const { return animal; }
    EstadoAdopcion getEstado() const { return estado; }
    static int getContadorInstancias();

    // Sobrecarga de operador $++$ (Avanzar estado) [cite: 56]
    Adopcion& operator++(); // Declaración

    // Sobrecarga de operador $--$ (Retroceder estado) [cite: 56]
    Adopcion& operator--(); // Declaración

    // Sobrecarga de operador $()$ para calcular el monto total [cite: 58]
    double operator()() const; // Declaración

    // Sobrecarga de operador $<<$ (Impresión) [cite: 54]
    friend std::ostream& operator<<(std::ostream& os, const Adopcion& ad);
};

#endif // ADOPCION_H