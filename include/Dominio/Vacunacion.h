#ifndef VACUNACION_H
#define VACUNACION_H
#include "Base/ControlVeterinario.h"

class Vacunacion : public ControlVeterinario {
public:
    Vacunacion(int i, std::string f, Animal* a); 
    std::string getTipoControl() const override; 
    void mostrarDetalles(std::ostream& os) const override; 
};
#endif // VACUNACION_H
