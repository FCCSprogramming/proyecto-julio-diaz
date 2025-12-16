#ifndef CURSO_H
#define CURSO_H
#include <string>
#include "estudiante.h"


class Curso {
private:
   std:: string nombreCurso;
   std:: string codigoCurso;
   int creditos;
   int cantEstudiantes;
   Estudiante* estudiantes= new Estudiante[cantEstudiantes];//cada curso va a tener un arreglo dinamico de estudiantes con una cantidad igual a cantEstudiantes
   float* notaParcial= new float[cantEstudiantes];//arreglo dinamico de notas parciales,una por cada estudiante inscrito respectivamente
public:
   Estudiante* ptr3 = estudiantes;
   Estudiante* ptr4 = estudiantes;
   Curso();
   ~Curso();
   void setNombreCurso(const std::string&);
   std::string getNombreCurso() const;
   void setCodigoCurso(const std::string&);
   std::string getCodigoCurso() const;
   void setCreditos(int);
   int getCreditos() const;
   void setCantEstudiantes(int);
   int getCantEstudiantes() const;
   Estudiante* getEstudiantes(Estudiante &estudiantes) const;
   void setNotaParcial(float &);
   float* getNotaParcial() const;    
};



#endif