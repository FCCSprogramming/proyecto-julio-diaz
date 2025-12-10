#include "sistema.h"
#include <iostream>

using namespace std;

Sistema::Sistema(){ 
}
Sistema::Sistema(int numEstudiantes,Estudiante* estudiantes){ 
    this->numEstudiantes=numEstudiantes;
    this->estudiantes=estudiantes;
}

Sistema ::~Sistema(){ 
}

void Sistema::registrarEstudiante(std::string nombre1,int edad1,std::string codigo1,int cantCursos1,Curso* cursos1){
    cout<<"Registrar Estudiante: ";
    cin>>nombre1;
    ptr->setNombre(nombre1);
    cout<<"Edad: ";
    cin>>edad1;
    ptr->setEdad(edad1);
    cout<<"Codigo: ";
    cin>>codigo1;
    ptr->setCodigo(codigo1);
    cout<<"Cantidad de cursos a inscribir: ";
    cin>>cantCursos1;
    ptr->setCantCursos(cantCursos1);
}