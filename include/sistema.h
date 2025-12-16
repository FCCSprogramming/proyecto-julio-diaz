#ifndef SISTEMA_H
#define SISTEMA_H
#include "estudiante.h"
#include "curso.h"


class Sistema {
    int numEstudiantes;
    Estudiante* estudiantes= new Estudiante[numEstudiantes];
public:
    Estudiante* ptr = estudiantes;//puntero que usara para registrar estudiantes(registrarEstudiante())
    Estudiante* ptr2= estudiantes;//puntero que se usara en distintas funciones para recorrer el arreglo dinamico de estudiantes
    Curso* ptr1,ptr_1;
    Sistema();
    Sistema(int,Estudiante*);
    ~Sistema();
    void setNumEstudiantes(int);
    int getNumEstudiantes() const;
    void registrarEstudiante();
    void registrarCurso(Curso*,Curso*);
    void inscribirCurso(Curso*,const int);
    void registrarNotaParcial(Curso*);
    void calcularPromedio_generarReporte(Sistema,Curso*,Curso*,int);
    void almacenarDatosEstudiantesAprobados(Sistema,Curso*,Curso*,int,fstream&);
    void guardarBaseDeDatos(Curso*,Curso*,int,fstream&);
    void cargarBaseDeDatos(fstream&);
    void accesoDirectoRegistros(fstream&);
    void listarDatosRegistrados();
};

#endif