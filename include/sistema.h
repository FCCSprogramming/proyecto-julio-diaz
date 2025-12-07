#ifndef SISTEMA_H
#define SISTEMA_H


class Sistema {
public:
    void registrarEstudiante();
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