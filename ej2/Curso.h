#pragma once

#include "Estudiante.h"

#include <iostream>
#include <vector>
#include <memory>

class Curso {
private:
    std::vector<std::unique_ptr<Estudiante>> lista_estudiantes;
    std::string nombre;
public:
    // Constructor
    Curso(std::string _nombre);
    Curso(std::string _nombre, std::vector<std::unique_ptr<Estudiante>> _lista_estudiantes);

    // Constructor de copia
    Curso(const Curso& otro);

    // Setter's
    // Inscribe un nuevo estudiante al curso.
    void inscribir_estudiante(const std::unique_ptr<Estudiante>& estudiante_nuevo);
    // Desinscribe un estudiante del curso.
    void desinscribir_estudiante(const std::unique_ptr<Estudiante>& estudiante_a_sacar);
    
    // Getter's
    // Verifica por legajo si existe tal estudiante en el curso.
    std::string get_nombre();
    bool is_inscripto(const int legajo);
    // Indica si el curso está completo o no, teniendo en cuenta que el curso tiene una capacidad de 20 alumnos.
    bool is_lleno();
    // Indica si el curso esta vacio.
    bool is_vacio();
    // Imprime la lista de estudiantes en orden alfabético.
    void print_lista_estudiantes();
};
