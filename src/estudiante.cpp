#include "estudiante.h"
#include "curso.h"
#include <iostream>

using namespace std;

Estudiante::Estudiante(){ 
}
void Estudiante::setCodigo(const std::string& codigo){
    this->codigo = codigo;
}
std::string Estudiante::getCodigo()const {
    return codigo;
}
void Estudiante::mostrarInfo() {
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Codigo: "<<codigo<<endl;
    cout<<"cursos inscritos: "<<cantCursos<<endl;
}
float Estudiante::calcularDesempenio() const {
    // Implementacion ficticia del calculo de desempenio
    float desempenio = 0.0;
    // Logica para calcular el desempenio basado en las notas de los cursos
    return desempenio;
}
void Estudiante::setCantCursos(int cantCursos) {
            this->cantCursos = cantCursos;
}
int Estudiante::getCantCursos()const {
    return cantCursos;
}