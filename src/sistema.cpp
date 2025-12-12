#include "sistema.h"
#include "estudiante.h"
#include "curso.h"
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
void Sistema::setNumEstudiantes(int numEstudiantes){
    this->numEstudiantes = numEstudiantes;
}
int Sistema::getNumEstudiantes() const {
    return numEstudiantes;
}

void Sistema::registrarEstudiante(){
    std::string nombre1,codigo1;
    int edad1,cantCursos1;
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
    ptr++;
}
void Sistema::registrarCurso(Curso* cursos,Curso* ptr1){
    std::string nombreCurso1,codigoCurso1;
    int creditos1,cantEstudiantes1;
    cout<<"Registrar Curso:";
    cin>>nombreCurso1;
    ptr1->setNombreCurso(nombreCurso1);
    cout<<"Codigo del Curso: ";
    cin>>codigoCurso1;
    ptr1->setCodigoCurso(codigoCurso1);
    cout<<"Creditos del Curso: ";
    cin>>creditos1;
    ptr1->setCreditos(creditos1);
    cout<<"Cantidad de Estudiantes a inscribir en el curso: ";
    cin>>cantEstudiantes1;
    ptr1->setCantEstudiantes(cantEstudiantes1);
    ptr1++;
}
void Sistema::inscribirCurso(Curso* curso,const int numCursos){
    ptr2 = estudiantes;
    std::string nombreEstudiante,nombreCursoInscribir;
    cout<<"Estudiante a inscribir en curso: ";
    cin>>nombreEstudiante;
    for(int i=0;i<Sistema::getNumEstudiantes();i++){
        if((ptr2)->getNombre()==nombreEstudiante){
            cout<<"Curso a inscribir: ";
            cin>>nombreCursoInscribir;
            for(int j=0;j<numCursos;j++){
                if((curso+j)->getNombreCurso()==nombreCursoInscribir){
                    (curso+j)->ptr3[j]=*(ptr2);
                    cout<<"Estudiante "<<nombreEstudiante<<" inscrito en el curso "<<nombreCursoInscribir<<endl;
                    (curso+j)->ptr3++;
                }else{
                    cout<<"Curso no encontrado."<<endl;
                }
            }
          
        }
    ptr2++;       
    }
}
void Sistema::registrarNotaParcial(){
    curso->prt4 = estudiantes;
    std::string nombreEstudiante;
    cout<<"Estudiante a registrar nota: "<<endl;
    cin>>nombreEstudiante;
    for(int i=0;i<Sistema::getNumEstudiantes();i++){
        if(()->getNombre()==nombreEstudiante){
            float nota;
            cout<<"Ingrese la nota parcial: ";
            cin>>nota;
            
        }
        
    }

}
