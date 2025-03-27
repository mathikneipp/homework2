#include "Estudiante.h"

#include <iostream>
#include <vector>

// Constructor
Estudiante::Estudiante(std::string nombre_completo_param, const int legajo_param): legajo(legajo_param){
    nombre_completo = nombre_completo_param;
    notas = {};
}

Estudiante::Estudiante(std::string nombre_completo_param, const int legajo_param, std::vector<std::pair<std::string, int>> notas_param): legajo(legajo_param){
    nombre_completo = nombre_completo_param;
    notas = notas_param;
}

// Getter's
std::string Estudiante::get_nombre() {
    return nombre_completo;
}

const int Estudiante::get_legajo() {
    return legajo;
}

std::vector<std::pair<std::string, int>> Estudiante::get_notas() {
    return notas;
}

float Estudiante::get_promedio() {
    float suma = 0.0;
    if (notas.empty()) return suma;
    for (int i = 0; i < notas.size(); i++) {
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
bool Estudiante::operator<(Estudiante otro) {
    return get_nombre() < otro.get_nombre();
}
// Imprime el nombre de un estudiante con formato "Nombre: <Nombre>"
std::ostream& operator<<(std::ostream& os, Estudiante& e) {
    os << "Nombre: " << e.get_nombre() << std::endl;
    return os;
}
