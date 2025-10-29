#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
private:
    static int contadorInstancias;
    int id;
    std::string nombre;
    int edad;
    bool adoptado;

public:
    Animal(int i, std::string n, int e);
    virtual ~Animal();

    // Funciones virtuales puras (Clase Abstracta)
    virtual std::string getEspecie() const = 0;
    virtual void mostrarDetalles(std::ostream& os) const = 0; // Método polimórfico clave

    // Métodos
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    bool estaAdoptado() const { return adoptado; }
    void setAdoptado(bool a) { adoptado = a; }
    static int getContadorInstancias();

    // Sobrecarga de operador $<<$ (Impresión) - Llama a mostrarDetalles
    friend std::ostream& operator<<(std::ostream& os, const Animal& a) {
        a.mostrarDetalles(os);
        return os;
    }

    // Sobrecarga de operador $<$ (Ordenamientos: por Edad)
    bool operator<(const Animal& otro) const;

    // SETTERS (CRUD - Modificación)
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setEdad(int nuevaEdad) { edad = nuevaEdad; }
};

#endif // ANIMAL_H