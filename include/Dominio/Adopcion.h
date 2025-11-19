#ifndef ADOPCION_H
#define ADOPCION_H

#include "Animal.h"
#include "Enum.h"

class Adopcion {
private:
    static int contadorInstancias;
    int id;
    Animal* animal;
    EstadoAdopcion estado;
    double costoBase;
    
public:
    // Constructor público (asegúrate de que sea público)
    Adopcion(int i, Animal* a, double costo);
    ~Adopcion();

    int getId() const { return id; }
    Animal* getAnimal() const { return animal; }
    EstadoAdopcion getEstado() const { return estado; }
    static int getContadorInstancias();

    // Sobrecarga de operador ++ (Avanzar estado)
    Adopcion& operator++();

    // Sobrecarga de operador -- (retroceder estado)
    Adopcion& operator--();

    // Sobrecarga de operador () para calcular el monto total
    double operator()() const;

    // Sobrecarga de operador << (Impresión)
    friend std::ostream& operator<<(std::ostream& os, const Adopcion& ad);
};

#endif // ADOPCION_H
