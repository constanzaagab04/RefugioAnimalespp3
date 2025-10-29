#ifndef DESPARASITACION_H
#define DESPARASITACION_H
#include "Base/ControlVeterinario.h"

class Desparasitacion : public ControlVeterinario {
public:
    Desparasitacion(int i, std::string f, Animal* a); // Declaración
    std::string getTipoControl() const override; // Declaración
    void mostrarDetalles(std::ostream& os) const override; // Declaración
};
#endif // DESPARASITACION_H