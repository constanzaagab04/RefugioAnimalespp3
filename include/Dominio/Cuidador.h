#ifndef CUIDADOR_H
#define CUIDADOR_H

#include <vector>
#include "Base/Persona.h"
#include "Base/Animal.h"

class Cuidador : public Persona {
private:
    static int contadorInstancias;
    std::vector<Animal*> animalesAsignados;
    int cargaMaxima;

public:
    // CORREGIDO: Constructor de 3 argumentos para Carga Máxima
    Cuidador(int i, std::string n, int c_max);
    ~Cuidador() override;

    bool puedeAsignar() const;
    void asignarAnimal(Animal* a);
    int getCargaActual() const { return animalesAsignados.size(); }
    int getCargaMaxima() const { return cargaMaxima; }
    static int getContadorInstancias();

    // POLIMORFISMO
    void mostrarDetalles(std::ostream& os) const override;

    // Métodos específicos
    void listarAnimalesAsignados(std::ostream& os) const;
    const std::vector<Animal*>& getAnimalesAsignados() const { return animalesAsignados; }

    // Función de utilidad para el CRUD
    void mostrar() const { std::cout << *this << std::endl; }
};

#endif // CUIDADOR_H