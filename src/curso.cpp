#include "curso.h"

Curso::Curso(){ 
}
Curso::~Curso(){ 
}
void Curso::setNombreCurso(const std::string& nombreCurso){
    this->nombreCurso = nombreCurso;
}
std::string Curso::getNombreCurso() const {
    return nombreCurso;
}
void Curso::setCodigoCurso(const std::string& codigoCurso){
    this->codigoCurso = codigoCurso;
}
std::string Curso::getCodigoCurso() const {
    return codigoCurso;
}
void Curso::setCreditos(int creditos){
    this->creditos = creditos;
}
int Curso::getCreditos() const {
    return creditos;
}
void Curso::setNotaParcial(float notaParcial){
    this->notaParcial = notaParcial;
}
float Curso::getNotaParcial() const {
    return notaParcial;
}
