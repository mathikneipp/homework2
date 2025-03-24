#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Estudiante {
    private:
        std::string nombre_completo;
        const int legajo;
        std::vector<float> notas;
    public:
        // Constructores
        Estudiante(std::string nombre_completo_param, const int legajo_param);
        Estudiante(std::string nombre_completo_param, const int legajo_param, std::vector<float> notas_param);

        // Getter's
        std::string get_nombre();
        const int get_legajo();
        std::vector<float> get_notas();
        float get_promedio();

        // Setter's
        void agregar_nota(float nota_nueva);

        // Operadores
        bool operator<(Estudiante otro);
        friend std::ostream& operator<<(std::ostream& os, Estudiante& p);

};
