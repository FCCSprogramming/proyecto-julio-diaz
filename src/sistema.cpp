#include "sistema.h"
#include "estudiante.h"
#include "curso.h"
#include <iostream>
#include <fstream>


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
void Sistema::registrarCurso(Curso* cursos,Curso* ptr1){//se usara el puntero de clase Curso ptrCursos creado en el main para ir registrando los cursos en el arreglo dinamico cursos
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
    cout<<"Curso "<<nombreCurso1<<" registrado exitosamente."<<endl;
    ptr1++;
}
void Sistema::inscribirCurso(Curso* curso,const int numCursos){
    ptr2 = estudiantes;//reiniciamos el puntero ptr2 al inicio del arreglo de estudiantes
    std::string nombreEstudiante,nombreCursoInscribir;
    cout<<"Estudiante a inscribir en curso: ";
    cin>>nombreEstudiante;
    for(int i=0;i<Sistema::getNumEstudiantes();i++){
        if((ptr2)->getNombre()==nombreEstudiante){//se busca al estudiante en el sistema 
            cout<<"Curso a inscribir: ";
            cin>>nombreCursoInscribir;
            for(int j=0;j<numCursos;j++){
                if((curso+j)->getNombreCurso()==nombreCursoInscribir){//se busca el curso en cursos
                    (curso+j)->ptr3[j]=*(ptr2);//se iguala el nombre del estudiante que se encuentra en la clase sistema al atributo de la clase curso
                    cout<<"Estudiante "<<nombreEstudiante<<" inscrito en el curso "<<nombreCursoInscribir<<endl;
                    (curso+j)->ptr3++;//se avanza el puntero ptr3 al siguiente espacio del arreglo dinamico de estudiantes del curso
                }else{
                    cout<<"Curso no encontrado."<<endl;
                }
            }
          
        }
    ptr2++;       
    }
}
void Sistema::registrarNotaParcial(Curso* curso){
    float* notaParcial = new float[curso->getCantEstudiantes()];
    curso->ptr4 = estudiantes;// se usa otro puntero ptr4 para recorrer el arreglo dinamico de estudiantes del curso
    std::string nombreEstudiante;
    cout<<"Estudiante a registrar nota: "<<endl;
    cin>>nombreEstudiante;
    for(int i=0;i<Sistema::getNumEstudiantes();i++){
        if(curso->ptr4->getNombre()==nombreEstudiante){
            float nota;
            cout<<"Ingrese la nota parcial: ";
            cin>>nota;
            notaParcial[i]=nota;
            curso->setNotaParcial(notaParcial[i]);//registra la nota parcial en el arreglo dinamico de notas parciales del curso
            cout<<"Nota registrada exitosamente."<<endl;
        }
        
    }

}
void Sistema::calcularPromedio_generarReporte(Sistema sistema,Curso* curso,Curso* ptrCurso,int numCursos){
    ptr2= estudiantes;//reiniciamos el puntero ptr2 al inicio del arreglo dinamico de estudiantes
    for(int i=0;i<sistema.getNumEstudiantes();i++){//por cada estudiantes se busca sus notas en los cursos inscritos
        float sumaNotas=0;
        for(int j=0;j<numCursos;j++){
            for(int k=0;k<(ptrCurso+j)->getCantEstudiantes();k++){
                if(ptr2->getNombre()==(ptrCurso+j)->ptr3[k].getNombre()){
                    sumaNotas += *((ptrCurso+j)->getNotaParcial()+k);//se va sumando las notas parciales encontradas para luego promediarlas
                }
            }
        }
        float promedio = sumaNotas/ptr2->getCantCursos();
        cout<<"Estudiante: "<<ptr2->getNombre()<<" - Promedio: "<<promedio<<endl;
        ptr2++;
    }
}
void Sistema::almacenarDatosEstudiantesAprobados(Sistema sistema,Curso* curso,Curso* ptrCurso,int numCursos,fstream& archivo){
    ptr2= estudiantes;
    for(int i=0;i<sistema.getNumEstudiantes();i++){
        float sumaNotas=0;
        for(int j=0;j<numCursos;j++){
            for(int k=0;k<(ptrCurso+j)->getCantEstudiantes();k++){
                if(ptr2->getNombre()==(ptrCurso+j)->ptr3[k].getNombre()){
                    sumaNotas += *((ptrCurso+j)->getNotaParcial()+k);
                }
            }
        }//se copia la misma logica de calculo de promedio para reutilizarla y asi leer solo los estudiantes aprobados al archivo
        float promedio = sumaNotas/ptr2->getCantCursos();
        archivo.open("C:\\Users\\Personal\\Documents\\GitHub\\proyecto-julio-diaz\\estudiantes aprobados.txt",ios::out|ios::app);
        if(!archivo){
            cout<<"Error al abrir el archivo."<<endl;
            return;
        }
        if(promedio>=10){
            archivo<<"Estudiante: "<<ptr2->getNombre()<<" - Promedio: "<<promedio<<endl;
        }
        archivo.close();
        ptr2++;
    }

}
void Sistema::guardarBaseDeDatos(Curso* curso,Curso* ptrCurso,int numCursos,fstream& archivoBin){
    archivoBin.open("C:\\Users\\Personal\\Documents\\GitHub\\proyecto-julio-diaz\\base de datos.bin",ios::out|ios::binary);
    if(!archivoBin){
        cout<<"Error al abrir el archivo binario."<<endl;
        return;
    }
    for(int i=0;i<numCursos;i++){
        std::string nombreCurso = (ptrCurso+i)->getNombreCurso();
        std::string codigoCurso = (ptrCurso+i)->getCodigoCurso();
        int creditos = (ptrCurso+i)->getCreditos();
        int cantEstudiantes = (ptrCurso+i)->getCantEstudiantes();
        archivoBin.write(reinterpret_cast<const char*>(&nombreCurso),sizeof(nombreCurso));
        archivoBin.write(reinterpret_cast<const char*>(&codigoCurso),sizeof(codigoCurso));
        archivoBin.write(reinterpret_cast<const char*>(&creditos),sizeof(creditos));
        archivoBin.write(reinterpret_cast<const char*>(&cantEstudiantes),sizeof(cantEstudiantes));
        for(int j=0;j<cantEstudiantes;j++){
            Estudiante estudiante = (ptrCurso+i)->ptr3[j];
            archivoBin.write(reinterpret_cast<const char*>(&estudiante),sizeof(Estudiante));
            float notaParcial = *((ptrCurso+i)->getNotaParcial()+j);
            archivoBin.write(reinterpret_cast<const char*>(&notaParcial),sizeof(notaParcial));
        }
    }
    archivoBin.close();
     
}
void Sistema::cargarBaseDeDatos(fstream& archivoBin){
    archivoBin.open("C:\\Users\\Personal\\Documents\\GitHub\\proyecto-julio-diaz\\base de datos.bin",ios::in|ios::binary);
    if(!archivoBin){
        cout<<"Error al abrir el archivo binario."<<endl;
        return;
    }
    while(!archivoBin.eof()){
        std::string nombreCurso;
        std::string codigoCurso;
        int creditos;
        int cantEstudiantes;
        archivoBin.read(reinterpret_cast<char*>(&nombreCurso),sizeof(nombreCurso));
        archivoBin.read(reinterpret_cast<char*>(&codigoCurso),sizeof(codigoCurso));
        archivoBin.read(reinterpret_cast<char*>(&creditos),sizeof(creditos));
        archivoBin.read(reinterpret_cast<char*>(&cantEstudiantes),sizeof(cantEstudiantes));
        cout<<"Curso: "<<nombreCurso<<", Codigo: "<<codigoCurso<<", Creditos: "<<creditos<<", Cantidad de Estudiantes: "<<cantEstudiantes<<endl;
        for(int j=0;j<cantEstudiantes;j++){
            Estudiante estudiante;
            archivoBin.read(reinterpret_cast<char*>(&estudiante),sizeof(Estudiante));
            float notaParcial;
            archivoBin.read(reinterpret_cast<char*>(&notaParcial),sizeof(notaParcial));
            cout<<"Estudiante: "<<estudiante.getNombre()<<", Nota Parcial: "<<notaParcial<<endl;
        }
    }
    archivoBin.close();
}
void Sistema::accesoDirectoRegistros(fstream& archivoBin){
    archivoBin.open("C:\\Users\\Personal\\Documents\\GitHub\\proyecto-julio-diaz\\base de datos.bin",ios::in|ios::binary);
    if(!archivoBin){
        cout<<"Error al abrir el archivo binario."<<endl;
        return;
    }
    for(int i=0;i<getNumEstudiantes();i++){
        archivoBin.seekg(i*sizeof(Estudiante), ios::beg);
        Estudiante estudiante;
        archivoBin.read(reinterpret_cast<char*>(&estudiante),sizeof(Estudiante));
        cout<<"Estudiante "<<i+1<<": "<<estudiante.getNombre()<<", Codigo: "<<estudiante.getCodigo()<<endl;
    }
    
}