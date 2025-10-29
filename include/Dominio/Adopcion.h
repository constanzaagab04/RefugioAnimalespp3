#ifndef ADOPCION_H
#define ADOPCION_H

#include "Base/Animal.h"
#include "Utilidad/Enums.h"

class Adopcion {
private:
    static int contadorInstancias; // Contador estatico 
    int id;
    Animal* animal;
    EstadoAdopcion estado;
    double costoBase;

public:
    Adopcion(int i, Animal* a, double costo); // Declaracion 
    ~Adopcion(); // Declaracion 

    int getId() const { return id; }
    Animal* getAnimal() const { return animal; }
    EstadoAdopcion getEstado() const { return estado; }
    static int getContadorInstancias();

    // Sobrecarga de operador ++ (Avanzar estado) 
    Adopcion& operator++(); // Declaración

    // Sobrecarga de operador -- (retroce estado) 
    Adopcion& operator--(); // Delcaracion

    // Sobrecarga de operador () para calcular el monto total 
    double operator()() const; // Declaracion

    // Sobrecarga de operador << (Impresión) 
    friend std::ostream& operator<<(std::ostream& os, const Adopcion& ad);
};

#endif // ADOPCION_H
