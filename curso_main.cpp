#include "Estudiante.h"
#include "Curso.h"

#include <iostream>
#include <vector>
#include <memory>
#include <utility>

/*
 * Tienen una relacion de asociacion, ya que ninguno tiene ownership sobre el otro, y trabajan juntos.
 */

int elegir_cursos(std::vector<std::unique_ptr<Curso>> cursos) {
    if (cursos.size() == 0) {
        std::cout << "No hay cursos disponibles." << std::endl;
        return -1;
    }
    int pos = 1;
    std::cout << "\nCursos: ";
    for (const auto& i : cursos) { // Imprimo todos los cursos que hay.
        std::cout << "\n" << pos << ". Clase: " << i->get_nombre();
        pos++;
    }
    std::cout << "\nEleccion: ";
    std::cin >> pos;
    if (std::cin.fail()) { // Caso de ingresar cualquier otra cosa.
        throw std::runtime_error("Entrada inválida.");
    }

    return pos - 1; // Devuelvo la posicion del unique pointer.
}

int elegir_estudiante(std::vector<std::unique_ptr<Estudiante>> estudiantes) {
    if (estudiantes.size() == 0) {
        std::cout << "No hay cursos disponibles." << std::endl;
        return -1;
    }
    
    int pos = 1;
    std::cout << "\nEstudiantes:";
    for (const auto& i : estudiantes) { // Imprimo todos los estudiantes que hay.
        std::cout << "\n" << pos << ". Nombre: " << i->get_nombre() << ". Legajo: " << i->get_legajo();
        pos++;
    }

    std::cout << "\nEleccion: ";
    std::cin >> pos;

    if (std::cin.fail()) { // Caso de ingresar cualquier otra cosa.
        throw std::runtime_error("Entrada inválida.");
    }
    return pos-1; // Devuelvo la posicion del unique pointer.
}

int main() {
    std::vector<std::unique_ptr<Estudiante>> estudiantes;
    std::vector<std::unique_ptr<Curso>> cursos;
    std::string _nombre;
    int _legajo, pos_curso_seleccionado, pos_estudiante_seleccionado;
    bool run = true;
    int opcion, pos, error = 0;
    while (run == true) {
        while (opcion < 1 || opcion > 8) {
            std::cout << "\nMenú Principal:\n"
                    << "1. Crear estudiante.\n"
                    << "2. Crear curso.\n"
                    << "3. Inscribir estudiante a un curso.\n"
                    << "4. Desinscribir estudiante del curso.\n"
                    << "5. Buscar estudiante en un curso por legajo.\n"
                    << "6. Mostrar lista de estudiantes ordenada.\n"
                    << "7. Copiar curso.\n"
                    << "8. Salir.\n"
                    << "Seleccionar opcion: ";
            std::cin >> opcion;
        }
        switch (opcion) {
            case 1:
                std::cout << "\nNombre: ";
                std::cin >> std::ws; // Elimina los whitespaces del buffer
                std::getline(std::cin, _nombre);
                std::cout << "\nLegajo: ";
                std::cin >> _legajo;
                if (std::cin.fail()) { // Caso de que se ingrese otra cosa a la pedida.
                    throw std::runtime_error("Entrada inválida");
                }

                for (const auto& i : estudiantes) {
                    if (i->get_legajo() == _legajo) {
                        std::cout << "El legajo ya existe." << std::endl;
                        error = 1; // En caso de que exista un estudiante con ese legajo
                    }
                }
                if (error == 0) estudiantes.push_back(std::make_unique<Estudiante>(_nombre, _legajo)); // Agrego el estudiante creado al vector de estudiantes.
                break;

            case 2:
                std::cout << "\nNombre: ";
                std::cin >> std::ws; // Elimina los whitespaces del buffer
                std::getline(std::cin, _nombre);
                if (std::cin.fail()) { // Caso de que se ingrese otra cosa a la pedida.
                    throw std::runtime_error("Entrada inválida");
                }

                cursos.push_back(std::make_unique<Curso>(_nombre)); // Agrego el curso creado al vector de cursos.
                break;

            case 3:
                pos_curso_seleccionado = elegir_cursos(cursos); // Elijo el curso
                if (pos_curso_seleccionado == -1) {
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }

                pos_estudiante_seleccionado = elegir_estudiante(estudiantes); // Elijo el estudiante
                if (pos_estudiante_seleccionado == -1) {
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }

                try {
                    cursos.at(pos_curso_seleccionado)->inscribir_estudiante(estudiantes.at(pos_estudiante_seleccionado)); // Inscribe el estudiante
                } catch (const std::runtime_error& e) {
                    std::cout << "\n[ERROR]: " << e.what() << std::endl; // Caso que no haya podido inscribirlo
                }
                break;

            case 4:
                pos_curso_seleccionado = elegir_cursos(cursos); // Elijo el curso
                if (pos_curso_seleccionado == -1) {
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }
                pos_estudiante_seleccionado = elegir_estudiante(estudiantes); // Elijo el estudiante
                if (pos_estudiante_seleccionado == -1) {
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }

                try {
                    cursos.at(pos_curso_seleccionado)->desinscribir_estudiante(estudiantes.at(pos_estudiante_seleccionado)); // Desinscribe el estudiante
                } catch (const std::runtime_error& e) {
                    std::cout << "\n[ERROR]: " << e.what() << std::endl; // Caso que no haya podido desinscribirlo
                }
                break;

            case 5:
                pos_curso_seleccionado = elegir_cursos(cursos); // Elijo el curso
                if (pos_curso_seleccionado == -1) {
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }

                std::cout << "\nLegajo: ";
                std::cin >> _legajo;
                if (std::cin.fail()) { // Caso de que se ingrese otra cosa a la pedida.
                    throw std::runtime_error("Entrada inválida");
                }

                if (cursos.at(pos_curso_seleccionado)->is_inscripto(_legajo)) std::cout << "El estudiante se encuentra inscripto.";
                else std::cout << "El estudiante no se encuentra inscripto." << std::endl;
                break;

            case 6:
                pos_curso_seleccionado = elegir_cursos(cursos); // Elijo el curso
                if (pos_curso_seleccionado == -1) {
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }
                std::cout << std::endl;
                cursos.at(pos_curso_seleccionado)->print_lista_estudiantes();
                break;

            case 7:
                pos_curso_seleccionado = elegir_cursos(cursos);
                if (pos_curso_seleccionado == -1) {
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }

                cursos.push_back(std::make_unique<Curso>(*cursos.at(pos_curso_seleccionado))); // Copio el curso y lo agrego al final del vector de cursos
                pos = 1;
                std::cout << "\nNueva lista de cursos:";
                for (const auto& i : cursos) { // Imprimo todos los cursos que hay
                    std::cout << "\n" << pos << ". Clase: " << i->get_nombre();
                    pos++;
                }
                break;

            case 8:
                run = false;
                break;
        }
        opcion = 0;
    }
    return 0;
}
