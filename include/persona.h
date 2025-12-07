#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;
public:
    Persona();
    void setNombre(const std::string&);
    virtual void mostrarInfo() = 0;
    virtual ~Persona();
    virtual float calcularDesempenio() const;
    std::string getNombre() const;
    void setEdad(int);
    int getEdad() const;
};

#endif