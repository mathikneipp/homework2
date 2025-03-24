#include "Estudiante.h"
#include "Curso.h"

#include <iostream>
#include <vector>
#include <algorithm>


// Constructor
Curso::Curso() {
    lista_estudiantes = {};
}

Curso::Curso(std::vector<std::shared_ptr<Estudiante>> lista_estudiantes_param) {
    lista_estudiantes = lista_estudiantes_param;
}

/* Deep copy
 * Recorro la lista del otro curso y voy creando nuevos smart pointers de los estudiantes e inscribiendo en el nuevo curso.
 */ 
Curso::Curso(const Curso& otro) {
    for (int i = 0; i < otro.lista_estudiantes.size(); i++) {
        // Crear un nuevo Estudiante con un smart pointer
        inscribir_estudiante(std::make_shared<Estudiante>(*otro.lista_estudiantes[i]));
    }
}

// Setter's
// Inscribe un nuevo estudiante al curso.
void Curso::inscribir_estudiante(const std::shared_ptr<Estudiante>& estudiante_nuevo) {
    if (is_inscripto(estudiante_nuevo->get_legajo())) throw std::runtime_error("El estudiante ya esta inscripto.");
    if (is_lleno()) throw std::runtime_error("El curso se encuentra lleno.");
    lista_estudiantes.push_back(estudiante_nuevo);
}

// Desinscribe un estudiante del curso.
void Curso::desinscribir_estudiante(const std::shared_ptr<Estudiante>& estudiante_a_sacar) {
    if (is_vacio()) throw std::runtime_error("El curso se encuentra vacio.");
    if (is_inscripto(estudiante_a_sacar->get_legajo()) == false) throw std::runtime_error("El estudiante no esta inscripto.");
    for (int i = 0; i < lista_estudiantes.size(); i++) {
        if (lista_estudiantes[i]->get_legajo() == estudiante_a_sacar->get_legajo()) {
            lista_estudiantes.erase(lista_estudiantes.begin() + i);
        }
    }
}

// Getter's
// Verifica por legajo si existe tal estudiante en el curso.
bool Curso::is_inscripto(const int legajo) {
    for (int i = 0; i < lista_estudiantes.size(); i++) {
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
    std::sort(lista_estudiantes.begin(), lista_estudiantes.end());
    for (int i = 0; i < lista_estudiantes.size(); i++) {
        std::cout << lista_estudiantes[i];
    }
}
