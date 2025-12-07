#include "estudiante.h"
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
    for (int i = 0;i<cantCursos;i++){
        cout<<"Curso "<<i+1<<": "<<cursos[i].getNombreCurso()<<" - "<<cursos[i].getCodigoCurso()<<" - Creditos: "<<cursos[i].getCreditos()<<endl;
    }
}
void Estudiante::setCantCursos(int cantCursos) {
            this->cantCursos = cantCursos;
}
int Estudiante::getCantCursos()const {
    return cantCursos;
}