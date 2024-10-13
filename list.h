#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Lista {
private:
    T* Datos;           // Arreglo dinámico
    size_t Capacidad;   // Capacidad actual del arreglo
    size_t Tamano;      // Número de elementos en la lista

    void AumentarCapacidad() {
        size_t NuevaCapacidad = (Capacidad == 0) ? 1 : Capacidad * 2;
        T* NuevosDatos = new T[NuevaCapacidad];

        if (Datos != NULL) {
            memcpy(NuevosDatos, Datos, Tamano * sizeof(T));
        }

        delete[] Datos;
        Datos = NuevosDatos;
        Capacidad = NuevaCapacidad;
    }

public:
    // Constructor
    Lista() : Datos(NULL), Capacidad(0), Tamano(0) {}

    // Destructor
    ~Lista() {
        delete[] Datos;
    }

    // Método para obtener el tamaño de la lista
    size_t Size() const {
        return Tamano;
    }

    // Método para agregar un elemento al final
    void Push_back(const T& Valor) {
        if (Tamano == Capacidad) {
            AumentarCapacidad();
        }
        Datos[Tamano] = Valor;
        Tamano++;
    }

    // Método para agregar un elemento al principio
    void Push_front(const T& Valor) {
        if (Tamano == Capacidad) {
            AumentarCapacidad();
        }
        for (size_t i = Tamano; i > 0; i--) {
            Datos[i] = Datos[i - 1];
        }
        Datos[0] = Valor;
        Tamano++;
    }

    // Método para eliminar el último elemento
    void Pop_back() {
        if (Tamano > 0) {
            Tamano--;
        } else {
            cout << "Realice un mensaje cuando el array esté vacío.\n";
        }
    }

    // Método para eliminar el primer elemento
    void Pop_front() {
        if (Tamano > 0) {
            for (size_t i = 0; i < Tamano - 1; i++) {
                Datos[i] = Datos[i + 1];
            }
            Tamano--;
        } else {
            cout << "Realice un mensaje cuando el array esté vacío.\n";
        }
    }

    // Método para verificar si la lista está vacía
    bool Empty() const {
        return Tamano == 0;
    }

    // Clase interna iteradora
    class Iterator {
    private:
        T* Ptr;  // Apuntador al elemento actual
    public:
        Iterator(T* p = nullptr) : Ptr(p) {}

        // Sobrecarga del operador * (dereferencia)
        T& operator*() const {
            return *Ptr;
        }

        // Sobrecarga del operador ++ (pre-incremento)
        Iterator& operator++() {
            Ptr++;
            return *this;
        }

        // Sobrecarga del operador != (diferencia)
        bool operator!=(const Iterator& Otro) const {
            return Ptr != Otro.Ptr;
        }
    };

    // Métodos para obtener iteradores
    Iterator Begin() {
        return Iterator(Datos);
    }

    Iterator End() {
        return Iterator(Datos + Tamano);
    }
};

#endif // LIST_H_INCLUDED
