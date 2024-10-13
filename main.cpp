#include <iostream>
#include "list.h"  // Incluimos la clase Lista personalizada
using namespace std;

class Persona {
private:
    int IdPersona;
    string Nombre;
    string Apellido;
public:
    Persona(int id, string n, string a) {
        this->IdPersona = id;
        this->Nombre = n;
        this->Apellido = a;
    }
    int GetIdPersona() {
        return this->IdPersona;
    }
    string GetNombre() {
        return this->Nombre;
    }
    string GetApellido() {
        return this->Apellido;
    }
    virtual int GetTipoPersona() = 0;
};

class Estudiante : public Persona {
private:
    float Nota1;
public:
    Estudiante(int id, string n, string a) : Persona(id, n, a) {
        this->Nota1 = 0;
    }
    void SetNota(float n) {
        this->Nota1 = n;
    }
    float GetNota() {
        return this->Nota1;
    }
    int GetTipoPersona() {
        return 1;
    }
};

class Trabajador : public Persona {
private:
    float Sueldo;
public:
    Trabajador(int id, string n, string a) : Persona(id, n, a) {
        this->Sueldo = 0;
    }
    void SetSueldo(float n) {
        this->Sueldo = n;
    }
    float GetSueldo() {
        return this->Sueldo;
    }
    int GetTipoPersona() {
        return 2;
    }
};

// Función para mostrar la lista personalizada
void Mostrar(Lista<Persona*>& lst) {
    if (lst.Empty()) {
        cout << "La lista está vacía\n";
    } else {
        cout << "Id\tNombre\tApellido\tTipo\n";
        for (Lista<Persona*>::Iterator it = lst.Begin(); it != lst.End(); ++it) {
            Persona* persona = *it;
            cout << persona->GetIdPersona() << "\t";
            cout << persona->GetNombre() << "\t";
            cout << persona->GetApellido() << "\t";
            if (persona->GetTipoPersona() == 1) {
                cout << "Estudiante\n";
            } else {
                cout << "Trabajador\n";
            }
        }
    }
}

int main() {
    Lista<Persona*> ListaPersonas;
    ListaPersonas.Push_back(new Estudiante(1, "Juan", "Perez"));
    ListaPersonas.Push_back(new Trabajador(2, "Mario", "Diaz"));

    Mostrar(ListaPersonas);

    // Limpieza de memoria
    for (Lista<Persona*>::Iterator it = ListaPersonas.Begin(); it != ListaPersonas.End(); ++it) {
        delete *it;
    }

    return 0;
}
