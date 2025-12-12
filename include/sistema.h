#ifndef SISTEMA_H
#define SISTEMA_H
#include "estudiante.h"
#include "curso.h"


class Sistema {
    int numEstudiantes;
    Estudiante* estudiantes= new Estudiante[numEstudiantes];
public:
    Estudiante* ptr = estudiantes;
    Estudiante* ptr2= estudiantes;
    Curso* ptr1,ptr_1;
    Sistema();
    Sistema(int,Estudiante*);
    ~Sistema();
    void setNumEstudiantes(int);
    int getNumEstudiantes() const;
    void registrarEstudiante();
    void registrarCurso(Curso*,Curso*);
    void inscribirCurso(Curso*,const int);
    void registrarNotaParcial();
    void calcularPromedio_generarReporte();
    void almacenarDatosEstudiantesAprobados();
    void guardarBaseDeDatos();
    void cargarBaseDeDatos();
    void accesoDirectoRegistros();
    void listarDatosRegistrados();
};

#endif