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
   Estudiante* estudiantes= new Estudiante[cantEstudiantes];
   float* notaParcial= new float[cantEstudiantes];
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
   void setNotaParcial(float* &);
   float* getNotaParcial() const;    
};



#endif