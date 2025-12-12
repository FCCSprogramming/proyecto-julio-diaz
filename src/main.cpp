#include <iostream>
#include "persona.h"
#include "curso.h"
#include "sistema.h"
#include "estudiante.h"




using namespace std;

int main() {
     const int numCursos=10;
    int contCursos=0;
    Sistema sistema(20,nullptr);
    Curso* cursos = new Curso[numCursos];
    Curso* ptrCurso = cursos;
    int opcion;
    while (opcion!=11) {
    cout<<"===Sistema de Gestion Academica UNI==="<<endl;
    cout<<"1)Registrar Estudiante"<<endl;
    cout<<"2)Registrar Curso"<<endl;
    cout<<"3)Inscribir a Curso"<<endl;
    cout<<"4)Registrar nota parcial"<<endl;
    cout<<"5)Calcular promedio y generar reporte"<<endl;
    cout<<"6)Almacenar datos de estudiantes aprobados"<<endl;
    cout<<"7)Guardar base de datos"<<endl;
    cout<<"8)Cargar base de datos"<<endl;
    cout<<"9)Acceso directo a registros"<<endl;
    cout<<"10)Listar datos registrados"<<endl;
    cout<<"11)Salir"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        sistema.registrarEstudiante();
        break;
    case 2:
        if(contCursos==numCursos){
            cout<<"Limite de cursos alcanzado."<<endl;
            break;
        }
        sistema.registrarCurso(cursos,ptrCurso);
        contCursos++;
        break;
    case 3:
        
        break;
    case 4: 
        
        break;        
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        
        break;
    case 9:
        
        break;
    case 10:
        
        break;
    case 11:
        cout<<"Saliendo del sistema..."<<endl;
        return 0;
    default:
        break;
    }
    }


    
    return 0;
}