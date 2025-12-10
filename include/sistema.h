#ifndef SISTEMA_H
#define SISTEMA_H
#include "estudiante.h"
#include "curso.h"


class Sistema {
    int numEstudiantes;
    Estudiante* estudiantes= new Estudiante[numEstudiantes];
public:
    Estudiante* ptr = estudiantes;
    Sistema();
    Sistema(int,Estudiante*);
    ~Sistema();
    void registrarEstudiante(std::string nombre,int,std::string,int,Curso*);
    void registrarCurso();
    void inscribirCurso();
    void registrarNotaParcial();
    void calcularPromedio_generarReporte();
    void almacenarDatosEstudiantesAprobados();
    void guardarBaseDeDatos();
    void cargarBaseDeDatos();
    void accesoDirectoRegistros();
    void listarDatosRegistrados();
};

#endif