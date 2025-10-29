#ifndef DESPARASITACION_H
#define DESPARASITACION_H
#include "Base/ControlVeterinario.h"

class Desparasitacion : public ControlVeterinario {
public:
    Desparasitacion(int i, std::string f, Animal* a); // Declaracion
    std::string getTipoControl() const override; // Declaracion
    void mostrarDetalles(std::ostream& os) const override; // Declaracioon
};
#endif // DESPARASITACION_H
