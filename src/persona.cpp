#include "persona.h"

Persona::Persona(){ 
}

Persona::~Persona(){ 
}

void Persona::setNombre(const std::string& nombre){
    this->nombre = nombre;
}

std::string Persona::getNombre() const {
    return nombre;
}

void Persona::setEdad(int edad){
    this->edad = edad;
}

int Persona::getEdad() const {
    return edad;
}
float Persona::calcularDesempenio() const {
    return 0.0;
}