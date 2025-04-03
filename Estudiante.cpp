#include "Estudiante.h"

#include <iostream>
#include <vector>

// Constructor
Estudiante::Estudiante(std::string _nombre_completo, const int _legajo) : legajo(_legajo){
    nombre_completo = _nombre_completo;
    notas = {};
}

Estudiante::Estudiante(std::string _nombre_completo, const int _legajo, std::vector<std::pair<std::string, float>> _notas) : legajo(_legajo){
    nombre_completo = _nombre_completo;
    notas = _notas;
}

// Getter's
std::string Estudiante::get_nombre() const {
    return nombre_completo;
}

int Estudiante::get_legajo() const {
    return legajo;
}

std::vector<std::pair<std::string, float>> Estudiante::get_notas() const {
    return notas;
}

float Estudiante::get_promedio() const {
    float suma = 0.0;
    if (notas.empty()) return suma;
    for (size_t i = 0; i < notas.size(); i++) {
        suma += notas[i].second; 
    }
    return (suma/notas.size());
}

// Setter's
void Estudiante::agregar_nota(std::string curso, const float nota_nueva) {
    notas.push_back({curso, nota_nueva});
}

// Operadores
// Compara dos nombres alfabeticamente.
bool Estudiante::operator<(const Estudiante& otro) const {
    return nombre_completo < otro.nombre_completo;
}

// Imprime el nombre de un estudiante con formato "Nombre: <Nombre>"
std::ostream& operator<<(std::ostream& os, const Estudiante& e) {
    os << "Nombre: " << e.get_nombre() << std::endl;
    return os;
}
