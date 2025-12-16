#include <iostream>
#include "persona.h"
#include "curso.h"
#include "sistema.h"
#include "estudiante.h"
#include <fstream>


using namespace std;

fstream archivo("C:\\Users\\Personal\\Documents\\GitHub\\proyecto-julio-diaz\\estudiantes aprobados.txt");//generamos el archivo de texto 
fstream archivoBin("C:\\Users\\Personal\\Documents\\GitHub\\proyecto-julio-diaz\\base de datos.bin");//generamos el archivo binario

int main() {
    const int numCursos=10;
    int contCursos=0;
    Sistema sistema(20,nullptr);//establecemos la maxima cantidad de estudiantes como 20 e inicialmente no hay estudiantes registrados
    Curso* cursos = new Curso[numCursos];//arreglo dinamico de cursos(max 10)
    Curso* ptrCurso1 = cursos;
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
        sistema.registrarEstudiante();//va registrando estudiantes en el sistema,no es necesario parametros
        break;
    case 2:
        if(contCursos==numCursos){//usamos el contCursos para que deje de registrar cursos al llegar al maximo
            cout<<"Limite de cursos alcanzado."<<endl;
            break;
        }
        sistema.registrarCurso(cursos,ptrCurso1);
        contCursos++;
        break;
    case 3:
        sistema.inscribirCurso(ptrCurso1,contCursos);
        break;
    case 4: 
        sistema.registrarNotaParcial(ptrCurso1);
        break;        
    case 5:
        sistema.calcularPromedio_generarReporte(sistema,cursos,ptrCurso1,numCursos);
        break;
    case 6:
        sistema.almacenarDatosEstudiantesAprobados(sistema,cursos,ptrCurso1,numCursos,archivo);
        break;
    case 7:
        sistema.guardarBaseDeDatos(cursos,ptrCurso1,numCursos,archivoBin);
        break;
    case 8:
        sistema.cargarBaseDeDatos(archivoBin);
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