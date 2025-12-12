#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include "persona.h"
#include "curso.h"

class Estudiante : public Persona {
    private:
        std::string codigo;
        int cantCursos;
    public:
        Estudiante();
        void mostrarInfo() override;
        float calcularDesempenio() const override;
        void setCodigo(const std::string&);
        std::string getCodigo() const;
        void setCantCursos(int);
        int getCantCursos()const;
};





#endif