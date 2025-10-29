#ifndef CONTENEDOR_DINAMICO_H
#define CONTENEDOR_DINAMICO_H

#include <iostream>
#include <functional>
#include <stdexcept>

// Clase de plantilla para el contenedor dinámico propio (arreglo dinámico)
template <class T>
class ContenedorDinamico {
private:
    T** elementos;
    int capacidad;
    int cantidad;

    void redimensionar(int nuevaCapacidad) {
        T** nuevoArreglo = new T*[nuevaCapacidad];
        for (int i = 0; i < cantidad; ++i) {
            nuevoArreglo[i] = elementos[i];
        }
        delete[] elementos;
        elementos = nuevoArreglo;
        capacidad = nuevaCapacidad;
    }

public:
    ContenedorDinamico(int capInicial = 10) : capacidad(capInicial), cantidad(0) {
        elementos = new T*[capacidad];
    }
    // El destructor sólo libera el arreglo de punteros, no los objetos T*.
    ~ContenedorDinamico() { delete[] elementos; }

    void insertar(T* elemento) {
        if (cantidad == capacidad) redimensionar(capacidad * 2);
        elementos[cantidad++] = elemento;
    }

    // Método de búsqueda (CONST)
    T* buscarPorID(int idBuscado) const {
        for (int i = 0; i < cantidad; ++i) {
            if (elementos[i]->getId() == idBuscado) return elementos[i];
        }
        return nullptr;
    }

    // Eliminación física (Baja física)
    void eliminarFisico(int idBuscado) {
        bool encontrado = false;
        for (int i = 0; i < cantidad; ++i) {
            if (elementos[i]->getId() == idBuscado) {
                delete elementos[i]; // **CRÍTICO: LIBERA EL OBJETO**
                encontrado = true;
                // Mueve los elementos restantes hacia adelante
                for (int j = i; j < cantidad - 1; ++j) {
                    elementos[j] = elementos[j + 1];
                }
                cantidad--;
                return;
            }
        }
        if (!encontrado) throw std::runtime_error("ID no encontrado para eliminación.");
    }

    // Ordenamiento manual (usa función lambda para el criterio)
    void ordenar(std::function<int(const T&, const T&)> comparador) {
        // Bubble Sort
        for (int i = 0; i < cantidad - 1; ++i) {
            for (int j = 0; j < cantidad - 1 - i; ++j) {
                if (comparador(*elementos[j], *elementos[j+1]) > 0) {
                    T* temp = elementos[j];
                    elementos[j] = elementos[j+1];
                    elementos[j+1] = temp;
                }
            }
        }
    }

    // Filtrado (Reportes)
    ContenedorDinamico<T>* filtrar(std::function<bool(const T&)> criterio) const {
        ContenedorDinamico<T>* resultado = new ContenedorDinamico<T>();
        for (int i = 0; i < cantidad; ++i) {
            if (criterio(*elementos[i])) {
                resultado->insertar(elementos[i]);
            }
        }
        return resultado;
    }

    int getCantidad() const { return cantidad; }

    // Iteradores (para uso sencillo en bucles for-each)
    class Iterador {
    private: T** actual;
    public:
        Iterador(T** p) : actual(p) {}
        bool operator!=(const Iterador& otro) const { return actual != otro.actual; }
        T* operator*() const { return *actual; }
        Iterador& operator++() { ++actual; return *this; }
    };
    Iterador begin() const { return Iterador(elementos); }
    Iterador end() const { return Iterador(elementos + cantidad); }


    ////// MÉTODOS CRUD GENÉRICOS (Definiciones agregadas para resolver el linker error)

    // DEFINICIÓN: Resuelve 'repoCuidadores.alta()'
    void alta(T* elemento) { insertar(elemento); }

    // DEFINICIÓN: Resuelve 'repoCuidadores.baja()'
    void baja(int id) { eliminarFisico(id); }

    // DEFINICIÓN: Resuelve la versión no-const de buscarPorID(), llamando a la versión const
    T* buscarPorID(int id) {
        // Llama a la versión const y luego elimina la constancia del puntero devuelto.
        // Esto es necesario para que el código que modifica el objeto encontrado pueda compilar.
        return const_cast<T*>(static_cast<const ContenedorDinamico<T>*>(this)->buscarPorID(id));
    }
};

#endif // CONTENEDOR_DINAMICO_H