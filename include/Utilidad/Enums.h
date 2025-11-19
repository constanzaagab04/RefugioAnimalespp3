#ifndef ENUM_H
#define ENUM_H

#include <string>

enum class EstadoAdopcion { INICIADA, REVISION, APROBADA, CONCRETADA, CANCELADA };

// Función de utilidad para convertir el enum a string
inline std::string estadoToString(EstadoAdopcion e) {
    switch (e) {
        case EstadoAdopcion::INICIADA: return "INICIADA";
        case EstadoAdopcion::REVISION: return "EN REVISION";
        case EstadoAdopcion::APROBADA: return "APROBADA";
        case EstadoAdopcion::CONCRETADA: return "CONCRETADA";
        case EstadoAdopcion::CANCELADA: return "CANCELADA";
        default: return "DESCONOCIDO";
    }
}

#endif // ENUM_H
