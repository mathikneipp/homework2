#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <utility>  // Para std::pair

class Estudiante {
    private:
        std::string nombre_completo;
        const int legajo;
        std::vector<std::pair<std::string, float>> notas;
    public:
        // Constructores
        Estudiante(std::string _nombre_completo, const int _legajo);
        Estudiante(std::string _nombre_completo, const int _legajo, std::vector<std::pair<std::string, float>> _notas);

        // Getter's
        std::string get_nombre() const ;
        int get_legajo() const;
        std::vector<std::pair<std::string, float>> get_notas() const ;
        float get_promedio() const ;

        // Setter's
        void agregar_nota(std::string curso, const float nota_nueva);

        // Operadores
        bool operator<(const Estudiante& otro) const;
        friend std::ostream& operator<<(std::ostream& os, const Estudiante& p);
};
