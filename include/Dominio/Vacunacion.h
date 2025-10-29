#ifndef VACUNACION_H
#define VACUNACION_H
#include "Base/ControlVeterinario.h"

class Vacunacion : public ControlVeterinario {
public:
    Vacunacion(int i, std::string f, Animal* a); // Declaración
    std::string getTipoControl() const override; // Declaración
    void mostrarDetalles(std::ostream& os) const override; // Declaración
};
#endif // VACUNACION_H