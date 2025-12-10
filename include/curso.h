#ifndef CURSO_H
#define CURSO_H
#include <string>


class Curso {
private:
   std:: string nombreCurso;
   std:: string codigoCurso;
   int creditos;
   float notaParcial;
public:
   Curso();
   ~Curso();
   void setNombreCurso(const std::string&);
   std::string getNombreCurso() const;
   void setCodigoCurso(const std::string&);
   std::string getCodigoCurso() const;
   void setCreditos(int);
   int getCreditos() const;
   void setNotaParcial(float);
   float getNotaParcial() const;    
};



#endif