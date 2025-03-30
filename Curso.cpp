#include "Estudiante.h"
#include "Curso.h"

#include <iostream>
#include <vector>
#include <algorithm>


// Constructor
Curso::Curso(std::string _nombre) {
    nombre = _nombre;
    lista_estudiantes = {};
}

Curso::Curso(std::string _nombre, std::vector<std::unique_ptr<Estudiante>> _lista_estudiantes) {
    nombre = _nombre;
    lista_estudiantes = _lista_estudiantes;
}

/* Shallow copy
 * Hago shallow copy, porque los cursos no poseen a los estudiantes.
 */ 
Curso::Curso(const Curso& otro) : lista_estudiantes(otro.lista_estudiantes), nombre(otro.nombre) {}

// Setter's
// Inscribe un nuevo estudiante al curso.
void Curso::inscribir_estudiante(const std::unique_ptr<Estudiante>& estudiante_nuevo) {
    if (is_inscripto(estudiante_nuevo->get_legajo())) throw std::runtime_error("El estudiante ya esta inscripto.");
    if (is_lleno()) throw std::runtime_error("El curso se encuentra lleno.");
    lista_estudiantes.push_back(estudiante_nuevo);
}

// Desinscribe un estudiante del curso.
void Curso::desinscribir_estudiante(const std::unique_ptr<Estudiante>& estudiante_a_sacar) {
    if (is_vacio()) throw std::runtime_error("El curso se encuentra vacio.");
    if (is_inscripto(estudiante_a_sacar->get_legajo()) == false) throw std::runtime_error("El estudiante no esta inscripto.");
    for (size_t i = 0; i < lista_estudiantes.size(); i++) {
        if (lista_estudiantes[i]->get_legajo() == estudiante_a_sacar->get_legajo()) {
            lista_estudiantes.erase(lista_estudiantes.begin() + i);
        }
    }
}

// Getter's

std::string Curso::get_nombre() {
    return nombre;
}

// Verifica por legajo si existe tal estudiante en el curso.
bool Curso::is_inscripto(const int legajo) {
    for (size_t i = 0; i < lista_estudiantes.size(); i++) {
        if (lista_estudiantes[i]->get_legajo() == legajo) return true; // En caso de que encuentre en el curso el legajo que buscamos.
    }
    return false; // Caso contrario
}

// Indicar si el curso está completo o no, teniendo en cuenta que el curso tiene una capacidad de 20 alumnos.
bool Curso::is_lleno() {
    return lista_estudiantes.size() >= 20; // Devuelve true si hay 20 personas o mas anotadas al curso. Y false caso contrario.
}

bool Curso::is_vacio() {
    return lista_estudiantes.empty(); // Devuelve true si el curso esta vacio, false caso contrario.
}

// Imprime la lista de estudiantes en orden alfabético.
void Curso::print_lista_estudiantes() {
    std::sort(lista_estudiantes.begin(), lista_estudiantes.end(), 
        [](const std::unique_ptr<Estudiante>& a, const std::unique_ptr<Estudiante>& b) { // Para usar los objetos y no los punteros.
            return *a < *b; // Uso el comparador <
        }); 
    for (const auto& estudiante : lista_estudiantes) {
        std::cout << *estudiante;
    }
}
