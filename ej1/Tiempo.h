#pragma once

#include <iostream>

class Tiempo {
private:
    int horas;
    int minutos;
    int segundos;
    std::string periodo;

public:
    // Constructores
    Tiempo();
    Tiempo(int horas_param);
    Tiempo(int horas_param, int minutos_param);
    Tiempo(int horas_param, int minutos_param, int segundos_param);
    Tiempo(int horas_param, int minutos_param, int segundos_param, std::string periodo_param);

    // Setter's
    void set_hora(int nueva_hora);
    void set_minutos(int nuevos_minutos);
    void set_segundos(int nuevos_segundos);
    void set_periodo(std::string nuevo_periodo);

    // Print's
    void print_hora(bool hs24 = false);
    void print_minutos();
    void print_segundos();
    void print_periodo();
    void print_tiempo(bool hs24 = false);
};
    